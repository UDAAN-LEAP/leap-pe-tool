#ifndef UNDOGLOBALREPLACE_H
#define UNDOGLOBALREPLACE_H

#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
class UndoGlobalReplace;
}

class UndoGlobalReplace : public QDialog
{
    Q_OBJECT

public:
    explicit UndoGlobalReplace(QMap<QString, QString> reversedGRMap, QWidget *parent = nullptr,QString mRole="", QString path="");
    ~UndoGlobalReplace();

private slots:
    void checkBoxStateChanged(QListWidgetItem*);
    void displayListForUndoOperation(QMap<QString, QString> reversedGRMap);

    void on_pushButton_clicked();

    void on_checkBox_clicked();

    void on_cancel_clicked();

    void on_applyButton_clicked();

public slots:
    void highlightChecked(QListWidgetItem*);

    QMap<QString, QString> getFinalUndoMap();

private:
    Ui::UndoGlobalReplace *ui;
    QMap <QString, QString> finalUndoMap;
    QString mRole;
    QString path;

};

#endif // UNDOGLOBALREPLACE_H
