#ifndef SymbolsView_H
#define SymbolsView_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class SymbolsView;
}

class SymbolsView : public QDialog
{
    Q_OBJECT

public:
    explicit SymbolsView(QWidget *parent = 0);
    ~SymbolsView();

private slots:
    void on_copyButton_clicked();
    void tabChanged(int idx);

private:
    Ui::SymbolsView *ui;
    QTextEdit *currentTab;
};

#endif // SymbolsView_H
