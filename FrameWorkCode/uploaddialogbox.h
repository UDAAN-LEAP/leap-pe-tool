#ifndef UPLOADDIALOGBOX_H
#define UPLOADDIALOGBOX_H

#include <QDialog>

namespace Ui {
class uploadDialogBox;
}

class uploadDialogBox : public QDialog
{
    Q_OBJECT

public:
    explicit uploadDialogBox(QMap<QString, QString> filteredGblReplacementMap, QVector<bool> stateOfReplaceInAllPages, QWidget *parent = nullptr);
    bool saveInCSVfile();
    ~uploadDialogBox();

private slots:
    void on_cancelButton_clicked();

    void on_okButton_clicked();

private:
    Ui::uploadDialogBox *ui;
    bool saveCSVfile = false;
};

#endif // UPLOADDIALOGBOX_H
