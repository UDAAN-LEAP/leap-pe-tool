#include "diacriticsview.h"
#include "ui_diacriticsview.h"

DiacriticsView::DiacriticsView(QWidget *parent) :
      QDialog(parent),
      ui(new Ui::DiacriticsView)
{
      ui->setupUi(this);
      //QString diString("A\nẠ ạ   Ȧ ȧ   Ä ä   Ȁ ȁ   Ā ā   Â â   Ǎ ǎ   Ã ã    \nḀ ḁ   Å å   Ăă   Ȃ ȃ   À à   A̲ a̲   Ặ ặ   Ả ả   \nǍ ǎ   Æ\n\nE\nĖ ė   Ë ë   É é   È è   Ê ê   Ě ě   Ẽ ẽ   Ĕ ĕ   \nẸ ẹ   Ệ ệ   Ḙ ḙ   Ḛ ḛ   Ế ế   Ē ē   Ẻ ẻ   Ȅ ȅ   \nE̋ e̋\n\nI\nÍ í   Ì ì    i̇́      i̇̀      i̇̃      Ï ï   Î î   Ĩ ĩ   \nĬ ĭ   Ǐ ǐ   Ī ī   Ỉ ỉ   Ȉ ȉ   I̋ i̋   Ȋ ȋ   Ị ị   \nᶖ   İ i\n\nO\nÓ ó   Ò ò   Ȯ ȯ   Ö ö   O͘ o͘   Ô ô   Ǒ ǒ   Ŏ ŏ   \nŌ ō   Ő ő   Õ õ   Ǫ ǫ   Ỏ ỏ   Ȍ ȍ   Ȏ ȏ  Ọ ọ\n\nU\nÚ ú   Ù ù   Ũ ũ   Ụ ụ   Ü ü   Ṳ ṳ   Ū ū   Û û   \nṶ ṷ   Ǔ ǔ   Ű ű   Ŭ ŭ   Ȗ ȗ   Ů ů   Ȕ ȕ\n\nB\nβ\nC\nĊ ċ   C̈ c̈   Ć ć   Ĉ ĉ   Č č   Ḉ ḉ   Ƈ ƈ  Ç ç\n\nD\nḊ ḋ   Ḍ ḍ   Ḏ ḏ   Ď ď   Ḑ ḑ    Ḓ ḓ   Ɗ ɗ   Ð đ   \nð   ᵭ   ᶁ   ᶑ   ȡ   ɖ\n\n\n\nF\nḞ ḟ   Ƒ ƒ   ᵮ   ᶂ\n\nG\nĠ ġ   Ḡ ḡ   Ǵ ǵ   Ĝ ĝ   Ǧ ǧ   Ğ ğ   Ǥ ǥ   Ģ ģ   Ɠ ɠ\n\nH\nḢ ḣ   Ḧ ḧ   Ĥ ĥ   Ȟ ȟ   Ħ ħ   Ḩ ḩ    Ⱨ ⱨ   ẖ ẖ   \nḤ ḥ   Ḫ ḫ\n\nJ\nĴ ĵ    ǰ    Ɉ ɉ    J̃ j̇̃\n\nK\nḰ ḱ   Ǩ ǩ   Ḳ ḳ   Ƙ ƙ   Ḵ ḵ   Ķ ķ   ᶄ   Ⱪ ⱪ\n\nL\nĹ ĺ   Ľ ľ   Ļ ļ   Ḷ ḷ   Ḹ ḹ   L̃ l̃   Ḽ ḽ   Ḻ ḻ \n\nM\nṀ ṁ   Ṃ ṃ   Ḿ ḿ   M̋ m̋   M̃ m̃    ᵯ   ᶆ\n\nN\nṄṅ   Ṇṇ Ńń   Ǹǹ   Ňň   Ññ   Ņņ    Ṋṋ   Ṉṉ   N̈n̈   Ɲɲ\n\n\n\nP\nṔ ṕ   Ṗ ṗ   Ᵽ ᵽ   Ƥ ƥ   P̃ p̃   ᵱ   ᶈ\n\nQ\nʠ   Ɋ   ɋ   q̃\n\nR\nŔ ŕ   Ɍ ɍ   Ř ř   Ŗ ŗ   Ṙ ṙ   Ȑ ȑ   Ȓ ȓ   Ṛ ṛ   \nṜ ṝ   Ṟ ṟ   Ɽ ɽ   R̃ r̃   ᶉ\n\nS\nŚ ś   Ṡ ṡ   Ṣ ṣ   Ṩ ṩ   S̈ s̈   ȿ\n\nT\nŤ ť   Ṫ ṫ   Ţ ţ   Ṭ ṭ   Ț ț   Ṱ ṱ   Ṯ ṯ   T̈ ẗ\n\nV\nṼ ṽ   Ṿ ṿ   Ʋ ʋ   ᶌ\n\nW\nẂ ẃ   Ẁ ẁ   Ŵ ŵ   Ẅ ẅ   Ẇ ẇ   Ẉ ẉ   ẘ\n\nX\nẌ ẍ   Ẋ ẋ   ᶍ\n\nY\nÝ ý   Ỳ ỳ   Ŷ ŷ   Ÿ ÿ   Ỹ ỹ   Ẏ ẏ   Ỵ ỵ   Ỷ ỷ   \nȲ ȳ\n\nZ\nŹ ź   Ẑ ẑ   Ž ž   Ż ż   Ẓ ẓ   Ẕ ẕ   Ⱬ ⱬ");
      //ui->textEdit->setText(diString);
      ui->textEdit->setReadOnly(true);
}

DiacriticsView::~DiacriticsView()
{
      delete ui;
}

void DiacriticsView::on_copyButton_clicked()
{
      ui->textEdit->copy();
}
