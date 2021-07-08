/********************************************************************************
** Form generated from reading UI file 'averageaccuracies.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AVERAGEACCURACIES_H
#define UI_AVERAGEACCURACIES_H

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
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AverageAccuracies
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_4;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLineEdit *avgwordacc;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_9;
    QLineEdit *avgcharacc;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_10;
    QFrame *line;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_11;
    QLineEdit *avgworderrors;
    QVBoxLayout *verticalLayout_12;
    QLabel *label_12;
    QLineEdit *avgcharerrors;
    QTableView *tableView;

    void setupUi(QDialog *AverageAccuracies)
    {
        if (AverageAccuracies->objectName().isEmpty())
            AverageAccuracies->setObjectName(QStringLiteral("AverageAccuracies"));
        AverageAccuracies->resize(489, 364);
        verticalLayout = new QVBoxLayout(AverageAccuracies);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_4 = new QLabel(AverageAccuracies);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_4);

        line_3 = new QFrame(AverageAccuracies);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line_3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_8 = new QLabel(AverageAccuracies);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_8->addWidget(label_8);

        avgwordacc = new QLineEdit(AverageAccuracies);
        avgwordacc->setObjectName(QStringLiteral("avgwordacc"));
        avgwordacc->setDragEnabled(true);
        avgwordacc->setReadOnly(true);

        verticalLayout_8->addWidget(avgwordacc);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_9 = new QLabel(AverageAccuracies);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_9->addWidget(label_9);

        avgcharacc = new QLineEdit(AverageAccuracies);
        avgcharacc->setObjectName(QStringLiteral("avgcharacc"));
        avgcharacc->setDragEnabled(true);
        avgcharacc->setReadOnly(true);

        verticalLayout_9->addWidget(avgcharacc);


        horizontalLayout_3->addLayout(verticalLayout_9);


        verticalLayout_7->addLayout(horizontalLayout_3);


        horizontalLayout->addLayout(verticalLayout_7);

        line_2 = new QFrame(AverageAccuracies);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_10 = new QLabel(AverageAccuracies);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_10->addWidget(label_10);

        line = new QFrame(AverageAccuracies);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_10->addWidget(line);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        label_11 = new QLabel(AverageAccuracies);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_11->addWidget(label_11);

        avgworderrors = new QLineEdit(AverageAccuracies);
        avgworderrors->setObjectName(QStringLiteral("avgworderrors"));
        avgworderrors->setDragEnabled(true);
        avgworderrors->setReadOnly(true);

        verticalLayout_11->addWidget(avgworderrors);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        label_12 = new QLabel(AverageAccuracies);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_12->addWidget(label_12);

        avgcharerrors = new QLineEdit(AverageAccuracies);
        avgcharerrors->setObjectName(QStringLiteral("avgcharerrors"));
        avgcharerrors->setDragEnabled(true);
        avgcharerrors->setReadOnly(true);

        verticalLayout_12->addWidget(avgcharerrors);


        horizontalLayout_4->addLayout(verticalLayout_12);


        verticalLayout_10->addLayout(horizontalLayout_4);


        horizontalLayout->addLayout(verticalLayout_10);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(AverageAccuracies);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(AverageAccuracies);

        QMetaObject::connectSlotsByName(AverageAccuracies);
    } // setupUi

    void retranslateUi(QDialog *AverageAccuracies)
    {
        AverageAccuracies->setWindowTitle(QApplication::translate("AverageAccuracies", "Dialog", Q_NULLPTR));
        label_4->setText(QApplication::translate("AverageAccuracies", "Average Accuracy", Q_NULLPTR));
        label_8->setText(QApplication::translate("AverageAccuracies", "Word Level", Q_NULLPTR));
        label_9->setText(QApplication::translate("AverageAccuracies", "Character Level", Q_NULLPTR));
        label_10->setText(QApplication::translate("AverageAccuracies", "Average Errors", Q_NULLPTR));
        label_11->setText(QApplication::translate("AverageAccuracies", "Word Level", Q_NULLPTR));
        label_12->setText(QApplication::translate("AverageAccuracies", "Character Level", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AverageAccuracies: public Ui_AverageAccuracies {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AVERAGEACCURACIES_H
