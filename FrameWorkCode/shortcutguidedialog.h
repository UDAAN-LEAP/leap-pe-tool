
#ifndef SHORTCUTGUIDEDIALOG_H
#define SHORTCUTGUIDEDIALOG_H

#include <QDialog>

namespace Ui {
class ShortcutGuideDialog;
}

class ShortcutGuideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShortcutGuideDialog(QWidget *parent = nullptr);
    ~ShortcutGuideDialog();

private:
    Ui::ShortcutGuideDialog *ui;
    QString list =  "<h1 >Udaan PE Tool - Shortcut Guide</h1>"
            "<h4>1. Open a project</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + O</strong> and select the project.xml file from the project folder to open the project.</li>"
            "</ul>"
            "<h4>2. Save a File</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + S</strong> to save the file.</li>"
            "</ul>"
            "<h4>3. Open a new tab</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + N</strong> to open a new tab in the window.</li>"
            "</ul>"
            "<h4>4. Save As</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Shift + S</strong> to save the file as a different copy with a different name and/or different location.</li>"
            "</ul>"
            "<h4>5. Navigate between pages</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Shift + R</strong> to navigate through the next page, <strong>Ctrl + Shift + L</strong> to navigate to the previous page.</li>"
            "</ul>"
            "<h4>6. Undo &amp; Redo</h4>"
            "<ul>"
            "<li>Press  <strong>Ctrl + Z</strong> to undo the changes and <strong>Ctrl + Shift + Z</strong> to redo the changes.</li>"
            "</ul>"
            "<h4>7. Find &amp; Replace</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + F</strong> to find and/or replace text.</li>"
            "</ul>"
            "<h4>8. Highlight</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + H</strong> to highlight the selected text.</li>"
            "</ul>"
            "<h4 >9. Spell Check</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + C</strong> to perform Spell Check.</li>"
            "</ul>"
            "<h4>10. Convert text to Devanagari</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + D</strong> to convert selected text to devanagari format.</li>"
            "</ul>"
            "<h4>11. Text Formatting</h4>"
            "<ul>"
            "<li>Bold: Press <strong>Ctrl + B</strong> to make selected text <strong>Bold</strong></li>"
            "<li>Italic: Press <strong>Ctrl + I</strong> to make text <em>Italic</em></li>"
            "<li>Subscript: Press <strong>Ctrl + `</strong>  to make text subscripted</li>"
            "<li>Superscript: Press <strong>Ctrl + Shift + `</strong> to make text superscript</li>"
            "<li>Tab Space: Press <strong>Ctrl + T</strong> to add tab space</li>"
            "</ul>"
            "<h4>12. Devanagari to SLP</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + G</strong> to Convert devanagari to roman letters as mapped in SLP Guide</li>"
            "</ul>"
            "<h4>13. Font Properties</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Shift + A</strong> to see current Font properties</li>"
            "</ul>"
            "<h4>14. Equation</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + E</strong> to open equation editor to write an equation.</li>"
            "</ul>"
            "<h4>15. Edit Equation</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Shift + E</strong> to edit teh selected Equation</li>"
            "</ul>"
            "<h4>16. Paste</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Shift + V</strong> to paste the text/image</li>"
            "</ul>"
            "<h4>17. Exit</h4>"
            "<ul>"
            "<li>Press <strong>Ctrl + Q</strong> to exit the Udaan PE Tool</li>"
            "</ul>";
};

#endif // SHORTCUTGUIDEDIALOG_H
