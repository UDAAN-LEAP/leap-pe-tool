#include "globalreplaceworker.h"
#include <QDir>
#include <QDirIterator>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>
#include <sstream>
#include <string>
#include <mainwindow.h>
#include <QFile>
#include <editdistance.h>


/*!
 * \fn GlobalReplaceWorker::GlobalReplaceWorker
 * \brief This is the constructor which initializes the objects needed to be shared between the main(GUI) thread and the another thread.
 * \param parent
 * \param filesChangedUsingGlobalReplace
 * \param mapOfReplacements
 * \param globalReplacementMap
 * \param globalReplacementMapAfterCheck
 * \param replaceInAllPages_Map
 * \param replaceInUneditedPages_Map
 * \param currentFileDirectory
 * \param gDirTwoLevelUp
 * \param gCurrentPageName
 * \param numOfChangedWords
 * \param check
 * \param r1
 * \param r2
 * \param x1
 * \param files
 * \param pairMap
 */
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

/*!
 * \fn GlobalReplaceWorker::writeGlobalCPairsToFiles
 * \brief This function writes the required replacements to the file specified
 * \details It copies the contents of the file to a QTextDocument which is used for replacement purpose.
 * \param file_path
 * \param globalReplacementMap
 * \param doc
 * \return Number of replaced words
 */
int GlobalReplaceWorker::writeGlobalCPairsToFiles(QString file_path, QMap<QString, QString> globalReplacementMap, QTextDocument *doc)
{
    // if any file other than html is passed, just return back
    doc->clear();
    if(!file_path.endsWith(".html")){
        return 0;
    }
    if (handleBbox != nullptr) {
        delete handleBbox;
    }

    QFile *file = new QFile(file_path);
    handleBbox = new HandleBbox(doc);
    QTextDocument *curDoc = handleBbox->loadFileInDoc(file);

    if (curDoc == nullptr) {
        qDebug() << "Cannot load file";
        return 0;
    }

    QMap <QString, QString> sentencesReplaced;
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

    QString replacementString1;
    //!Replacing words by iterating the map
    if(pairMap)
    {
        QMap< QPair<QString,QString>,QString>::iterator grmIterator;
        QMap<QString, QString>::Iterator itr;
        for (grmIterator = globalReplacementMapAfterCheck.begin(); grmIterator != globalReplacementMapAfterCheck.end(); ++grmIterator)
        {
            if(pageName != grmIterator.key().second)
            {
                continue;
            }
//            qDebug()<<"Going to replace in ::"<<pageName;
            QString sanstr(grmIterator.value());
            sanstr.replace("\(","\\(");sanstr.replace("\)","\\)");
            sanstr = sanstr.simplified();
            QString replacementString = grmIterator.key().first; // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
            QStringList org_sen = sanstr.split(" ");

            std::string rep = replacementString.toStdString();
            QString::fromStdString(rep).toUtf8();
            QString replacement = QString::fromStdString(rep);

            QStringList replaced_list = replacement.split(" ");
            QString replaced_sen = replacement;
            for(itr = sentencesReplaced.begin(); itr != sentencesReplaced.end(); ++itr){
                qDebug()<<sanstr<<" :: "<<itr.key();
                if(sanstr.contains(itr.key())){
                    sanstr = sanstr.replace(itr.key(),itr.value());
                    replacementString = replacementString.replace(itr.key(),"<span style = \"background-color:#ffff00;\">"+itr.value()+"</span>");
                }
            }

            std::string str = replacementString.toStdString();
            QString::fromStdString(str).toUtf8();
            replacementString1 = QString::fromStdString(str);
            (*mapOfReplacements)[grmIterator.value()] = grmIterator.key().first.trimmed();
            //browser->moveCursor(QTextCursor::Start);

            QRegularExpression re(sanstr);
            //Code to highlight replaced words only; finding sentence1 -sentence2
            for(int i=0; i<org_sen.size(); i++){
                if(replaced_list.contains(org_sen[i]))
                    replaced_sen = replaced_sen.remove(org_sen[i]);
            }
            replaced_sen = replaced_sen.simplified();
            qDebug() <<"original :"<<sanstr;
            QTextCursor docCursor(doc);
            docCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
            int startPos = 0;

            while (true) {
                QTextCursor cur = doc->find(re, startPos, QTextDocument::FindWholeWords);
                QTextCursor origCur(cur);
                if (cur.isNull()) {
                    break;
                }

                QTextCharFormat fmt;
                startPos = cur.position() + 1;
                int pos = cur.position(); // get the cursor position
                int ancr = pos - replacementString.size() + 1; // anchor is now cursor position - length of old word to be replaced

                if (pos < ancr) {
                    cur.setPosition(pos, QTextCursor::MoveAnchor);
                    cur.setPosition(ancr, QTextCursor::KeepAnchor);
                }
                fmt = cur.charFormat(); // get the QTextCharFormat of old/word phrase to be replaced
                replacementString1 = replacementString.simplified();
                QString final_str = replacementString1;
                final_str = final_str.replace(replaced_sen, "<span style = \"background-color:#ffff00;\">" + replaced_sen + "</span>");
                origCur.insertHtml(final_str);
                cur.setPosition(origCur.position());
                pos = cur.position();
                ancr = pos - replacementString1.size();
                cur.setPosition(pos, QTextCursor::MoveAnchor);
                cur.mergeCharFormat(fmt); // apply the text properties captured earlier
                tot_replaced += 1;
                sentencesReplaced.insert(sanstr, replacementString1);
            }
        }
    }
    else
    {
        QMap<QString,QString>::iterator grmIterator;
        for (grmIterator = globalReplacementMap2.begin(); grmIterator != globalReplacementMap2.end(); ++grmIterator)
        {
            QString sanstr(grmIterator.key());
            sanstr.replace("\(","\\(");sanstr.replace("\)","\\)");
            QRegularExpression re(sanstr);
            QString replacementString = grmIterator.value(); // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
            std::string str = replacementString.toStdString();
            QString::fromStdString(str).toUtf8();
            replacementString1 = QString::fromStdString(str);
            (*mapOfReplacements)[grmIterator.key()] = grmIterator.value().trimmed();
            QTextCursor docCursor(doc);
            docCursor.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);

            int startPos = 0;
            while (true) {
                QTextCursor cur = doc->find(re, startPos, QTextDocument::FindWholeWords);
                QTextCursor origCur(cur);
                if (cur.isNull()) {
                    break;
                }
                QTextCharFormat fmt;
                startPos = cur.position() + 1;
                int pos = cur.position(); //get the cursor position
                int ancr = pos - replacementString.size() + 1; //anchor is now cursor position - length of old word to be replaced
                if (pos < ancr) {
                    cur.setPosition(pos, QTextCursor::MoveAnchor);
                    cur.setPosition(ancr, QTextCursor::KeepAnchor);
                }
                fmt = cur.charFormat(); //get the QTextCharFormat of old word/phrase to be replaced
                origCur.insertHtml("<span style = \"background-color:#ffff00;\">" + replacementString1 + "</span>");
                pos = cur.position();
                ancr = pos - replacementString1.size();//anchor is cursor position - new word/phrase length
                cur.setPosition(pos, QTextCursor::MoveAnchor);
                cur.setPosition(ancr, QTextCursor::KeepAnchor);
                cur.mergeCharFormat(fmt); //apply the text properties captured earlier
                tot_replaced += 1;
            }
        }
    }
    s1 = doc->toHtml();
    in << s1;
    f.flush();
    f.close();
    handleBbox->insertBboxes(file);
    return tot_replaced;
}

/*!
 * \fn GlobalReplaceWorker::replaceWordsInFiles
 * \brief This function traverses the user role's dir and filters the html files and passes the required files to writeGlobalCPairsToFiles() function for replacing the required replacements. It also emits the signal for updating progress bar.
 */
void GlobalReplaceWorker::replaceWordsInFiles()
{
    QTextDocument* doc = new QTextDocument();
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
                        *r1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
                        *r2 = *r2 + *r1;
                        if(*r1 > 0)
                            (*files)++;
                    }
                    else if(suff != "dict"){
                        *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
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
                    *r1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
                    *r2 = *r2 + *r1;
                    if(*r1 > 0)
                        (*files)++;
                }
                else if(suff != "dict"){
                    *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
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
                    *r1 = writeGlobalCPairsToFiles(it_file_path, replaceInUneditedPages_Map, doc);
                    *r2 = *r2 + *r1;
                    if(*r1 > 0)
                        (*files)++;
                }
                else if(suff != "dict"){
                    *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
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
                *r1 = writeGlobalCPairsToFiles(it_file_path, replaceInAllPages_Map, doc);
                *r2 = *r2 + *r1;
                if(*r1 > 0)
                    (*files)++;
            }
            else if(suff != "dict"){
                *x1 = writeGlobalCPairsToFiles(it_file_path, globalReplacementMap, doc);
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

/*!
 * \fn GlobalReplaceWorker::writeLogs
 * \brief It writes the logs in the [set-name]logs.csv file which resides in the set folder.
 * \details The format of logs is <SourceWord>,<TargetWord>,<TypeOfReplacement>,<TimeOfReplacement>,<PageName>,<SetName>
 */
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

/*!
 * \fn GlobalReplaceWorker::saveBboxInfo
 * \brief Saves the bbox info
 * \param htmlFile
 */
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

/*!
 * \fn GlobalReplaceWorker::bboxInsertion
 * \brief Inserts bbox into the saved file
 * \param f
 */
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
