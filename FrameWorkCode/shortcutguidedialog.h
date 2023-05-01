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
    QString list =  "# Udaan PE Tool - Shortcut Guide\n"
                    "----\n"
                    "#### 1. Open a project\n"
                    "- Press **Ctrl + O** and select the project.xml file from the project folder to open the project.\n"
                    "#### 2. Save a File\n"
                    "- Press **Ctrl + S** to save the file.\n"
                    "#### 3. Open a new tab\n"
                    "- Press **Ctrl + N** to open a new tab in the window.\n"
                    "#### 4. Save As\n"
                    "- Press **Ctrl + Shift + S** to save the file as a different copy with a different name and/or different location.\n"
                    "#### 5. Navigate between pages\n"
                    "- Press **Ctrl + Shift + R** to navigate through the next page, **Ctrl + Shift + L** to navigate to the previous page.\n"
                    "#### 6. Undo & Redo\n"
                    "- Press  **Ctrl + Z** to undo the changes and **Ctrl + Shift + Z** to redo the changes.\n"
                    "#### 7. Find & Replace\n"
                    "- Press **Ctrl + F** to find and/or replace text.\n"
                    "#### 8. Highlight\n"
                    "- Press **Ctrl + H** to highlight the selected text.\n"
                    "#### 9. Spell Check\n"
                    "- Press **Ctrl + C** to perform Spell Check.\n"
                    "#### 10. Convert text to Devanagari\n"
                    "- Press **Ctrl + D** to convert selected text to devanagari format.\n"
                    "#### 11. Text Formatting\n"
                    "- Bold: Press **Ctrl + B** to make selected text **Bold**\n"
                    "- Italic: Press **Ctrl + I** to make text *Italic*\n"
                    "- Subscript: Press **Ctrl + \`**  to make text subscripted\n"
                    "- Superscript: Press **Ctrl + Shift + \`** to make text superscript\n"
                    "- Tab Space: Press **Ctrl + T** to add tab space\n"
                    "#### 12. Devanagari to SLP\n"
                    "- Press **Ctrl + G** to Convert devanagari to roman letters as mapped in SLP Guide\n"
                    "#### 13. Font Properties\n"
                    "- Press **Ctrl + Shift + A** to see current Font properties\n"
                    "#### 14. Equation\n"
                    "- Press **Ctrl + E** to open equation editor to write an equation\n"
                    "#### 15. Edit Equation\n"
                    "- Press **Ctrl + Shift + E** to edit teh selected Equation\n"
                    "#### 16. Exit\n"
                    "- Press **Ctrl + Q** to exit the Udaan PE Tool\n";
};

#endif // SHORTCUTGUIDEDIALOG_H
