#include "equationeditor.h"
#include "qdebug.h"
#include "qpushbutton.h"
#include "ui_equationeditor.h"

#include <QClipboard>
#include <QComboBox>
#include <QFile>
#include <QFileDialog>
#include <QFontDatabase>
#include <QLabel>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QtMath>
#include <QtSvg/QSvgGenerator>
#include <QMathBranLatex.h>
#include <QMathBranUnicode.h>
#include <QDockWidget>
#include <QStandardPaths>
#include <QProcess>
#include <QTextCursor>

/*!
 * \fn equationeditor::equationeditor
 * \brief Equation editor
 * \param parent
 * \param gDirTwoLevelUp
 * \param b
 * \param mode
 * \brief If mode is equal to 0, then new equation is typed and inserted. If the mode contains file path, then the previous equation is edited(Whose path is passed here).
 */
equationeditor::equationeditor(QWidget *parent,
                               QString gDirTwoLevelUp,
                               CustomTextBrowser *b,
                               QString mode):
    QMainWindow(parent),
    ui(new Ui::equationeditor){
    ui->setupUi(this);
    setWindowTitle("Equation Editor");
    this->gDirTwoLevelUp = gDirTwoLevelUp;
    this->curr_browser = b;
    this->mode = mode;
//    qDebug()<<"Dir:"<<currentFileDirectory<<"GLevel:"<<gDirTwoLevelUp;

    TypesetToolbar* toolbar = new TypesetToolbar(this);
    connect(toolbar, SIGNAL(clickSymbol(QString)), &typeset_edit, SLOT(insertPlainText(const QString&)));
    connect(toolbar, SIGNAL(clickMathBran(QString)), &typeset_edit, SLOT(insertMathBran(const QString&)));
    connect(toolbar, SIGNAL(clickEnclosingMathBran(QString, QString)),
            this, SLOT(enclosedMathBranButton(QString, QString)));
    addToolBar(toolbar);
    toolbar->setAllowedAreas(Qt::ToolBarArea());
    ui->menuBar->setParent(toolbar);
    setCentralWidget(&typeset_edit);
    toolbar->setStyleSheet("background-color:white; color:black;");
    centralWidget()->setStyleSheet("background-color:white; color:black;");
    //disablng line numbers
    typeset_edit.showLineNumbers(false);

    #ifdef __EMSCRIPTEN__
    //WASM cannot access clipboard without ctrl-c/v/x press; GUI buttons don't work
    ui->actionCopy->setVisible(false);
    ui->actionCut->setVisible(false);
    ui->actionCut->setEnabled(false);
    ui->actionPaste->setVisible(false);
    ui->actionCopy_as_PNG->setVisible(false);
    ui->actionCopy_as_TeX->setVisible(false);
    ui->actionCopy_as_Unicode->setVisible(false);

    //Extra setup for WASM
    QLabel* link = new QLabel(this);
    link->setText("<a href=\"https://github.com/JohnDTill/YAWYSIWYGEE\">https://github.com/JohnDTill/YAWYSIWYGEE</a>");
    link->setOpenExternalLinks(true);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(link);
    layout->addWidget(&typeset_edit);
    QWidget* container = new QWidget(this);
    container->setLayout(layout);
    setCentralWidget(container);
    #else
    connect(ui->actionCut, SIGNAL(triggered()), &typeset_edit, SLOT(cut()));
    connect(ui->actionCopy, SIGNAL(triggered()), &typeset_edit, SLOT(copy()));
    connect(ui->actionPaste, SIGNAL(triggered()), &typeset_edit, SLOT(paste()));
    #endif

    connect(&typeset_edit, SIGNAL(undoAvailable(bool)), ui->actionUndo, SLOT(setEnabled(bool)));
    connect(&typeset_edit, SIGNAL(redoAvailable(bool)), ui->actionRedo, SLOT(setEnabled(bool)));

    //open equation for edit
    if(mode.compare("0")){
        load(mode);
    }
}

/*!
 * \fn equationeditor::~equationeditor
 */
equationeditor::~equationeditor() {
   delete ui;
}

/*!
 * \fn equationeditor::on_actionNew_triggered
 * \brief It clears the typeset_edit and path.
 */
void equationeditor::on_actionNew_triggered(){
    typeset_edit.clear();
    save_path.clear();
    setWindowTitle("Equation Editor");
}

/*!
 * \fn equationeditor::on_actionLoad_triggered
 * \brief Loads new file in typeset_edit.
 */
void equationeditor::on_actionLoad_triggered(){
    loadPrompt();
}

/*!
 * \fn equationeditor::on_actionSave_triggered
 * \brief calls save() function when save button is clicked.
 */
void equationeditor::on_actionSave_triggered(){
    save();
}

/*!
 * \fn equationeditor::on_actionSave_As_triggered
 * \brief When user clicks on "save as" button, savePrompt() function is called.
 */
void equationeditor::on_actionSave_As_triggered(){
    savePrompt();
}

/*!
 * \fn equationeditor::on_actionPrint_triggered
 * \brief When user clicks on print button, the current content written in typeset_edit is saved as svg.
 */
void equationeditor::on_actionPrint_triggered(){
    printSvgPrompt();
}

/*!
 * \fn equationeditor::on_actionExit_triggered
 * \brief Closes equation editor
 */
void equationeditor::on_actionExit_triggered(){
    exit(0);
}

/*!
 * \fn equationeditor::on_actionUndo_triggered
 * \brief This function is called on udo operation.
 */
void equationeditor::on_actionUndo_triggered(){
    typeset_edit.undo();
}

/*!
 * \fn equationeditor::on_actionRedo_triggered
 * \brief This function is called on redo operation
 */
void equationeditor::on_actionRedo_triggered(){
    typeset_edit.redo();
    typeset_edit.clearErrors();
}

/*!
 * \fn equationeditor::on_actionLoad_Test_txt_triggered
 * \brief If user wants to load a test project in equation editor, this function is called when clicked on "load test"
 */
void equationeditor::on_actionLoad_Test_txt_triggered(){
    load(":/test.txt");
    save_path.clear();
}

/*!
 * \fn equationeditor::on_actionZoom_In_triggered
 * \brief This function zooms in the typeset_edit contents
 */
void equationeditor::on_actionZoom_In_triggered(){
    typeset_edit.zoomIn();
}

/*!
 * \fn equationeditor::on_actionZoom_Out_triggered
 * \brief This function zooms out the typeset_edit contents
 */
void equationeditor::on_actionZoom_Out_triggered(){
    typeset_edit.zoomOut();
}

/*!
 * \fn equationeditor::on_actionReset_Zoom_triggered
 * \brief This function resets the zoom level to default zoom level in the typeset_edit window
 */
void equationeditor::on_actionReset_Zoom_triggered(){
    typeset_edit.zoomReset();
}

/*!
 * \fn equationeditor::on_actionShow_Line_Numbers_toggled
 * \param show
 * \brief There is an option to show line numbers when we type the equation in an equation editor. User can turn on/off the line numbers by using this option.
 */
void equationeditor::on_actionShow_Line_Numbers_toggled(bool show){
    typeset_edit.showLineNumbers(show);
}

/*!
 * \fn equationeditor::on_actionVanilla_triggered
 * \brief This function changes the theme of equation ediotr.
 * \brief Two themes are available - Vanilla and Chalkboard
 */
void equationeditor::on_actionVanilla_triggered(){
    ui->actionVanilla->setChecked(true);
    ui->actionChalkboard->setChecked(false);

    typeset_edit.setPalette(palette());
}

/*!
 * \fn equationeditor::on_actionChalkboard_triggered
 * \brie Sets the theme to chalkboard.
 */
void equationeditor::on_actionChalkboard_triggered(){
    ui->actionVanilla->setChecked(false);
    ui->actionChalkboard->setChecked(true);

    QPalette chalkboard = palette();
    chalkboard.setColor(QPalette::All, QPalette::Base, QColor::fromRgb(70,133,87));
    chalkboard.setColor(QPalette::All, QPalette::Text, Qt::white);
    chalkboard.setColor(QPalette::All, QPalette::Mid, Qt::white);
    chalkboard.setColor(QPalette::All, QPalette::Window, QColor::fromRgb(70,133,87));

    typeset_edit.setPalette(chalkboard);
}

/*!
 * \fn equationeditor::on_actionCopy_as_PNG_triggered
 * \brief This function copies the typeset_edit contents as png image.
 */
void equationeditor::on_actionCopy_as_PNG_triggered(){
    typeset_edit.copyPng();
}

/*!
 * \fn equationeditor::load
 * \param filename
 * \brief This function opens, renders and shows an equation in editor from selected file.
 * \brief File should contain a valid MathBran code.
 */
void equationeditor::load(QString filename){
    QFile file(filename);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", "Could not open \"" + filename + "\" to read.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QTextStream in(&file);
    in.setCodec("UTF-8");

    QString math_bran = in.readAll();
    if(!MathBran::isWellFormed(math_bran)){
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", "\"" + filename + "\" contains invalid MathBran code.");
        messageBox.setFixedSize(500,200);
        return;
    }
    typeset_edit.setMathBran(math_bran);

    QFileInfo file_info(file);
    typeset_edit.setDocumentTitle(file_info.fileName());
    setWindowTitle("Equation Editor - \"" + file_info.fileName() + '"');
    save_path = filename;
}

/*!
 * \fn equationeditor::loadPrompt
 * \brief This function shows the dialog to select a file.
 */
void equationeditor::loadPrompt(){
    QString path = QFileDialog::getOpenFileName(nullptr, tr("Load File"), "./", tr("Text (*.txt)"));
    if(path.isEmpty()) return;
    else load(path);
}

/*!
 * \fn equationeditor::save
 * \brief If save path is empty, savePrompt() function is called, else saveAs() function is called with path.
 */
void equationeditor::save(){
    if(save_path.isEmpty()) savePrompt();
    else saveAs(save_path);
}

/*!
 * \fn equationeditor::saveAs
 * \param save_path
 * \brief This function saves the file at specified location.
 * \brief File contents are stored in MathBran notation.
 */
void equationeditor::saveAs(QString save_path){
    QFile file(save_path);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox messageBox;
        messageBox.critical(nullptr, "Error", "Could not open \"" + save_path + "\" to write.");
        messageBox.setFixedSize(500,200);
        return;
    }

    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << typeset_edit.toMathBran();

    QFileInfo file_info(file);
    typeset_edit.setDocumentTitle(file_info.fileName());
    setWindowTitle("YAWYSIWYGEE - \"" + file_info.fileName() + '"');
    this->save_path = save_path;
}

/*!
 * \fn equationeditor::savePrompt
 * \brief Shows the pop up dialog to user to save the file at desired location.
 */
void equationeditor::savePrompt(){
    QString title = typeset_edit.documentTitle();
    QString prompt_name = title.isEmpty() ? "untitled.txt" : typeset_edit.documentTitle();
    QString file_name = QFileDialog::getSaveFileName(nullptr, tr("Save File"),
                                prompt_name,
                                tr("Text (*.txt)"));

    if(!file_name.isEmpty()) saveAs(file_name);
}

/*!
 * \fn equationeditor::printSvgPrompt
 * \brief This functions generates the svg of typeset_edit contents and saves at selected location.
 * \brief QSvgGenerator is used to generate svg file.
 */
void equationeditor::printSvgPrompt(){
    QString title = typeset_edit.documentTitle();
    QString prompt_name = title.isEmpty() ?
                          "untitled.svg" :
                          typeset_edit.documentTitle().split('.').front() + ".svg";
    QString file_name = QFileDialog::getSaveFileName(nullptr, tr("Export PDF"),
                                prompt_name,
                                tr("SVG (*.svg)"));

    if(file_name.isEmpty()) return;

    QSvgGenerator svgGen;
    svgGen.setFileName(file_name);

    typeset_edit.printSvg(&svgGen);
}

/*!
 * \fn equationeditor::on_actionCopy_as_TeX_triggered
 * \brief This copies the equation as Latex code which can pasted by user at some other place.
 */
void equationeditor::on_actionCopy_as_TeX_triggered(){
    QString math_bran = typeset_edit.selectedMathBran();
    if(!math_bran.isEmpty()) QGuiApplication::clipboard()->setText(MathBran::toLatex(math_bran));
}

/*!
 * \fn equationeditor::on_actionCopy_as_Unicode_triggered
 * \brief This copies the equation as Unicode code which can pasted by user at some other place.
 */
void equationeditor::on_actionCopy_as_Unicode_triggered(){
    QString math_bran = typeset_edit.selectedMathBran();
    if(math_bran.isEmpty()) return;

    if(!MathBran::canConvertToUnicode(math_bran)){
        QMessageBox messageBox;
        messageBox.warning(nullptr, "Warning", "Selected text cannot be converted to unicode.");
        messageBox.setFixedSize(500, 200);
        return;
    }

    QGuiApplication::clipboard()->setText(MathBran::toUnicode(math_bran));
}

/*!
 * \fn equationeditor::enclosedMathBranButton
 * \param l
 * \param r
 * \brief Inserts the provided strings in the tpeset_edit and renders it as a valid mathematical equation.
 */
void equationeditor::enclosedMathBranButton(QString l, QString r){
    QString selected = typeset_edit.selectedMathBran();
    if(selected.contains('\n')) typeset_edit.insertMathBran(l + r);
    else typeset_edit.insertMathBran(l + selected + r);
}

/*!
 * \fn equationeditor::on_actionInsert_Equation_triggered
 * \brief Inserts the equation in html file at current cursor position.
 * \details This functions converts the equation editor contents into a png image and inserts this image in browser at cursor position.
 * \details This inserted png image is also stored locally inside the project directory, within Equations_ folder.
 * \details Besides the png image, Latex code and MathBran code is also stored in separate files.
 * \details For one equation, three files are stored locally. In our udaan post editing tool, we show equations as png images but in html files, it is stored as Latex code within $$ $$ tags
 * \details which can be rendered by MathJax library in any browser. MathBran files are useful to edit already inserted images because our equation editor can render the MathBran notation only.
 */
void equationeditor::on_actionInsert_Equation_triggered()
{
    if(!QDir(gDirTwoLevelUp+"/Equations_").exists())
            QDir().mkdir(gDirTwoLevelUp+"/Equations_");

    QDir dir(gDirTwoLevelUp+"/Equations_");
    QString count = QString::number((dir.count()-1)/3 +1);
    QString file_name = gDirTwoLevelUp+"/Equations_/"+count+".png";
    typeset_edit.copyPng(2);
    QImage img = QGuiApplication::clipboard()->image();
    img.save(file_name);

    QString math_bran = typeset_edit.selectedMathBran();
    if(!math_bran.isEmpty()) QGuiApplication::clipboard()->setText(MathBran::toLatex(math_bran));
//    QString cnt = QString::number((dir.count()-1)/2 +1);
    QFile file(gDirTwoLevelUp+"/Equations_/"+count+".tex");
    file.open(QIODevice::WriteOnly);
    QTextStream in(&file);
    in.setCodec("UTF-8");
    in<<QGuiApplication::clipboard()->text();
    file.flush();
    file.close();
    //Save Mathbran notation file which will be useful in editing equations
    QFile f(gDirTwoLevelUp+"/Equations_/"+count+".txt");

    if(!f.open(QIODevice::WriteOnly | QIODevice::Text)){
        qDebug()<<"Can't open the file to save Mathbran notation!";
        return;
    }

    QTextStream out(&f);
    out.setCodec("UTF-8");
    out << typeset_edit.toMathBran();
    f.flush();
    f.close();

    //Insert equation png at cursor position
    QString filename = gDirTwoLevelUp+"/Equations_/"+count+".png";
    QString html = "<img src=\""+filename+"\">";
    QTextCursor cursor = curr_browser->textCursor();
    cursor.insertHtml(html);

    equationeditor::close();
}

