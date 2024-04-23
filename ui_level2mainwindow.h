/********************************************************************************
** Form generated from reading UI file 'level2mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL2MAINWINDOW_H
#define UI_LEVEL2MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Level2MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *lifeLabel;
    QLabel *label_2;
    QPushButton *skipButton;
    QWidget *layoutWidget;
    QVBoxLayout *rightSide;
    QPushButton *pair_1_1;
    QPushButton *pair_2_2;
    QPushButton *pair_3_3;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *pair_1;
    QPushButton *pair_2;
    QPushButton *pair_3;
    QLabel *CorrectLabel;
    QLabel *tryagain;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Level2MainWindow)
    {
        if (Level2MainWindow->objectName().isEmpty())
            Level2MainWindow->setObjectName("Level2MainWindow");
        Level2MainWindow->resize(800, 600);
        centralwidget = new QWidget(Level2MainWindow);
        centralwidget->setObjectName("centralwidget");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(170, 50, 451, 20));
        progressBar->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(350, 20, 31, 31));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/heart.jpg);"));
        lifeLabel = new QLabel(centralwidget);
        lifeLabel->setObjectName("lifeLabel");
        lifeLabel->setGeometry(QRect(390, 20, 21, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(170, 90, 291, 61));
        skipButton = new QPushButton(centralwidget);
        skipButton->setObjectName("skipButton");
        skipButton->setGeometry(QRect(330, 490, 119, 32));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(400, 210, 171, 241));
        rightSide = new QVBoxLayout(layoutWidget);
        rightSide->setObjectName("rightSide");
        rightSide->setContentsMargins(0, 0, 0, 0);
        pair_1_1 = new QPushButton(layoutWidget);
        pair_1_1->setObjectName("pair_1_1");

        rightSide->addWidget(pair_1_1);

        pair_2_2 = new QPushButton(layoutWidget);
        pair_2_2->setObjectName("pair_2_2");

        rightSide->addWidget(pair_2_2);

        pair_3_3 = new QPushButton(layoutWidget);
        pair_3_3->setObjectName("pair_3_3");

        rightSide->addWidget(pair_3_3);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(200, 210, 171, 241));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pair_1 = new QPushButton(layoutWidget1);
        pair_1->setObjectName("pair_1");

        verticalLayout->addWidget(pair_1);

        pair_2 = new QPushButton(layoutWidget1);
        pair_2->setObjectName("pair_2");

        verticalLayout->addWidget(pair_2);

        pair_3 = new QPushButton(layoutWidget1);
        pair_3->setObjectName("pair_3");

        verticalLayout->addWidget(pair_3);

        CorrectLabel = new QLabel(centralwidget);
        CorrectLabel->setObjectName("CorrectLabel");
        CorrectLabel->setGeometry(QRect(270, 300, 281, 61));
        tryagain = new QLabel(centralwidget);
        tryagain->setObjectName("tryagain");
        tryagain->setGeometry(QRect(320, 300, 281, 61));
        Level2MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Level2MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        Level2MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(Level2MainWindow);
        statusbar->setObjectName("statusbar");
        Level2MainWindow->setStatusBar(statusbar);

        retranslateUi(Level2MainWindow);

        QMetaObject::connectSlotsByName(Level2MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *Level2MainWindow)
    {
        Level2MainWindow->setWindowTitle(QCoreApplication::translate("Level2MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        lifeLabel->setText(QCoreApplication::translate("Level2MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#ff2600;\">5</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Level2MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Select the matching pairs</span></p></body></html>", nullptr));
        skipButton->setText(QCoreApplication::translate("Level2MainWindow", "SKIP", nullptr));
        pair_1_1->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        pair_2_2->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        pair_3_3->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        pair_1->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        pair_2->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        pair_3->setText(QCoreApplication::translate("Level2MainWindow", "PushButton", nullptr));
        CorrectLabel->setText(QCoreApplication::translate("Level2MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Nice Job! Keep it up</span></p></body></html>", nullptr));
        tryagain->setText(QCoreApplication::translate("Level2MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Try again!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Level2MainWindow: public Ui_Level2MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL2MAINWINDOW_H
