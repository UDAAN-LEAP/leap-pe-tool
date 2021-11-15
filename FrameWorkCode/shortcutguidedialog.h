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
};

#endif // SHORTCUTGUIDEDIALOG_H
