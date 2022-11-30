#include "handlebbox.h"

//#include <QFile>
//#include <QTextCursor>
//#include <QTextStream>
//#include <QRegularExpression>
#include <QTextDocument>
//#include <QDebug>
//#include <QTextBlock>

HandleBbox::HandleBbox()
{
    this->doc = new QTextDocument();
    this->docIsPassed = true;
}

HandleBbox::HandleBbox(QTextDocument* doc)
{
    this->doc = doc;
    this->docIsPassed = false;
}

HandleBbox::~HandleBbox()
{
    if (docIsPassed) {
        delete doc;
    }
}

QTextDocument *HandleBbox::loadFileInDoc(QFile *f)
{
    QTextCursor cur(doc);
    if (!f->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Cannot open file";
        return nullptr;
    }
    QString line;
    int flag_ = 0;
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
                    if(inputText.contains("align=\"right\"")){
                        blockFormat.setAlignment(Qt::AlignRight);
                    }
                    else if(inputText.contains("align=\"center\"")){
                        blockFormat.setAlignment(Qt::AlignCenter);
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
                    if(inputText.contains("align=\"right\"")){
                        blockFormat.setAlignment(Qt::AlignRight);
                    }
                    else if(inputText.contains("align=\"center\"")){
                        blockFormat.setAlignment(Qt::AlignCenter);
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

        // If bbox is already present, move to next entry
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
        if ((bbox_tags.indexOf("title=\"bbox") == -1) || (first == -1)) { // If bbox tag is not present
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
