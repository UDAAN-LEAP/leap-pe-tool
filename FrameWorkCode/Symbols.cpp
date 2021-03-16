#include "Symbols.h"
#include "ui_Symbols.h"

SymbolsView *SymbolsView::symbolsView = 0;

SymbolsView::SymbolsView(QWidget *parent) :
      QDialog(parent, Qt::WindowCloseButtonHint),
      ui(new Ui::SymbolsView)
{
    ui->setupUi(this);
    setWindowTitle("Special Symbols");
    currentTab = ui->Diacritics;
    bool b = connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
}
 void SymbolsView::tabChanged(int idx)
 {
    QWidget *widget = ui->tabWidget->widget(idx);
    QList<QTextEdit*> allTextEdits = widget->findChildren<QTextEdit*>();
    if(allTextEdits.count()!= 1)
      return;
    currentTab = allTextEdits[0];
 }
SymbolsView::~SymbolsView()
{
    delete ui;
}

void SymbolsView::on_copyButton_clicked()
{
      currentTab->copy();
}

SymbolsView* SymbolsView::openSymbolTable(QWidget *parent) {
    if (symbolsView) {
        return symbolsView;
    }

    symbolsView = new SymbolsView(parent);
    return symbolsView;
}
