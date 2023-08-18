#ifndef ADD_COMMENT_H
#define ADD_COMMENT_H

#include <QDialog>

namespace Ui {
class CommentHandler;
}

class CommentHandler : public QDialog
{
    Q_OBJECT

public:
    explicit CommentHandler(QWidget *parent = nullptr, QString corrector_comment = "", QString verifier_comment = "", QString mRole = "");
    ~CommentHandler();
    QString getComment();

private slots:
    void on_AddComment_clicked();

    void on_Cancel_clicked();

    void on_deleteComment_clicked();

signals:
    void commented();
    void deleted();

private:
    Ui::CommentHandler *ui;
    QString _comment;

};

#endif // ADD_COMMENT_H
