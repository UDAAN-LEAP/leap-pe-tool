#ifndef GLOBALREPLACEDIALOG_H
#define GLOBALREPLACEDIALOG_H

#include <QDialog>
#include <QMap>
#include <QListWidgetItem>
namespace Ui {
class GlobalReplaceDialog;
}

class GlobalReplaceDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GlobalReplaceDialog(QVector <QString> replacedWords,QWidget *parent = nullptr);
    ~GlobalReplaceDialog();

private slots:
    void on_cancelButton_clicked();
    void displayOriginalList(QVector <QString> replacedWords);

public slots:
    bool on_applyButton_clicked();
    void highlightChecked(QListWidgetItem* item);
    QMap <QString, QString> getFilteredGlobalReplacementMap();

private:
    Ui::GlobalReplaceDialog *ui;
    QMap <QString, QString> filteredGlobalReplacementMap;
};

#endif // GLOBALREPLACEDIALOG_H
