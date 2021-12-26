#ifndef GLOBALREPLACEPREVIEW_H
#define GLOBALREPLACEPREVIEW_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class globalReplacePreview;
}

class globalReplacePreview : public QDialog
{
    Q_OBJECT

public:
    globalReplacePreview(QWidget *parent,QStandardItemModel *model);
    ~globalReplacePreview();

private:
    Ui::globalReplacePreview *ui;
};

#endif // GLOBALREPLACEPREVIEW_H
