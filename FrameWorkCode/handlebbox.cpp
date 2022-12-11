#include "handlebbox.h"

//#include <QFile>
//#include <QTextCursor>
//#include <QTextStream>
//#include <QRegularExpression>
#include <QTextDocument>
//#include <QDebug>
//#include <QTextBlock>

/*!
 * \brief HandleBbox::HandleBbox
 */
HandleBbox::HandleBbox()
{
    this->doc = new QTextDocument();
    this->docIsPassed = true;
}
/*!
 * \brief HandleBbox::HandleBbox
 * \param doc
 */
HandleBbox::HandleBbox(QTextDocument* doc)
{
    this->doc = doc;
    this->docIsPassed = false;
}
/*!
 * \brief HandleBbox::~HandleBbox
 */
HandleBbox::~HandleBbox()
{
    if (docIsPassed) {
        delete doc;
    }
}
/*!
 * \brief HandleBbox::loadFileInDoc
 * \param f
 * function:
 * input file is read
 * paragraph,image and table,list tags are iterated
 * the text is set as blocks.
 * alignments are set if they are present in <p>,<img/> or <table> tags(set asblock formats)
 * input text is insert as html inside block.
 */
QTextDocument *HandleBbox::loadFileInDoc(QFile *f)
{
    QTextCursor cur(doc);QTextCursor cur2(doc);
    if (!f->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file";
        return nullptr;
    }
    QString line;
    int flag_ = 0, nestedListCount = 0;
    QString inputText = "";
    while(!f->atEnd()) {
        line = f->readLine();
        line = line.simplified();
        QStringList l = line.split(" ");
        for(int i = 0; i < l.size(); i++) {
            //for parsing p tags
            if((l[i].contains("<p") && flag_ != 2) || flag_ == 1){
                flag_ = 1;
                while(i < l.size() && !l[i].contains("</p>")){
                    inputText += l[i];
                    inputText += " ";
                    i++;
                }
                if(i == l.size())
                    i = i - 1;
                if(l[i].contains("</p>")){
                    flag_ = 0;
                    inputText += l[i];
                    inputText += " ";
                    inputText = latex2png(inputText);
                    if(inputText.contains("align=\"right\"")){
                        blockFormat.setAlignment(Qt::AlignRight);
                    }
                    else if(inputText.contains("align=\"center\"")){
                        blockFormat.setAlignment(Qt::AlignCenter);
                    }
                    else if(inputText.contains("align=\"justify\"")){
                        blockFormat.setAlignment(Qt::AlignJustify);
                    }
                    else if(!inputText.contains("align=\"center\"") && !inputText.contains("align=\"right\"") ){
                        blockFormat.setAlignment(Qt::AlignLeft);
                    }
                    cur.insertBlock();
                    cur.insertHtml(inputText);
                    cur.setBlockFormat(blockFormat);
                    inputText = "";
                }
            }
            //for parsing table tags
            else if(l[i].contains("<table") || flag_ == 2){
                flag_ = 2;
                while(i < l.size() && !l[i].contains("</table>")){
                    inputText += l[i];
                    inputText += " ";
                    i++;
                }
                if(i == l.size())
                    i = i - 1;
                if(l[i].contains("</table>")){
                    flag_ = 0;
                    inputText += l[i];
                    inputText += " ";
                    inputText = latex2png(inputText);
                    if(inputText.contains("align=\"right\"")){
                        blockFormat.setAlignment(Qt::AlignRight);
                    }
                    else if(inputText.contains("align=\"center\"")){
                        blockFormat.setAlignment(Qt::AlignCenter);
                    }
                    else if(inputText.contains("align=\"justify\"")){
                        blockFormat.setAlignment(Qt::AlignJustify);
                    }
                    else if(!inputText.contains("align=\"center\"") && !inputText.contains("align=\"right\"") ){
                        blockFormat.setAlignment(Qt::AlignLeft);
                    }
                    cur.insertBlock();
                    cur.insertHtml(inputText);
                    cur.setBlockFormat(blockFormat);
                    inputText = "";
                }

            }

            //for parsing image tags
            else if(l[i].contains("<img") || flag_ == 3){
                flag_ = 3;
                while(i < l.size() && !l[i].contains(">")){
                    inputText += l[i];
                    inputText += " ";
                    i++;
                }
                if(i == l.size())
                    i = i - 1;
                if(l[i].contains(">")){
                    flag_ = 0;
                    inputText += l[i];
                    inputText += " ";
                    cur.insertBlock();
                    cur.insertHtml(inputText);
                    inputText = "";
                }

            }

            //!for parsing unordered list
            //! Checking for ul tag and waiting till its closing tag is found.
            //! There can be a nested list - for that nestedListCount varaible is helpful.
            //! When new list is inserted in a document, Qt inserts an empty block at strat - Qt bug.
            //! For removing that empty block, we are finding the block count before inserting the list then deleting the block by block number found before inserting the list.
            else if((l[i].contains("<ul") && flag_ != 1 && flag_ != 2 && flag_ != 3 && flag_ != 6) || flag_ == 5){
                flag_ = 5;
                if(l[i].contains("<ul")) nestedListCount += 1;  //! If opening tag of list is seen, nestedListCount is incremented to keep track of opening list tags seen in a list
                while(i < l.size() && !l[i].contains("</ul>")){
                    inputText += l[i];
                    inputText += " ";
                    i++;
                }
                if(i == l.size())
                    i = i - 1;
                if(l[i].contains("</ul>"))
                {
                    nestedListCount -= 1;       //! If closing tag of list is seen, nestedListCount is decremented. When this varaible reaches zero, the list has ended.
                    inputText += l[i];
                    inputText += " ";
                }
                if(l[i].contains("</ul>") && nestedListCount < 1){
                    flag_ = 0;
                    inputText = latex2png(inputText);
                    int num = doc->blockCount();
                    cur.insertBlock();
                    cur.insertHtml(inputText);
                    cur2 = QTextCursor(doc->findBlockByNumber(num));
                    cur2.select(QTextCursor::BlockUnderCursor);
                    cur2.deleteChar();
                    inputText = "";
                }
            }

            //for parsing ordered list
            else if((l[i].contains("<ol") && flag_ != 1 && flag_ != 2 && flag_ != 3 && flag_ !=5 ) || flag_ == 6){
                flag_ = 6;
                if(l[i].contains("<ol")) nestedListCount += 1;
                while(i < l.size() && !l[i].contains("</ol>")){
                    inputText += l[i];
                    inputText += " ";
                    i++;
                }
                if(i == l.size())
                    i = i - 1;
                if(l[i].contains("</ol>"))
                {
                    nestedListCount -= 1;
                    inputText += l[i];
                    inputText += " ";
                }
                if(l[i].contains("</ol>") && nestedListCount < 1){
                    flag_ = 0;
                    inputText = latex2png(inputText);
                    int num = doc->blockCount();
                    cur.insertBlock();
                    cur.insertHtml(inputText);
                    cur2 = QTextCursor(doc->findBlockByNumber(num));
                    cur2.select(QTextCursor::BlockUnderCursor);
                    cur2.deleteChar();
                    inputText = "";
                }
            }

        }
        if(flag_ == 1 || flag_ == 2) {
            inputText += "\n";
        }
    }

    cur = QTextCursor(doc->findBlockByNumber(0));
    cur.select(QTextCursor::BlockUnderCursor);
    cur.deleteChar();
    f->close();

    storeBboxes(f);
    return doc;
}
/*!
 * \brief HandleBbox::insertBboxes
 * \param file
 * inserts the boxes into the file
 * if file is not available for writing mode,function terminates
 * all the lines of file are read and stored in varaible(input)
 * If bbox is already present, move to next entry
 * tages for table, image are added
 * are successfull insertion the file is flushed and closed
 */
void HandleBbox::insertBboxes(QFile *file)
{
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing";
        return;
    }
    QString input = file->readAll();
    file->close();
    QRegularExpression regex_p("(<p[^>]*>|</p>|<img[^>]*>|<table[^>]*>|<td[^>]*>|</table>)");
    QRegularExpressionMatchIterator itr = regex_p.globalMatch(input);

    int i = 0;
    bool inTable = false;
    bool inPara = false;
    int increment = 0;
    QString currentTag;
    while (itr.hasNext() && i < bboxes.size()) {
        QRegularExpressionMatch match = itr.next();
        QString htmlTagData = match.captured(1);
        int end = match.capturedEnd(1);


        if (htmlTagData.indexOf("title=\"bbox") != -1) {
            i++;
            continue;
        }

        if (htmlTagData.left(6) == "<table") {
            inTable = true;
            currentTag = "table";
        } else if (htmlTagData.left(7) == "</table") {
            inTable = false;
            currentTag = "/table";
            continue;
        } else if (htmlTagData.left(4) == "<img") {
            if (inPara) {
                i--;
            }
            currentTag = "img";
        } else if (htmlTagData.left(3) == "<td") {
            currentTag = "td";
        } else if (htmlTagData.left(2) == "<p") {
            if (inTable) {
                continue;
            }
            currentTag = "p";
            inPara = true;
        } else if (htmlTagData.left(3) == "</p") {
            inPara = false;
            continue;
        }

        if (bboxes[i].first != currentTag) {
            qDebug() << "tags not matching at " << i;
        }
        QString temp = " title=\"" + bboxes[i++].second + "\"";
        increment += temp.length();

        if (currentTag == "img") {
            input.insert(end - 2, temp);
        } else {
            input.insert(end - 1, temp);
        }

        itr = regex_p.globalMatch(input, end + 1);
    }

    if (!file->open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file for writing";
        return;
    }

    QTextStream out(file);
    out.setCodec("utf-8");
    out << input;
    out.flush();
    file->close();
}
/*!
 * \brief HandleBbox::storeBboxes
 * \param file
 * the boxes are stored
 * Function terminates if file is available for writing mode
 * text of the input file is read
 * If bbox tag is not present,tags(variable) are set to null
 * loop itreates through the input file
 * several tags are check and stored inside bBox accordingly
 */
void HandleBbox::storeBboxes(QFile *file)
{
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream st(file);
    QString initial = st.readAll();
    file->close();
    bboxes.clear();

    QRegularExpression rex("(<p[^>]*>|<img[^>]*>|<table[^>]*>|</table>|<td[^>]*>)");
    QRegularExpressionMatchIterator itr;

    itr = rex.globalMatch(initial);

    QString temp_tags;
    bool inTable = false;

    while (itr.hasNext())
    {
        QRegularExpressionMatch match = itr.next();
        QString bbox_tags = match.captured(1);

        int first, last;
        first = bbox_tags.indexOf("bbox");
        if ((bbox_tags.indexOf("title=\"bbox") == -1) || (first == -1)) {
            temp_tags = "";
        } else { // If bbox tag is present
            int i = first;
            while (bbox_tags[i] != "\"") {
                i++;
            }
            last = i - 1;
            temp_tags = bbox_tags.mid(first, last - first + 1);
            temp_tags = temp_tags.simplified();
        }

        /*! @todo
         * 1. If images are inside tables
         * 2. If multiple lines are there in one cell of table i.e. if there are multiple paragraphs in one table cell
         */

        if(bbox_tags.left(2) == "<i") {
            bboxes.push_back({"img",temp_tags});
        } else if(bbox_tags.left(2) == "<p" && (!inTable)) {
            bboxes.push_back({"p",temp_tags});
        } else if (bbox_tags.left(3) == "<td") {
            bboxes.push_back({"td", temp_tags});
        } else if (bbox_tags.left(6) == "<table") { // Table start
            inTable = true;
            bboxes.push_back({"table", temp_tags});
        } else if (bbox_tags.left(7) == "</table") {
            inTable = false;
            bboxes.push_back({"/table", temp_tags});
        }
    }
}



/*!
 * \brief HandleBbox::latex2png
 * \param inputText
 * Doing equation latex to equaton png mapping
 * we are showing png in our tool and saving Latex form in html page
 * \return
 */
QString HandleBbox::latex2png(QString inputText)
{ 
    if(inputText.contains("$$")){

        QRegularExpression rex("<a(.*?)</a>",QRegularExpression::DotMatchesEverythingOption);
        QRegularExpressionMatchIterator itr;
        itr = rex.globalMatch(inputText);
        while(itr.hasNext()){

            QRegularExpressionMatch match = itr.next();
            QString text = match.captured(1);
            if(text.contains("Equations_"))
            {
                int sindex = match.capturedStart(1);
                int l_index = match.capturedEnd(1);
                std::string inputText_ = text.toStdString();
                int ind = inputText_.find("/");
                int lindex = inputText_.find(".tex");

                std::string str = inputText_.substr(ind,lindex-ind);
                QString path = QString::fromStdString(str) + ".png";
                QString html = "<img src=\""+path+"\">";
                text = "<a"+text+"</a>";
                inputText.replace(text,html);
            }

        }
        inputText = inputText.replace("$$","dne_nqe"); //where dne_nqe is a random string used as end delimiter here.
        //Note that this string should not appear as an original text - else it will cause parsing issues.
        QRegularExpression rex_dollar("dne_nqe(.*?)dne_nqe",QRegularExpression::DotMatchesEverythingOption);
        inputText = inputText.remove(rex_dollar);
    }
    return inputText;
}

