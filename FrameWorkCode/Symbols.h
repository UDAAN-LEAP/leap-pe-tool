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
    ~SymbolsView();
    static SymbolsView* openSymbolTable(QWidget *);

public slots:
    void on_copyButton_clicked();
    void tabChanged(int idx);

private slots:


private:
    Ui::SymbolsView *ui;
    QTextEdit *currentTab;
    static SymbolsView *symbolsView;
    explicit SymbolsView(QWidget *parent = 0);

};

#endif // SymbolsView_H
