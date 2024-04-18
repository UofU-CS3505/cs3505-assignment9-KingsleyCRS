/********************************************************************************
** Form generated from reading UI file 'mastermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERMAINWINDOW_H
#define UI_MASTERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "mastergameboard.h"

QT_BEGIN_NAMESPACE

class Ui_MasterMainWindow
{
public:
    QWidget *centralwidget;
    MasterGameBoard *gameMap;
    QWidget *toolBar;
    QPushButton *hindButton;
    QPushButton *pushButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MasterMainWindow)
    {
        if (MasterMainWindow->objectName().isEmpty())
            MasterMainWindow->setObjectName("MasterMainWindow");
        MasterMainWindow->resize(800, 600);
        centralwidget = new QWidget(MasterMainWindow);
        centralwidget->setObjectName("centralwidget");
        gameMap = new MasterGameBoard(centralwidget);
        gameMap->setObjectName("gameMap");
        gameMap->setGeometry(QRect(0, 0, 600, 600));
        toolBar = new QWidget(centralwidget);
        toolBar->setObjectName("toolBar");
        toolBar->setGeometry(QRect(600, 0, 200, 600));
        hindButton = new QPushButton(toolBar);
        hindButton->setObjectName("hindButton");
        hindButton->setGeometry(QRect(0, 0, 121, 51));
        pushButton = new QPushButton(toolBar);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 510, 201, 61));
        MasterMainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MasterMainWindow);
        statusbar->setObjectName("statusbar");
        MasterMainWindow->setStatusBar(statusbar);

        retranslateUi(MasterMainWindow);

        QMetaObject::connectSlotsByName(MasterMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MasterMainWindow)
    {
        MasterMainWindow->setWindowTitle(QCoreApplication::translate("MasterMainWindow", "MainWindow", nullptr));
        hindButton->setText(QCoreApplication::translate("MasterMainWindow", "HINT", nullptr));
        pushButton->setText(QCoreApplication::translate("MasterMainWindow", "I Quit, Chinese is TOO HARD", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MasterMainWindow: public Ui_MasterMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERMAINWINDOW_H
