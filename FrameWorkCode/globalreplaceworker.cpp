#include "globalreplaceworker.h"
#include <QDir>
#include <QDirIterator>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

GlobalReplaceWorker::GlobalReplaceWorker(QObject *parent,
                                         QList<QString> *filesChangedUsingGlobalReplace,
                                         QMap<QString, QString> *mapOfReplacements,
                                         QMap<QString, QString> globalReplacementMap,
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
                                         int *files
                                         ) : QObject(parent)
{
    this->filesChangedUsingGlobalReplace = filesChangedUsingGlobalReplace;
    this->mapOfReplacements = mapOfReplacements;
    this->globalReplacementMap = globalReplacementMap;
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

    editedFilesLogPath = gDirTwoLevelUp + "/Dicts/" + ".EditedFiles.txt";
}

int GlobalReplaceWorker::writeGlobalCPairsToFiles(QString file_path, QMap<QString, QString> globalReplacementMap)
{
    QMap <QString, QString>::iterator grmIterator;
    QFile f(file_path);

    f.open(QIODevice::ReadOnly);

    //!Set encoding and read the file content
    QTextStream in(&f);
    in.setCodec("UTF-8");
    QString s1 = in.readAll();
    f.close();
    f.open(QIODevice::WriteOnly);
    int replaced = 0, tot_replaced = 0;

    //!Replacing words by iterating the map
    for (grmIterator = globalReplacementMap.begin(); grmIterator != globalReplacementMap.end(); ++grmIterator)
        {
            //qDebug() << "grmIterator Key : " <<grmIterator.key()<<"grmIterator.value : "<<grmIterator.value();
            if((grmIterator.key().split(" ", QString::SkipEmptyParts).count() == 1) || (grmIterator.value().split(" ", QString::SkipEmptyParts).count() == 1))
            {
                QString sanstr = QRegExp::escape(grmIterator.key());    //sanitized string
                QString pattern = "(\\b)"+sanstr+"(\\b)"; // \b is word boundary, for cpp compilers an extra \ is required before \b, refer to QT docs for details
                QRegExp re(pattern);
                QString replacementString = re.cap(1) + grmIterator.value() + re.cap(2); // \1 would be replace by the first paranthesis i.e. the \b  and \2 would be replaced by the second \b by QT Regex
                std::string str = replacementString.toStdString();
                //qDebug() << "San : " << sanstr << "\nRegexp : " << re;
                QString::fromStdString(str).toUtf8();
                //QString replacementString1 = QString::fromStdString(str).trimmed();
                QString replacementString1 = "<span style = \"background-color:#ffff00;\">" + QString::fromStdString(str).trimmed() + "</span>";
                (*mapOfReplacements)[grmIterator.key()] = grmIterator.value().trimmed();
                s1.replace(re, replacementString1);
                replaced = s1.count(replacementString1);
                tot_replaced = tot_replaced + replaced;
            }

            else if((grmIterator.key().split(" ", QString::SkipEmptyParts).count() > 1) || (grmIterator.value().split(" ", QString::SkipEmptyParts).count() > 1))
            {
                s1 = s1.simplified();
                (*mapOfReplacements)[grmIterator.key()] = grmIterator.value().trimmed();
                QString replacementString = "<span style = \"background-color:#ffff00;\">" + grmIterator.value() + "</span>";
                s1.replace(grmIterator.key(), replacementString);
                replaced = s1.count(grmIterator.value());
                tot_replaced = tot_replaced + replaced;

            }

        }
    in << s1;
    f.flush();
    f.close();

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




