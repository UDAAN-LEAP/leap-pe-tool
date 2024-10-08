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
    QMap<QPair<QString,QString>,QString> *changesCheckedInPreviewMap;
    bool clicked_applyButton();
    ~GlobalReplaceDialog();
signals:
    void fetchCheckedlist(QMap <QString, QString>,QVector<int> allPages);

private slots:
   // void on_cancelButton_clicked();
    void on_applyButton_clicked();
    void displayOriginalList(QVector <QString> replacedWords);
    void leftCheckBoxStateChanged(QListWidgetItem*);
    void rightCheckBoxStateChanged();
    void on_previewButton_clicked();
    void on_pushButton_clicked();
    void on_checkBox_clicked();
    void on_checkBox_2_clicked();

    void on_pushButton_2_clicked();

public slots:
    void highlightChecked(QListWidgetItem* item);
    QMap <QString, QString> getFilteredGlobalReplacementMap();
    QMap <QString, QString> uncheckedItemsList();
    void disableCheckboxes(int,QMap<QPair<QString,QString>,QString> *changesCheckedInPreviewMap);
    friend class MainWindow;

private:
    Ui::GlobalReplaceDialog *ui;
    QMap <QString, QString> filteredGlobalReplacementMap;
    QMap <QString, QString> uncheckedItemsListMap;
    QVector<QListWidgetItem *> rightPaneCheckboxes; // Addresses of checkboxes on right side
    QVector<int> leftPaneCheckboxesStates; // State of checkboxes on left side
    QVector<int> rightPaneCheckboxesStates; // State of checkboxes on right side
//    QCheckBox *box;
//    QVBoxLayout *vbox = new QVBoxLayout;
    bool applyButtonIsClicked = false;

};

#endif // GLOBALREPLACEDIALOG_H
