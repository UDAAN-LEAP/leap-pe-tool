/*
 * It shows the table for various symbols
 */
#include "Symbols.h"
#include "ui_Symbols.h"

/*!
 * \brief SymbolsView::symbolsView
 */
SymbolsView *SymbolsView::symbolsView = 0;

/*!
 * \brief SymbolsView::SymbolsView
 * \param parent
 */
SymbolsView::SymbolsView(QWidget *parent) : QDialog(parent, Qt::WindowCloseButtonHint), ui(new Ui::SymbolsView)
{
    ui->setupUi(this);
    ui->MathematicalSymbols->setText(
        R"(𝑥 𝑦 𝑧 x̄ ȳ z̄
∀ ∁ ∂ ∃ ∄ ∅ ∆ ∇ ∈ ∉ ∊ ∋ ∌ ∍ ∎ ∏
∐ ∑ − ± ∓ ∔ ∕ ∖ ∗ ∘ ∙ √ ∛ ∜ ∝ ∞ ∟ ∠
∡ ∢ ∣ ∤ ∥ ∦ ∧ ∨ ∩ ∪ ∫ ∬ ∭ ∮ ∯ ∰
∱ ∲ ∳ ∴ ∵ ∶ ∷ ∸ ∹ ∺ ∻ ÷ ∼ ∽ ∾ ∿ ≀
≁ ≂ ≃ ≄ ≅ ≆ ≇ ≈ ≉ ≊ ≋ ≌ ≍ ≎ ≏ ≐
≑ ≒ ≓ ≔ ≕ ≖ ≗ ≘ ≙ ≚ ≛ ≜ ≝ ≞ ≟
≠ ≡ ≢ ≣ ≤ ≥ ≦ ≧ ≨ ≩ ≪ ≫ ≬ ≭ ≮ ≯
≰ ≱ ≲ ≳ ≴ ≵ ≶ ≷ ≸ ≹ ⊂ ⊃ ⊄ ⊅ ⊆ ⊇
⊈ ⊉ ⊊ ⊋ ⊌ ⊍ ⊎ ⊏ ⊐ ⊑ ⊒ ⊓ ⊔ ⊕ ⊖ ⊗
⊘ ⊙ ⊢ ⊣ ⊤ ⊥ ⊦ ⊧ ⊨ ⊩ ⊪ ⊫ ⊬ ⊭ ⊮ ⊯
⊻ ⊼ ⊽ ⊾ ⊿ ⋀ ⋁ ⋂ ⋃ ⋄ ⋅ ⋆ ⋇ ⋈ ⋉ ⋊
⋋ ⋌ ⋍ ⋎ ⋏ ⋐ ⋑ ⋒ ⋓ ⋔ ⋕ ⋖ ⋗ ⋘ ⋙
⋚ ⋛ ⋜ ⋝ ⋞ ⋟ ⋮ ⋯ ⋰ ⋱ ⋵ ⋶ ⋷ ⋸ ⋹
⋺ ⋻ ⋼ ⋽ ⋾ ⋿ ¬ ∝ ×

⥢ ⥣ ⥤ ⥥ ⥦ ⥧ ⥨ ⥩ ⥪ ⥫ ⥬ ⥭ ⥮ ⥯
⇒ ⇔ ↔ ← ↑ → ↓

𝛣 𝛤 𝛥 𝛦 𝛧 𝛨 𝛩 𝛪 𝛫 𝛬 𝛭 𝛮 𝛯 𝛰 𝛱 𝛲 𝛳 𝛴
𝛵 𝛶 𝛷 𝛸 𝛹 𝛺 𝛻 𝛼 𝛽 𝛾 𝛿 𝜀 𝜁 𝜂 𝜃 𝜄 𝜅 𝜆 𝜇 𝜈
𝜉 𝜊 𝜋 𝜌 𝜍 𝜎 𝜏 𝜐 𝜑 𝜒 𝜓 𝜔 𝜕 𝜖 𝜗 𝜘 𝜙 𝜚 𝜛
℉ ℃ ⊗ ⊖ ∀ ∯ ∮ ∰
)"
);
    ui->SpecialCharacters->setText(
    R"(¶  ¦  Ȝ  ȝ  —  –  ‑  °  ·  † ‡ § ऽ) ❀ ✿ ✽ ꕥ 💮"
);

    R"(A
Ạ ạ   Ȧ ȧ   Ä ä   Ȁ ȁ   Ā ā   Â â   Ǎ ǎ   Ã ã    
Å å   Ḁ ḁ   Ăă   Ȃ ȃ   À à   A̲ a̲   Ặ ặ   Ả ả   
Ǎ ǎ   Æ ӕ

B
β

C
Ċ ċ   C̈ c̈   Ć ć   Ĉ ĉ   Č č   Ḉ ḉ   Ƈ ƈ  Ç ç

D
Ḋ ḋ   Ḍ ḍ   Ḏ ḏ   Ď ď   Ḑ ḑ    Ḓ ḓ   Ɗ ɗ   Ð đ

E
Ė ė   Ë ë   É é   È è   Ê ê   Ě ě   Ẽ ẽ   Ĕ ĕ   
Ế ế   Ē ē   Ẻ ẻ   Ȅ ȅ   Ẹ ẹ   Ệ ệ   Ḙ ḙ   Ḛ ḛ      
E̋ e̋

F
Ḟ ḟ   Ƒ ƒ

G
Ġ ġ   Ḡ ḡ   Ǵ ǵ   Ĝ ĝ   Ǧ ǧ   Ğ ğ   Ǥ ǥ   Ģ ģ   Ɠ ɠ

H
Ḣ ḣ   Ḧ ḧ   Ĥ ĥ   Ȟ ȟ   Ħ ħ   Ḩ ḩ    Ⱨ ⱨ   ẖ ẖ   
Ḥ ḥ   Ḫ ḫ

I
Í í   Ì ì    i̇́      i̇̀     i̇̃   Ï ï   Î î   Ĩ ĩ   
Ĭ ĭ   Ǐ ǐ   Ī ī   Ỉ ỉ   Ȉ ȉ   I̋ i̋   Ȋ ȋ   Ị ị   
ᶖ   İ i

J
Ĵ ĵ    ǰ    Ɉ ɉ    J̃ j̇̃

K
Ḱ ḱ   Ǩ ǩ   Ḳ ḳ   Ƙ ƙ   Ḵ ḵ   Ķ ķ   ᶄ   Ⱪ ⱪ

L
Ĺ ĺ   Ľ ľ   Ļ ļ   Ḷ ḷ   Ḹ ḹ   L̃ l̃   Ḽ ḽ   Ḻ ḻ 

M
Ṁ ṁ   Ṃ ṃ   Ḿ ḿ   M̋ m̋   M̃ m̃    ᵯ   ᶆ

N
Ṅṅ   Ṇṇ Ńń   Ǹǹ   Ňň   Ññ   Ņņ    Ṋṋ   Ṉṉ   N̈n̈   Ɲɲ

O
Ó ó   Ò ò   Ȯ ȯ   Ö ö   O͘ o͘   Ô ô   Ǒ ǒ   Ŏ ŏ   
Ō ō   Ő ő   Õ õ   Ǫ ǫ   Ỏ ỏ   Ȍ ȍ   Ȏ ȏ  Ọ ọ

P
Ṕ ṕ   Ṗ ṗ   Ᵽ ᵽ   Ƥ ƥ   P̃ p̃   ᵱ   ᶈ

Q
ʠ   Ɋ   ɋ   q̃

R
Ŕ ŕ   Ɍ ɍ   Ř ř   Ŗ ŗ   Ṙ ṙ   Ȑ ȑ   Ȓ ȓ   Ṛ ṛ   
Ṝ ṝ   Ṟ ṟ   Ɽ ɽ   R̃ r̃   ᶉ

S
Ś ś   Ṡ ṡ   Ṣ ṣ   Ṩ ṩ   S̈ s̈   ȿ

T
Ť ť   Ṫ ṫ   Ţ ţ   Ṭ ṭ   Ț ț   Ṱ ṱ   Ṯ ṯ   T̈ ẗ

U
Ú ú   Ù ù   Ũ ũ   Ụ ụ   Ü ü   Ṳ ṳ   Ū ū   Û û   
Ṷ ṷ   Ǔ ǔ   Ű ű   Ŭ ŭ   Ȗ ȗ   Ů ů   Ȕ ȕ

V
Ṽ ṽ   Ṿ ṿ   Ʋ ʋ   ᶌ

W
Ẃ ẃ   Ẁ ẁ   Ŵ ŵ   Ẅ ẅ   Ẇ ẇ   Ẉ ẉ   ẘ

X
Ẍ ẍ   Ẋ ẋ   ᶍ

Y
Ý ý   Ỳ ỳ   Ŷ ŷ   Ÿ ÿ   Ỹ ỹ   Ẏ ẏ   Ỵ ỵ   Ỷ ỷ   
Ȳ ȳ

Z
Ź ź   Ẑ ẑ   Ž ž   Ż ż   Ẓ ẓ   Ẕ ẕ   Ⱬ ⱬ)"
);
    setWindowTitle("Special Symbols");
    currentTab = ui->Diacritics;
    bool b = connect(ui->tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));
}
/*!
 * \brief SymbolsView::tabChanged
 * \param idx
 */
void SymbolsView::tabChanged(int idx)
 {
    QWidget *widget = ui->tabWidget->widget(idx);
    QList<QTextEdit*> allTextEdits = widget->findChildren<QTextEdit*>();
    if(allTextEdits.count()!= 1)
      return;
    currentTab = allTextEdits[0];
 }

 /*!
 * \brief SymbolsView::~SymbolsView
 */
SymbolsView::~SymbolsView()
{
    delete ui;
}

/*!
 * \brief SymbolsView::on_copyButton_clicked
 */
void SymbolsView::on_copyButton_clicked()
{
      currentTab->copy();
}

/*!
 * \brief SymbolsView::openSymbolTable
 * \param parent
 * \return
 * opens symbol table
 */
SymbolsView* SymbolsView::openSymbolTable(QWidget *parent)
{
    if (symbolsView)
    {
        return symbolsView;
    }

    symbolsView = new SymbolsView(parent);
    return symbolsView;
}
