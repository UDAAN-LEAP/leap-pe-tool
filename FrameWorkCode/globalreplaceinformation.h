#ifndef GLOBALREPLACEINFORMATION_H
#define GLOBALREPLACEINFORMATION_H

#include <QDialog>

namespace Ui {
class globalReplaceInformation;
}

class globalReplaceInformation : public QDialog
{
    Q_OBJECT

public:
    explicit globalReplaceInformation(QWidget *parent = 0);
    ~globalReplaceInformation();

private:
    Ui::globalReplaceInformation *ui;
};

#endif // GLOBALREPLACEINFORMATION_H
