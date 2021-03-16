#ifndef TEXTFINDER_H
#define TEXTFINDER_H

#include <QDialog>
#include <string>
#include <QString>
using namespace std;

namespace Ui {
class TextFinder;
}

class TextFinder : public QDialog
{
    Q_OBJECT

public:
    static TextFinder* openFindAndReplace(QWidget *);
    ~TextFinder();

private slots:

    void on_findNextButton_clicked();

    void on_findPreviousButton_clicked();

    void on_replaceButton_clicked();

    void on_replaceAllButton_clicked();

    void keyPressEvent(QKeyEvent *);

    QString toDevanagari(string);

    bool eventFilter(QObject *watched, QEvent *event);


private:
    Ui::TextFinder *ui;
    explicit TextFinder(QWidget *parent = nullptr);
    static TextFinder *textFinder;
};

#endif // TEXTFINDER_H
