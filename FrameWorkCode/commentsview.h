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
    explicit CommentsView(const int &words, const int &chars, const float &wordacc, const float &characc, const QString comments, const QString commentFilename,int rating, QWidget *parent = nullptr);
    ~CommentsView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CommentsView *ui;
};

#endif // COMMENTSVIEW_H
