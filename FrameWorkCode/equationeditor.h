#ifndef EQUATIONEDITOR_H
#define EQUATIONEDITOR_H
#include "customtextbrowser.h"
#include <QDialog>
#include <YAWYSIWYGEE>
#include <QMainWindow>
#include <QApplication>
#ifdef _MSC_VER
#define NO_RETURN(method) \
    __declspec(noreturn) method;
#else
#define NO_RETURN(method) \
    method __attribute__((noreturn));
#endif

namespace Ui {
class equationeditor; //this is the property `objectName` from the previous step. They need to match
}


class equationeditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit equationeditor(QWidget *parent,
                            QString gDirTwoLevelUp,
                            CustomTextBrowser *b,
                            QString mode);
    ~equationeditor();
private:
   Ui::equationeditor* ui;
   TypesetEdit typeset_edit;
   QString save_path;
   QString gDirTwoLevelUp;
   CustomTextBrowser * curr_browser = nullptr;
   QString mode;

private slots:
   void on_actionNew_triggered();
   void on_actionLoad_triggered();
   void on_actionSave_triggered();
   void on_actionSave_As_triggered();
   void on_actionPrint_triggered();
   NO_RETURN(void on_actionExit_triggered())
   void on_actionUndo_triggered();
   void on_actionRedo_triggered();
   void on_actionLoad_Test_txt_triggered();
   void on_actionZoom_In_triggered();
   void on_actionZoom_Out_triggered();
   void on_actionReset_Zoom_triggered();
   void on_actionShow_Line_Numbers_toggled(bool show);
   void on_actionVanilla_triggered();
   void on_actionChalkboard_triggered();
   void on_actionCopy_as_PNG_triggered();
   void on_actionCopy_as_TeX_triggered();
   void on_actionCopy_as_Unicode_triggered();
   void enclosedMathBranButton(QString l, QString r);

   void on_actionInsert_Equation_triggered();

private:
    void load(QString filename);
    void loadPrompt();
    void save();
    void saveAs(QString save_path);
    void savePrompt();
    void printSvgPrompt();
};

#endif // EQUATIONEDITOR_H
