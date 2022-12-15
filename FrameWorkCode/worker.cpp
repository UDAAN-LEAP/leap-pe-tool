#include "worker.h"
#include "slpNPatternDict.h"
#include "editdistance.h"


/*!
 * \fn Worker::Worker
 * \brief This class is used to execute Save Function of MainWindow class in a multithreaded fashion.
 * \param parent
 * \param mProject
 * \param gCurrentPageName
 * \param gCurrentDirName
 * \param gDirTwoLevelUp
 * \param s1
 * \param s2
 * \param CPair_editDis
 * \param CPairs
 * \param filestructure_fw
 */
Worker::Worker(QObject *parent,
               Project* mProject,
               QString gCurrentPageName,
               QString gCurrentDirName,
               QString gDirTwoLevelUp,
               QString s1,
               QString s2,
               std::map<std::string, std::string> CPair_editDis,
               std::map<string, set<string> >* CPairs,
               map<QString, QString> filestructure_fw
               ) : QObject(parent)
{
    this->CPairs = CPairs;
    this->mProject = mProject;
    this->s1 = s1;
    this->s2 = s2;
    this->CPair_editDis = CPair_editDis;
    this->gCurrentPageName = gCurrentPageName;
    this->gCurrentDirName = gCurrentDirName;
    this->gDirTwoLevelUp = gDirTwoLevelUp;
    this->filestructure_fw = filestructure_fw;
}

slpNPatternDict slnp;

/*!
 * \fn Worker::doSaveBackend
 * \brief This function calls SaveFile_Backend functions and emits finished() whenever the function completes
 *        executing.
 * \sa SaveFile_Backend()
 */
void Worker::doSaveBackend()
{
    QVector <QString> changedWords;
    QString tempPageName = gCurrentPageName;

    //! Selecting the location where file is to be saved
    QString changefiledir = filestructure_fw[gCurrentDirName];
    QString localFilename = gDirTwoLevelUp + "/" +changefiledir +"/" + tempPageName;

    localFilename.replace(".txt",".html");

    QFile sFile(localFilename);
    edit_Distance ed;
    changedWords = ed.editDistance(s1, s2);             // Update CPair by editdistance
    QVectorIterator<QString> i(changedWords);
    while (i.hasNext())
        qDebug() << i.next()<<endl;

    //! Do commit when there are some changes in previous and new html file on the basis of editdistance.
    if(changedWords.size())
    {
        if((*mProject).get_version().toInt())     //Check version number
        {
            QString commit_msg = "Corrector Turned in Version: " + (*mProject).get_version();
            //!Check commit condition
//            if(!(*mProject).commit(commit_msg.toStdString()))
//            {
//                return;
//            }
//            else
//            {
//                (*mProject).commit(commit_msg.toStdString());
//            }
        }
    }
    emit finished();
}

/*!
 * \fn Worker::addCpair
 * \brief It adds the replacements done using global-replace to the CPair.
 * \details This is done to show better suggestions to the user when he/she right clicks on a word.
 */
void Worker:: addCpair()
{
    //! Enters entries in CPairs through CPair_editDis; allows multiple entries for a incorrent word entry
    for(auto &elem : CPair_editDis)
    {
        //CPair.insert(make_pair(toslp1(elem.first), toslp1(elem.second)));
        if ( (*CPairs).find(elem.first) != (*CPairs).end())
        {
            std::set< std::string>& s_ref = (*CPairs)[elem.first];
            s_ref.insert(elem.second);
        }
        else
        {
            (*CPairs)[elem.first].insert(elem.second);
        }
    }

    //! Reflecting CPairs entries in the file /Dicts/CPair; Making it dynamic
    QString filename12 = (*mProject).GetDir().absolutePath() + "/Dicts/" + "CPair";
    QFile file12(filename12);
    QStringList split1;
    if(!file12.exists())
    {
        //       qDebug() << "No exist file "<<filename12;
    }
    else
    {
        QFile myfile(filename12);
        myfile.open(QIODevice::ReadOnly | QIODevice::Text);
        QTextStream out1(&myfile);
        out1.setCodec("UTF-8");
        QString text;
        while(!out1.atEnd())
        {
            text = out1.readLine();
            split1.append(text.split('\t'));
        }
        myfile.close();
    }

    //! Insert entries in Correct Formatting Hello (/t) hi,(comma)hiii
    if (file12.open(QIODevice::ReadWrite  | QIODevice::Text | QIODevice::Truncate))
    {
        QTextStream out(&file12);
        out.setCodec("UTF-8");
        map<string, set<string>>::iterator itr;
        set<string>::iterator set_it;
        int flag = 0;

        for (itr = (*CPairs).begin(); itr != (*CPairs).end(); ++itr)
        {
            //!Don't add special symbols to cpair file
            QString special_symbols = "~`!@#$%^&*()-+={}[]|\"/:\ ;'<>,.?;";
            int replaceFlag = 0;
            for(int i=0;i<QString::fromStdString(itr->first).size();i++){
                int count =0;
                for(int k=0;k<special_symbols.size();k++){
                    if(QString::fromStdString(itr->first)[i] != special_symbols[k]){
                        count +=1;
                    }
                    if(count == special_symbols.size()){
                        replaceFlag = 1;
                        break;
                    }
                }
                if(replaceFlag == 1)
                    break;
            }

            for(int i =0;i<split1.size();i+=2){
                if(QString::fromStdString(itr->first) == split1[i]){
                    flag = 1;
                    break;}
            }
            if(flag == 0 && replaceFlag == 1){
                split1.append(QString::fromStdString(itr->first));
                set_it = itr->second.begin();
                {
                    split1.append(QString::fromStdString(*set_it));

                }
            }

            flag = 0;
        }

        //!Add entries to cpair file {hi \t hello \n}
        for(int i=0;i<split1.size()-1;i+=2){
            out <<  split1[i] << '\t'<<split1[i+1]<<"\n";
        }
        file12.close();
    }
}
