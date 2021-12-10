/********************************************************************************
** Form generated from reading UI file 'textfinder.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTFINDER_H
#define UI_TEXTFINDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_TextFinder
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *findLabel;
    QLineEdit *findLineEdit;
    QLabel *replaceLabel;
    QLineEdit *replaceLineEdit;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *findPreviousButton;
    QPushButton *findNextButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *replaceButton;
    QPushButton *replaceAllButton;

    void setupUi(QDialog *TextFinder)
    {
        if (TextFinder->objectName().isEmpty())
            TextFinder->setObjectName(QStringLiteral("TextFinder"));
        TextFinder->resize(377, 189);
        QFont font;
        font.setFamily(QStringLiteral("Work Sans"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        TextFinder->setFont(font);
        TextFinder->setStyleSheet(QStringLiteral("font: 11pt \"Work Sans\";"));
        TextFinder->setSizeGripEnabled(false);
        horizontalLayout_3 = new QHBoxLayout(TextFinder);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setFormAlignment(Qt::AlignCenter);
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(10, 10, 10, 10);
        findLabel = new QLabel(TextFinder);
        findLabel->setObjectName(QStringLiteral("findLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, findLabel);

        findLineEdit = new QLineEdit(TextFinder);
        findLineEdit->setObjectName(QStringLiteral("findLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, findLineEdit);

        replaceLabel = new QLabel(TextFinder);
        replaceLabel->setObjectName(QStringLiteral("replaceLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, replaceLabel);

        replaceLineEdit = new QLineEdit(TextFinder);
        replaceLineEdit->setObjectName(QStringLiteral("replaceLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, replaceLineEdit);


        verticalLayout->addLayout(formLayout);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, 3, 10, 2);
        findPreviousButton = new QPushButton(TextFinder);
        findPreviousButton->setObjectName(QStringLiteral("findPreviousButton"));

        horizontalLayout->addWidget(findPreviousButton);

        findNextButton = new QPushButton(TextFinder);
        findNextButton->setObjectName(QStringLiteral("findNextButton"));

        horizontalLayout->addWidget(findNextButton);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 2, 10, 3);
        replaceButton = new QPushButton(TextFinder);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));
        replaceButton->setFont(font);

        horizontalLayout_2->addWidget(replaceButton);

        replaceAllButton = new QPushButton(TextFinder);
        replaceAllButton->setObjectName(QStringLiteral("replaceAllButton"));
        replaceAllButton->setFont(font);

        horizontalLayout_2->addWidget(replaceAllButton);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout_3->addLayout(verticalLayout);


        retranslateUi(TextFinder);

        QMetaObject::connectSlotsByName(TextFinder);
    } // setupUi

    void retranslateUi(QDialog *TextFinder)
    {
        TextFinder->setWindowTitle(QApplication::translate("TextFinder", "Find and Replace", Q_NULLPTR));
        findLabel->setText(QApplication::translate("TextFinder", "Find:", Q_NULLPTR));
        replaceLabel->setText(QApplication::translate("TextFinder", "Replace:", Q_NULLPTR));
        findPreviousButton->setText(QApplication::translate("TextFinder", "Find Previous", Q_NULLPTR));
        findNextButton->setText(QApplication::translate("TextFinder", "Find Next", Q_NULLPTR));
        replaceButton->setText(QApplication::translate("TextFinder", "Replace", Q_NULLPTR));
        replaceAllButton->setText(QApplication::translate("TextFinder", "Replace All", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TextFinder: public Ui_TextFinder {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTFINDER_H
