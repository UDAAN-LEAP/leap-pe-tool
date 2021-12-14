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
    explicit UndoGlobalReplace(QMap<QString, QString> reversedGRMap, QWidget *parent = nullptr);
    ~UndoGlobalReplace();

private slots:
    void displayListForUndoOperation(QMap<QString, QString> reversedGRMap);

    void on_cancelButton_clicked();

public slots:
    void highlightChecked(QListWidgetItem*);

    bool on_applyButton_clicked();

    QMap<QString, QString> getFinalUndoMap();

private:
    Ui::UndoGlobalReplace *ui;
    QMap <QString, QString> finalUndoMap;
};

#endif // UNDOGLOBALREPLACE_H
