/********************************************************************************
** Form generated from reading UI file 'commentsview.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTSVIEW_H
#define UI_COMMENTSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CommentsView
{
public:
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *h_words;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLineEdit *h_characters;
    QSpacerItem *horizontalSpacer_2;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QLineEdit *acc_word;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QLineEdit *acc_character;
    QLabel *label_3;
    QTextBrowser *commentTextBrowser;

    void setupUi(QDialog *CommentsView)
    {
        if (CommentsView->objectName().isEmpty())
            CommentsView->setObjectName(QStringLiteral("CommentsView"));
        CommentsView->resize(479, 377);
        horizontalLayout_4 = new QHBoxLayout(CommentsView);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(CommentsView);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        line_3 = new QFrame(CommentsView);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(CommentsView);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        h_words = new QLineEdit(CommentsView);
        h_words->setObjectName(QStringLiteral("h_words"));

        verticalLayout->addWidget(h_words);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(CommentsView);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_2->addWidget(label_4);

        h_characters = new QLineEdit(CommentsView);
        h_characters->setObjectName(QStringLiteral("h_characters"));

        verticalLayout_2->addWidget(h_characters);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        line_2 = new QFrame(CommentsView);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_6 = new QLabel(CommentsView);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_4->addWidget(label_6);

        line = new QFrame(CommentsView);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_7 = new QLabel(CommentsView);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_5->addWidget(label_7);

        acc_word = new QLineEdit(CommentsView);
        acc_word->setObjectName(QStringLiteral("acc_word"));

        verticalLayout_5->addWidget(acc_word);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(CommentsView);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_6->addWidget(label_8);

        acc_character = new QLineEdit(CommentsView);
        acc_character->setObjectName(QStringLiteral("acc_character"));

        verticalLayout_6->addWidget(acc_character);


        horizontalLayout_2->addLayout(verticalLayout_6);


        verticalLayout_4->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_3);

        label_3 = new QLabel(CommentsView);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_7->addWidget(label_3);

        commentTextBrowser = new QTextBrowser(CommentsView);
        commentTextBrowser->setObjectName(QStringLiteral("commentTextBrowser"));
        commentTextBrowser->setMaximumSize(QSize(604, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Shobhika"));
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        commentTextBrowser->setFont(font);

        verticalLayout_7->addWidget(commentTextBrowser);


        horizontalLayout_4->addLayout(verticalLayout_7);


        retranslateUi(CommentsView);

        QMetaObject::connectSlotsByName(CommentsView);
    } // setupUi

    void retranslateUi(QDialog *CommentsView)
    {
        CommentsView->setWindowTitle(QApplication::translate("CommentsView", "View Comments", Q_NULLPTR));
        label->setText(QApplication::translate("CommentsView", "<b>Total Highlights</b>", Q_NULLPTR));
        label_2->setText(QApplication::translate("CommentsView", "Words", Q_NULLPTR));
        label_4->setText(QApplication::translate("CommentsView", "Characters", Q_NULLPTR));
        label_6->setText(QApplication::translate("CommentsView", "<b>Accuracy</b>", Q_NULLPTR));
        label_7->setText(QApplication::translate("CommentsView", "Word-Level", Q_NULLPTR));
        label_8->setText(QApplication::translate("CommentsView", "Character-Level", Q_NULLPTR));
        label_3->setText(QApplication::translate("CommentsView", "<b>Comments</b>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommentsView: public Ui_CommentsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTSVIEW_H
