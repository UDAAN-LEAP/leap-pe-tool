#include "Symbols.h"
#include "ui_Symbols.h"

SymbolsView *SymbolsView::symbolsView = 0;

SymbolsView::SymbolsView(QWidget *parent) :
      QDialog(parent, Qt::WindowCloseButtonHint),
      ui(new Ui::SymbolsView)
{
    ui->setupUi(this);
    ui->MathematicalSymbols->setText(R"(∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏
∐ ∑ − ∓ ∔ ∕ ∖ ∗ ∘ ∙ √ ∛ ∜ ∝ ∞ ∟ ∠
∡ ∢ ∣ ∤ ∥ ∦ ∧ ∨ ∩ ∪ ∫ ∬ ∭ ∮ ∯ ∰
∱ ∲ ∳ ∴ ∵ ∶ ∷ ∸ ∹ ∺ ∻ ∼ ∽ ∾ ∿ ≀ ≁
≂ ≃ ≄ ≅ ≆ ≇ ≈ ≉ ≊ ≋ ≌ ≍ ≎ ≏ ≐
≑ ≒ ≓ ≔ ≕ ≖ ≗ ≘ ≙ ≚ ≛ ≜ ≝ ≞ ≟
≠ ≡ ≢ ≣ ≤ ≥ ≦ ≧ ≨ ≩ ≪ ≫ ≬ ≭ ≮ ≯
≰ ≱ ≲ ≳ ≴ ≵ ≶ ≷ ≸ ≹ ⊂ ⊃ ⊄ ⊅ ⊆ ⊇
⊈ ⊉ ⊊ ⊋ ⊌ ⊍ ⊎ ⊏ ⊐ ⊑ ⊒ ⊓ ⊔ ⊕ ⊖ ⊗
⊘ ⊙ ⊢ ⊣ ⊤ ⊥ ⊦ ⊧ ⊨ ⊩ ⊪ ⊫ ⊬ ⊭ ⊮ ⊯
⊻ ⊼ ⊽ ⊾ ⊿ ⋀ ⋁ ⋂ ⋃ ⋄ ⋅ ⋆ ⋇ ⋈ ⋉ ⋊
⋋ ⋌ ⋍ ⋎ ⋏ ⋐ ⋑ ⋒ ⋓ ⋔ ⋕ ⋖ ⋗ ⋘ ⋙
⋚ ⋛ ⋜ ⋝ ⋞ ⋟ ⋮ ⋯ ⋰ ⋱ ⋵ ⋶ ⋷ ⋸ ⋹
⋺ ⋻ ⋼ ⋽ ⋾ ⋿

⥢ ⥣ ⥤ ⥥ ⥦ ⥧ ⥨ ⥩ ⥪ ⥫ ⥬ ⥭ ⥮ ⥯

𝛣 𝛤 𝛥 𝛦 𝛧 𝛨 𝛩 𝛪 𝛫 𝛬 𝛭 𝛮 𝛯 𝛰 𝛱 𝛲 𝛳 𝛴
𝛵 𝛶 𝛷 𝛸 𝛹 𝛺 𝛻 𝛼 𝛽 𝛾 𝛿 𝜀 𝜁 𝜂 𝜃 𝜄 𝜅 𝜆 𝜇 𝜈
𝜉 𝜊 𝜋 𝜌 𝜍 𝜎 𝜏 𝜐 𝜑 𝜒 𝜓 𝜔 𝜕 𝜖 𝜗 𝜘 𝜙 𝜚 𝜛
℉ ℃
)" );    
    
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
