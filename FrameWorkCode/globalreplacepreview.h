#ifndef GLOBALREPLACEPREVIEW_H
#define GLOBALREPLACEPREVIEW_H

#include <QDialog>

namespace Ui {
class globalReplacePreview;
}

class globalReplacePreview : public QDialog
{
    Q_OBJECT

public:
    explicit globalReplacePreview(QWidget *parent = 0);
    ~globalReplacePreview();

private:
    Ui::globalReplacePreview *ui;
};

#endif // GLOBALREPLACEPREVIEW_H
