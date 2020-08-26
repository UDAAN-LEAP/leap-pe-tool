#include "Symbols.h"
#include "ui_Symbols.h"

SymbolsView::SymbolsView(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::SymbolsView)
{
    ui->setupUi(this);
    setWindowTitle("Special Symbols");
    currentTab = ui->Diacritics;
    bool b = connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));

}
 void SymbolsView::tabChanged(int idx)
 {
     currentTab = (QTextEdit*)ui->tabWidget->widget(idx);
 }
SymbolsView::~SymbolsView()
{
      delete ui;
}

void SymbolsView::on_copyButton_clicked()
{
      currentTab->copy();
}
