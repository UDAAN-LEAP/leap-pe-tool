#ifndef COMMENTSVIEW_H
#define COMMENTSVIEW_H

#include <QDialog>
namespace Ui {
class CommentsView;
}

class CommentsView : public QDialog
{
    Q_OBJECT

public:
    explicit CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc, const QString comments, const QString commentFilename, const QString currentpagename, int rating,  const QString avgAcc, const QString role, QString version, QWidget *parent = nullptr);
    ~CommentsView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommentsView *ui;
};

#endif // COMMENTSVIEW_H
