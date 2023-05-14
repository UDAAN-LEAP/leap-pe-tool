#ifndef SymbolsView_H
#define SymbolsView_H

#include "customtextbrowser.h"
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
    static SymbolsView* openSymbolTable(QWidget *, CustomTextBrowser *);

public slots:
    void on_copyButton_clicked();
    void tabChanged(int idx);

private slots:
bool eventFilter(QObject *obj, QEvent *event);

private:
    Ui::SymbolsView *ui;
    QTextEdit *currentTab;
    static SymbolsView *symbolsView;
    explicit SymbolsView(QWidget *parent = 0, CustomTextBrowser *curr_brow=0);
    CustomTextBrowser *cust_brow;

};

#endif // SymbolsView_H
