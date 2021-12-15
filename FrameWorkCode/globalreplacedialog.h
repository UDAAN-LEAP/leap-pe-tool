#ifndef GLOBALREPLACEDIALOG_H
#define GLOBALREPLACEDIALOG_H

#include <QDialog>
#include <QMap>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QGroupBox>
#include <QVBoxLayout>

namespace Ui {
class GlobalReplaceDialog;
}

class GlobalReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GlobalReplaceDialog(QVector <QString> replacedWords,QWidget *parent = nullptr);
    QVector<int> getStatesOfCheckboxes();
    ~GlobalReplaceDialog();

private slots:
    void on_cancelButton_clicked();
    void displayOriginalList(QVector <QString> replacedWords);


    void on_pushButton_clicked();
    void leftCheckBoxStateChanged(QListWidgetItem*);

public slots:
    bool on_applyButton_clicked();
    void highlightChecked(QListWidgetItem* item);
    QMap <QString, QString> getFilteredGlobalReplacementMap();

private:
    Ui::GlobalReplaceDialog *ui;
    QMap <QString, QString> filteredGlobalReplacementMap;
    QVector<QCheckBox *> replaceInAllFiles_Checkboxes; // Addresses of checkboxes on right side
    QVector<int> wordSelection_CheckboxesState; // State of checkboxes on left side
    QCheckBox *box;
    QVBoxLayout *vbox = new QVBoxLayout;
};

#endif // GLOBALREPLACEDIALOG_H
