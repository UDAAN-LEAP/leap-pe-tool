#include "globalreplaceworker.h"
#include <QDir>
#include <QDirIterator>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <QTextBrowser>
#include <sstream>
#include <string>
#include <mainwindow.h>
#include <QFile>
#include <editdistance.h>
//using namespace std;

GlobalReplaceWorker::GlobalReplaceWorker(QObject *parent,
                                         QList<QString> *filesChangedUsingGlobalReplace,
                                         QMap<QString, QString> *mapOfReplacements,
                                         QMap<QString, QString> globalReplacementMap,
                                         QMap<QPair<QString,QString>,QString> globalReplacementMapAfterCheck,
                                         QMap<QString, QString> replaceInAllPages_Map,
                                         QMap<QString, QString> replaceInUneditedPages_Map,
                                         QString currentFileDirectory,
                                         QString gDirTwoLevelUp,
                                         QString gCurrentPageName,
                                         int numOfChangedWords,
                                         int check,
                                         int *r1,
                                         int *r2,
                                         int *x1,
                                         int *files,
                                         int pairMap
                                         ) : QObject(parent)
{
    this->filesChangedUsingGlobalReplace = filesChangedUsingGlobalReplace;
    this->mapOfReplacements = mapOfReplacements;
    this->globalReplacementMap = globalReplacementMap;
    this->globalReplacementMap2 = globalReplacementMap;
    this->replaceInAllPages_Map = replaceInAllPages_Map;
    this->replaceInUneditedPages_Map = replaceInUneditedPages_Map;
    this->currentFileDirectory = currentFileDirectory;
    this->gDirTwoLevelUp = gDirTwoLevelUp;
    this->gCurrentPageName = gCurrentPageName;
    this->numOfChangedWords = numOfChangedWords;
    this->check = check;
    this->r1 = r1;
    this->r2 = r2;
    this->x1 = x1;
    this->files = files;

    this-> globalReplacementMapAfterCheck = globalReplacementMapAfterCheck;
    this->pairMap = pairMap;

    editedFilesLogPath = gDirTwoLevelUp + "/Dicts/" + ".EditedFiles.txt";
}

int GlobalReplaceWorker::writeGlobalCPairsToFiles(QString file_path, QMap<QString, QString> globalReplacementMap)
{
    //save bbox information of files
    if(file_path.endsWith(".html")){
        saveBboxInfo(file_path);
    }
    // if any file other than html is passed, just return back
    if(!file_path.endsWith(".html") || file_path.endsWith(gCurrentPageName)){
        return 0;
    }
    QMap <QString, QString>::iterator grmIterator;
    QFile f(file_path);
    f.open(QIODevice::ReadOnly);
    QStringList temporaryList = file_path.split("/");
    QString pageName = temporaryList.at(temporaryList.size()-1);

    //!Set encoding and read the file content
    QTextStream in(&f);
    in.setCodec("UTF-8");
    QString s1 = in.readAll();
    f.close();
    f.open(QIODevice::WriteOnly);
    int replaced = 0, tot_replaced = 0;

    //create new text browser for html files(such that replacement works on text instead of html)
    QTextBrowser * browser = new QTextBrowser();
    browser->setReadOnly(false);

    QFont font("Shobhika-Regular");
    font.setWeight(16);
    font.setPointSize(16);
    font.setFamily("Shobhika");
    browser->setFont(font);
    browser->setHtml(s1);
    //QString pageName;

    QString replacementString1;
    //!Replacing words by iterating the map
    if(pairMap)
    {

    QMap< QPair<QString,QString>,QString>::iterator grmIterator;
    for (grmIterator = globalReplacementMapAfterCheck.begin(); grmIterator != globalReplacementMapAfterCheck.end(); ++grmIterator)
        {

                if(pageName != grmIterator.key().second)
                {
                    //qDebug()<<"NOT CHANGED in -------->"<<pageName<<":"<<grmIterator.key()<<","<<grmIterator.value()<<endl;
                    continue;
                }

                //qDebug()<<"CHANGED in -------->"<<pageName<<":"<<grmIterator.key()<<","<<grmIterator.value()<<endl;

            //qDebug() << "grmIterator Key : " <<grmIterator.key()<<"grmIterator.value : "<<grmIterator.value();
                //QString sanstr = QRegExp::escape(grmIterator.value());    //sanitized string
                QString sanstr(grmIterator.value());
                sanstr = "(\\b)"+sanstr+"(\\b)";
                QRegExp re(sanstr);
                //QString pattern = "(\\b)"+sanstr+"(\\b)"; // \b is word boundary, for cpp compilers an extra \ is required before \b, refer to QT docs for details
                //QRegExp re(pattern);
                QString replacementString = grmIterator.key().first; // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
                std::string str = replacementString.toStdString();
                //qDebug() << "San : " << sanstr << "\nRegexp : " << re;
                QString::fromStdString(str).toUtf8();
                //QString replacementString1 = QString::fromStdString(str).trimmed();
                //QString replacementString1 = "<span style = \"background-color:#ffff00;\">" + QString::fromStdString(str).trimmed() + "</span>";
                replacementString1 = QString::fromStdString(str); //.trimmed();
                (*mapOfReplacements)[grmIterator.value()] = grmIterator.key().first.trimmed();
                //input.replace(re, replacementString1);
                browser->moveCursor(QTextCursor::Start);

                //qDebug()<<"____REPLACEMENT_____"<<replacementString1;

                while(browser->find(re))
                {
                    //qDebug()<<"____REPLACEMENT in LOOP_____";
                    QTextCursor cursor = browser->textCursor(); //get the cursor
                    QTextCharFormat fmt;
                    int pos = cursor.position(); //get the cursor position
                    int ancr = pos - replacementString.size() + 1; //anchor is now cursor position - length of old word to be replaced
                    //qDebug()<<"pos : ancr"<<pos<<ancr;
                    if (pos < ancr) {
                        cursor.setPosition(pos, QTextCursor::MoveAnchor);
                        cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                    }
                    fmt = cursor.charFormat(); //get the QTextCharFormat of old word/phrase to be replaced
                    browser->textCursor().insertHtml("<span style = \"background-color:#ffff00;\">"+replacementString1+"</span>");
                    cursor = browser->textCursor(); //get new cursor position after old word is replaced by new one

                    pos = cursor.position();
                    ancr = pos - replacementString1.size();//anchor is cursor position - new word/phrase length
                    cursor.setPosition(pos, QTextCursor::MoveAnchor);
                    cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                    //qDebug()<<"pos : ancr"<<pos<<ancr;
                    cursor.mergeCharFormat(fmt); //apply the text properties captured earlier

                    tot_replaced = tot_replaced + 1;
                }
        }
    }
    else
    {
        QMap<QString,QString>::iterator grmIterator;
        for (grmIterator = globalReplacementMap2.begin(); grmIterator != globalReplacementMap2.end(); ++grmIterator)
            {


                   // qDebug()<<"CHANGED in -------->"<<pageName<<":"<<grmIterator.key()<<","<<grmIterator.value()<<endl;

                //qDebug() << "grmIterator Key : " <<grmIterator.key()<<"grmIterator.value : "<<grmIterator.value();
                    //QString sanstr = QRegExp::escape(grmIterator.value());    //sanitized string
                    QString sanstr(grmIterator.key());
                    sanstr = "(\\b)"+sanstr+"(\\b)";
                    QRegExp re(sanstr);

                    //QString pattern = "(\\b)"+sanstr+"(\\b)"; // \b is word boundary, for cpp compilers an extra \ is required before \b, refer to QT docs for details
                    //QRegExp re(pattern);
                    QString replacementString = grmIterator.value(); // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
                    std::string str = replacementString.toStdString();
                    //qDebug() << "San : " << sanstr << "\nRegexp : " << re;
                    QString::fromStdString(str).toUtf8();
                    //QString replacementString1 = QString::fromStdString(str).trimmed();
                    //QString replacementString1 = "<span style = \"background-color:#ffff00;\">" + QString::fromStdString(str).trimmed() + "</span>";
                    replacementString1 = QString::fromStdString(str); //.trimmed();
                    (*mapOfReplacements)[grmIterator.key()] = grmIterator.value().trimmed();
                    //input.replace(re, replacementString1);
                    browser->moveCursor(QTextCursor::Start);

                    //qDebug()<<"____REPLACEMENT_____"<<replacementString1;

                    while(browser->find(re))
                    {
                       // qDebug()<<"____REPLACEMENT in LOOP_____";
                        QTextCursor cursor = browser->textCursor(); //get the cursor
                        QTextCharFormat fmt;
                        int pos = cursor.position(); //get the cursor position
                        int ancr = pos - replacementString.size() + 1; //anchor is now cursor position - length of old word to be replaced
                        //qDebug()<<"pos : ancr"<<pos<<ancr;
                        if (pos < ancr) {
                            cursor.setPosition(pos, QTextCursor::MoveAnchor);
                            cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                        }
                        fmt = cursor.charFormat(); //get the QTextCharFormat of old word/phrase to be replaced
                        browser->textCursor().insertHtml("<span style = \"background-color:#ffff00;\">"+replacementString1+"</span>");
                        cursor = browser->textCursor(); //get new cursor position after old word is replaced by new one

                        pos = cursor.position();
                        ancr = pos - replacementString1.size();//anchor is cursor position - new word/phrase length
                        cursor.setPosition(pos, QTextCursor::MoveAnchor);
                        cursor.setPosition(ancr, QTextCursor::KeepAnchor);
                        //qDebug()<<"pos : ancr"<<pos<<ancr;
                        cursor.mergeCharFormat(fmt); //apply the text properties captured earlier

                        tot_replaced = tot_replaced + 1;
                    }
            }
    }

    s1 = browser->toHtml();

    in << s1;
    f.flush();
    f.close();
    browser->close();
    //call filterHtml() function to filter html files, bboxInsertion() to insert back bbox information
//  filterHtml(file_path);
    bboxInsertion(file_path);

    return tot_replaced;
}

void GlobalReplaceWorker::replaceWordsInFiles()
{
    QDirIterator dirIterator(currentFileDirectory, QDirIterator::Subdirectories);
    QDir currDir(currentFileDirectory);
    QString suffix;
    QString toolMode = currentFileDirectory.right(currentFileDirectory.size() - currentFileDirectory.lastIndexOf('/') - 1);
    if (toolMode == "CorrectorOutput" || toolMode == "VerifierOutput")
    {
        suffix = "*.html";
    }
    else if (toolMode == "Document")
    {
        suffix = "*.txt";
    }
    QStringList fileNameList = currDir.entryList({suffix}, QDir::Files);
    int numberOfFiles = fileNameList.size();
    int count = 0;
    int perc = 0; // percentage to be shown on progress bar

    if (numOfChangedWords == 1)
    {
        if (check == 0)
        {
            while (dirIterator.hasNext()) {
                QString it_file_path = dirIterator.next();
                bool isFileInEditedFilesLog = isStringInFile(editedFilesLogPath, it_file_path);
                QString suff = dirIterator.fileInfo().completeSuffix();
                if(!isFileInEditedFilesLog)
                {
                    (*filesChangedUsingGlobalReplace).append(it_file_path);
                    if(suff == "html") {
                        *r1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
                        *r2 = *r2 + *r1;
                        if(*r1 > 0)
                            (*files)++;
                    }
                    else if(suff != "dict"){
                        *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
                    }
                }
                count++;
                int tempPerc = (count * 100) / numberOfFiles;
                if (tempPerc > perc) {
                    perc = tempPerc;
                    emit changeProgressBarValue(perc);
                }
            }
        }
        else if (check == 1)
        {
            while (dirIterator.hasNext()) {
                QString it_file_path = dirIterator.next();
                QString suff = dirIterator.fileInfo().completeSuffix();
                (*filesChangedUsingGlobalReplace).append(it_file_path);
                if(suff == "html") {
                    *r1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
                    *r2 = *r2 + *r1;
                    if(*r1 > 0)
                        (*files)++;
                }
                else if(suff != "dict"){
                    *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
                }
                count++;
                int tempPerc = (count * 100) / numberOfFiles;
                if (tempPerc > perc) {
                    perc = tempPerc;
                    emit changeProgressBarValue(perc);
                }
            }
        }
    }
    else if (numOfChangedWords > 1)
    {
        //! Replacing in Unedited pages
        while (dirIterator.hasNext())
        {
            QString it_file_path = dirIterator.next();
            bool isFileInEditedFilesLog = isStringInFile(editedFilesLogPath, it_file_path);
            QString suff = dirIterator.fileInfo().completeSuffix();
            if (!isFileInEditedFilesLog)
            {
                (*filesChangedUsingGlobalReplace).append(it_file_path);
                if(suff == "html") {
                    *r1 = writeGlobalCPairsToFiles(it_file_path, replaceInUneditedPages_Map);
                    *r2 = *r2 + *r1;
                    if(*r1 > 0)
                        (*files)++;
                }
                else if(suff != "dict"){
                    *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
                }
            }
            count++;
            int tempPerc = (count * 100) / numberOfFiles;
            if ((tempPerc > perc) && (tempPerc < 50)) {
                perc = tempPerc;
                emit changeProgressBarValue(perc);
            }
        }
        emit changeProgressBarValue(50);
        count = 0;
        perc = 0;

        QDirIterator dirIterator_2(currentFileDirectory, QDirIterator::Subdirectories);

        //! Replacing in all pages
        while (dirIterator_2.hasNext())
        {
            QString it_file_path = dirIterator_2.next();
            QString suff = dirIterator_2.fileInfo().completeSuffix();
            (*filesChangedUsingGlobalReplace).append(it_file_path);
            if(suff == "html") {
                *r1 = writeGlobalCPairsToFiles(it_file_path, replaceInAllPages_Map);
                *r2 = *r2 + *r1;
                if(*r1 > 0)
                    (*files)++;
            }
            else if(suff != "dict"){
                *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap);
            }

            count++;
            int tempPerc = (count * 100) / numberOfFiles;
            if ((tempPerc > perc) && (tempPerc > 50)) {
                perc = tempPerc;
                emit changeProgressBarValue(perc);
            }
        }
    }

    emit changeProgressBarValue(100);
    emit finishedReplacingWords();
}

void GlobalReplaceWorker::writeLogs()
{
    if(globalReplacementMap.values().length()>0)
    {
        QMap <QString, QString>::iterator grmIterator;

        QDir directory(gDirTwoLevelUp);
        QString setName=directory.dirName();
        QString filename = gDirTwoLevelUp+"/"+setName+"_logs.csv";
        QFile csvFile(filename);
        if(!csvFile.exists())
        {
            csvFile.open(QIODevice::ReadWrite | QIODevice::Append);
            QTextStream output(&csvFile);
            output.setCodec("UTF-8");
            output << "Source Word,Target Word,Type of Replacement,Time of Replacement,Page Name,Set name";
        }

        else
        {
            csvFile.open(QIODevice::ReadWrite | QIODevice::Append);
        }

        for (grmIterator = globalReplacementMap.begin(); grmIterator != globalReplacementMap.end(); ++grmIterator)
        {
            QString sourceString = grmIterator.key();
            QString replaceString= grmIterator.value();
            QString typeOfReplacement;
            if(replaceInAllPages_Map.contains(sourceString)||check==1)
            {
               typeOfReplacement="All Pages";
            }
            else if(replaceInUneditedPages_Map.contains(sourceString)||check==0)
            {
               typeOfReplacement="Unedited Pages";
            }

            QDateTime current = QDateTime::currentDateTime();
            QString time = current.toString();

            QTextStream output(&csvFile);
            output.setCodec("UTF-8");
            //qDebug() << "csv Contents" << output.readAll();
            output << "\n";
            output<<sourceString<<","<<replaceString<<","<<typeOfReplacement<<","<<time<<","<<gCurrentPageName<<","<<setName;
        }
        csvFile.close();
        check=2;

    }

    emit finishedWritingLogs();
}

/*!
 * \fn GlobalReplaceWorker::isStringInFile
 * \brief Checks if a QString is in file at file_path
 * \param file_path
 * \param searchString
 * \return 0 if not present and 1 if it is present
 */
bool GlobalReplaceWorker::isStringInFile(QString file_path, QString searchString)
{
    QFile fileToSearchIn(file_path);
    bool textFound = false;

    if(fileToSearchIn.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&fileToSearchIn);
        QString line;

        //! Check in everyline if string exists
        do{
            line = in.readLine();
            if(line.contains(searchString)){
                textFound = true;
                break;
            }
        }while(!line.isNull());
    }
    fileToSearchIn.close();

    return textFound;
}
void GlobalReplaceWorker::saveBboxInfo(QString htmlFile){
    QFile gfile(htmlFile);
    gfile.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&gfile);
    QString initial = in.readAll();
    gfile.close();
    QString bboxfile = gfile.fileName();
    bboxfile = bboxfile.replace(".html", ".bbox");


    if(!QDir(gDirTwoLevelUp+"/bboxf").exists())
            QDir().mkdir(gDirTwoLevelUp+"/bboxf");

        bboxfile=bboxfile.replace("CorrectorOutput","bboxf");


    QFile bbox_file(bboxfile);
    if(initial.contains("bbox") && !bbox_file.exists())
      {
          QMap<QString, QString> bbox;
          QStringList plist = initial.split("<span class");
          for(int i=0;i<plist.length();i++)
          {
             QString bbox_tags = plist[i];
             int first = bbox_tags.indexOf("bbox");
             int last = bbox_tags.indexOf(";\">");
             bbox_tags = bbox_tags.mid(first,last-first);
             bbox_tags = bbox_tags.remove("\">\n");
             bbox_tags = bbox_tags.trimmed();

             QStringList bbox_coordinates = bbox_tags.split(" ");
             bbox_tags = bbox_coordinates[0] + " " + bbox_coordinates[1] + " " + bbox_coordinates[2] + " " + bbox_coordinates[3] + " " + bbox_coordinates[4];

             int start = plist[i].indexOf(";\">\n");
             int end = plist[i].indexOf("</span>");
             QString sents = plist[i].mid(start, end-start);
             sents = sents.remove(";\">\n");
             sents = sents.trimmed();
             bbox.insert(bbox_tags, sents);

          }
          bbox.erase(bbox.begin());
          //qDebug()<<bbox;
          bbox_file.open(QIODevice::ReadWrite | QFile::Truncate);
          QDataStream out (&bbox_file);
          out.setVersion(QDataStream::Qt_5_3);
          out<<bbox;
          bbox_file.flush();
          bbox_file.close();
         // qDebug() << "bbox file written succesfully ... ";
      }
}

//void GlobalReplaceWorker::filterHtml(QString f)
//{
//    QFile file(f);

//    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug() << "File not opened for reading";
//        return;
//    }

//    QTextStream in(&file);
//    in.setCodec("UTF-8");
//    QString text = in.readAll();
//    file.close();

//    QRegularExpression re1("(<span[^>]*>)");
//    QRegularExpressionMatchIterator it;

//    it = re1.globalMatch(text);

//    int prevStringStart = -1, prevStringEnd = -1, curStringStart = -1, curStringEnd = -1;
//    QString prevString = "", curString = "";
//    QVector<QVector<int> > results;

//    while (it.hasNext()) {
//        QRegularExpressionMatch match = it.next();
//        curString = match.captured(1);
//        curStringStart = match.capturedStart(1);
//        curStringEnd = match.capturedEnd(1);

//        // Checking if a new paragraph is starting or not
//        if (prevString != "") {
//            QString subString = text.mid(prevStringEnd, curStringEnd - prevStringEnd);
//            if (subString.contains("</p>")) {
//                prevString = "";
//            }
//        }

//        if (prevString == "") {
//            prevString = curString;
//            prevStringStart = curStringStart;
//            prevStringEnd = curStringEnd;
//        }
//        else if (prevString == curString) {
//            QString subs = text.mid(prevStringEnd, curStringStart - prevStringEnd);
//            int closingIndexOfspanClosing = subs.indexOf("</span>")+QString("</span>").length();

//            if ((prevStringEnd + closingIndexOfspanClosing) == curStringStart) {
//                results.push_back({prevStringStart, prevStringEnd, curStringStart, curStringEnd});
//            }

//            prevStringStart = curStringStart;
//            prevStringEnd = curStringEnd;
//        }
//    }

//    if (!file.open(QFile::WriteOnly)) {
//        qDebug() << "File not opened for writing";
//        return;
//    }
//    QTextStream out(&file);
//    out.setCodec("UTF-8");

//    int index = 0, flag = 0, flag_test = 0;
//    int ite = 0, value_prev = 0;

//    while(flag_test == 0 && index < text.size()) {
//        QList<int> list_;

//        for(int x = value_prev; x < results.size(); x++) {
//            if(x < results.size() - 1) {
//                if(results[x][2] == results[x+1][0]) {
//                    int sizeList = list_.size();
//                    if(sizeList == 0 || list_[sizeList - 1] != results[x][2]) {
//                        list_.append(results[x][2]);
//                    }
//                    list_.append(results[x][3]);
//                    list_.append(results[x+1][2]);
//                }
//                else {
//                    int sizeList = list_.size();
//                    if(sizeList == 0)
//                        list_.append(results[x][2]);
//                    list_.append(results[x][3]);
//                    value_prev = x+1;
//                    break;
//                }
//            }
//            else {
//                list_.append(results[x][2]);
//                list_.append(results[x][3]);
//                value_prev = x+1;
//                break;
//            }
//        }

//        for(int tmp = 0; tmp < list_.size(); tmp++) {
//            if(tmp == 0) {
//                while(index < list_[tmp]-7){
//                    QChar s = text.at(index);
//                    out << s;
//                    index++;
//                }
//            }
//            else {
//                index = list_[tmp];
//                if(tmp < list_.size() - 1)
//                    tmp++;
//                while(index < list_[tmp]-7) {
//                    QChar s = text.at(index);
//                    out << s;
//                    index++;
//                }
//            }
//        }

//        if(value_prev >= results.size()) {
//            flag_test = 1;
//        }
//    }
//    while(index < text.size()) {
//        QChar s = text.at(index);
//        out << s;
//        index++;
//    }
//    file.flush();
//    file.close();
//}

void GlobalReplaceWorker::bboxInsertion(QString f){
    QFile file(f);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "File not opened for reading";
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");
    QString text = in.readAll();
    file.close();

    QRegularExpression rex("<p(.*?)</p>",QRegularExpression::DotMatchesEverythingOption);
    QRegularExpression rex_("<span(.*?)</span>",QRegularExpression::DotMatchesEverythingOption);

    QRegularExpression rex2("(<p[^>]*>|<span[^>]*>)");
    QString fBbox = f;
    fBbox.replace(".html",".bbox");
    fBbox.replace("CorrectorOutput","bboxf");
    //qDebug()<<"file = "<<fBbox;
    QFile bbox_file(fBbox);
    if(bbox_file.exists())
    {
        QRegularExpressionMatchIterator itr,itr_;
        itr = rex.globalMatch(text);
        itr_ = rex_.globalMatch(text);
        if (!bbox_file.open(QIODevice::ReadOnly)) {
            qDebug() << "Unable to open bbox_file!";
            return;
        }

        QDataStream in_(&bbox_file);
        in_.setVersion(QDataStream::Qt_5_3);
        QMap<QString,QString> coordinates;

        in_ >> coordinates;
        bbox_file.close();
        QString bbox_coordinates;
        QStringList bbox_list,bbox_list_;
        QMap<QString, QString>::iterator ci;
        edit_Distance edit;
        //qDebug()<<"in_ : map="<<in_<<":"<<coordinates;
        QRegularExpression rex3("(<[^>]*>|[^>]*>)");
        while (itr.hasNext())
        {
            QRegularExpressionMatch match = itr.next();
            QString ex = match.captured(1);

            ex.remove(rex3);
            double max = 0;
            for(ci = coordinates.begin(); ci!=coordinates.end(); ++ci)
            {
                double similarity = edit.getSimilarityValue(ex.toStdString(), ci.value().toStdString());
                if(similarity>max)
                {
                    bbox_coordinates = ci.key();
                    max = similarity;
                }
            }
            bbox_coordinates.remove("\">");
            if(bbox_coordinates != "")
            bbox_list.append(bbox_coordinates);
        }
        //itr_ is for span tags
        while (itr_.hasNext())
        {
            QRegularExpressionMatch match_ = itr_.next();
            QString ex_ = match_.captured(1);
            ex_.remove(rex3);
            double max = 0;
            for(ci = coordinates.begin(); ci!=coordinates.end(); ++ci)
            {
                double similarity = edit.DiceMatch(ex_.toStdString(), ci.value().toStdString());

                if(similarity>max)
                {
                    bbox_coordinates = ci.key();
                    max = similarity;
                }
            }
            bbox_coordinates.remove("\">");
            if(bbox_coordinates != "")
            bbox_list_.append(bbox_coordinates);
        }
        //now just insert the bbox coordinates into the file saved
        QRegularExpressionMatchIterator itr2;
        itr2 = rex2.globalMatch(text,0);
        int i=0,j=0;
//        qDebug()<<"bbox file="<<fBbox;
//        qDebug()<<"bbox file size="<<bbox_file.size()<<coordinates;
//        qDebug()<<"bbox_list="<<bbox_list;
//        qDebug()<<"bbox_list_="<<bbox_list_;
        if(bbox_list.size() == 0 && bbox_list_.size() == 0){
            return;
        }
        while (itr2.hasNext()) {
            QRegularExpressionMatch match2 = itr2.next();
            QString ex = match2.captured(1);
            int endIndex = match2.capturedEnd(1);
            if((ex[1] == "p" || ex[1] == "P") && i<bbox_list.size()){
                endIndex = endIndex-1;
                text.insert(endIndex," title=\""+bbox_list[i]+"\"");//index+1
                i++;
            }
            else if((ex[1] == "s" || ex[1] == "S") && j<bbox_list_.size()){
                endIndex = endIndex-1;
                text.insert(endIndex," title=\""+bbox_list_[j]+"\"");
                j++;
            }

            itr2 = rex2.globalMatch(text,endIndex+1);

        }
        if(file.open(QFile::WriteOnly))
        {
            QTextStream out2(&file);
            out2.setCodec("UTF-8");          //!Sets the codec for this stream
            //text = "<style> body{ width: 21cm; height: 29.7cm; margin: 30mm 45mm 30mm 45mm; } </style>" + text;     //Formatting the output using CSS <style> tag
            out2 << text;
            file.flush();      //!Flushes any buffered data waiting to be written in the \a sFile
            file.close();      //!Closing the file
        }
    bbox_list.clear();bbox_list_.clear();
    }

}

