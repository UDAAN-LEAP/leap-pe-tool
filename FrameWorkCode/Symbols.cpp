#include "Symbols.h"
#include "ui_Symbols.h"

SymbolsView::SymbolsView(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::SymbolsView)
{
    setWindowTitle("Special Symbols");
    currentTab = ui->Diacritics;
    connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabchanged(int)));
    ui->setupUi(this);
}
 void SymbolsView::tabchanged(int idx)
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
