/********************************************************************************
** Form generated from reading UI file 'mastermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MASTERMAINWINDOW_H
#define UI_MASTERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QPushButton *hintButton;
    QPushButton *quitButton;
    QPushButton *Level1Button;
    QPushButton *Level2Button;
    QPushButton *Level3Button;
    QPushButton *Level4Button;
    QPushButton *Level5Button;
    QLabel *Goal;
    QLabel *tutorial;
    QPushButton *resetButton;
    QLabel *Hint;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MasterMainWindow)
    {
        if (MasterMainWindow->objectName().isEmpty())
            MasterMainWindow->setObjectName("MasterMainWindow");
        MasterMainWindow->resize(820, 619);
        centralwidget = new QWidget(MasterMainWindow);
        centralwidget->setObjectName("centralwidget");
        gameMap = new MasterGameBoard(centralwidget);
        gameMap->setObjectName("gameMap");
        gameMap->setGeometry(QRect(0, 0, 600, 600));
        toolBar = new QWidget(centralwidget);
        toolBar->setObjectName("toolBar");
        toolBar->setGeometry(QRect(620, 0, 250, 800));
        hintButton = new QPushButton(toolBar);
        hintButton->setObjectName("hintButton");
        hintButton->setGeometry(QRect(90, 90, 111, 31));
        quitButton = new QPushButton(toolBar);
        quitButton->setObjectName("quitButton");
        quitButton->setGeometry(QRect(0, 520, 201, 61));
        Level1Button = new QPushButton(toolBar);
        Level1Button->setObjectName("Level1Button");
        Level1Button->setGeometry(QRect(0, 100, 80, 18));
        Level2Button = new QPushButton(toolBar);
        Level2Button->setObjectName("Level2Button");
        Level2Button->setEnabled(true);
        Level2Button->setGeometry(QRect(0, 120, 80, 18));
        Level3Button = new QPushButton(toolBar);
        Level3Button->setObjectName("Level3Button");
        Level3Button->setEnabled(true);
        Level3Button->setGeometry(QRect(0, 140, 80, 18));
        Level4Button = new QPushButton(toolBar);
        Level4Button->setObjectName("Level4Button");
        Level4Button->setEnabled(true);
        Level4Button->setGeometry(QRect(0, 160, 80, 18));
        Level5Button = new QPushButton(toolBar);
        Level5Button->setObjectName("Level5Button");
        Level5Button->setEnabled(true);
        Level5Button->setGeometry(QRect(0, 180, 80, 18));
        Goal = new QLabel(toolBar);
        Goal->setObjectName("Goal");
        Goal->setGeometry(QRect(0, 30, 211, 41));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        Goal->setFont(font);
        tutorial = new QLabel(toolBar);
        tutorial->setObjectName("tutorial");
        tutorial->setGeometry(QRect(9, 0, 241, 31));
        QFont font1;
        font1.setPointSize(9);
        tutorial->setFont(font1);
        resetButton = new QPushButton(toolBar);
        resetButton->setObjectName("resetButton");
        resetButton->setGeometry(QRect(0, 440, 111, 41));
        Hint = new QLabel(toolBar);
        Hint->setObjectName("Hint");
        Hint->setGeometry(QRect(0, 200, 191, 51));
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
        hintButton->setText(QCoreApplication::translate("MasterMainWindow", "Give me some HInt", nullptr));
        quitButton->setText(QCoreApplication::translate("MasterMainWindow", "I Quit, Chinese is TOO HARD", nullptr));
        Level1Button->setText(QCoreApplication::translate("MasterMainWindow", "Level1", nullptr));
        Level2Button->setText(QCoreApplication::translate("MasterMainWindow", "Level2", nullptr));
        Level3Button->setText(QCoreApplication::translate("MasterMainWindow", "Level3", nullptr));
        Level4Button->setText(QCoreApplication::translate("MasterMainWindow", "Level4", nullptr));
        Level5Button->setText(QCoreApplication::translate("MasterMainWindow", "Level5", nullptr));
        Goal->setText(QCoreApplication::translate("MasterMainWindow", "Goal: Save the Dog.", nullptr));
        tutorial->setText(QCoreApplication::translate("MasterMainWindow", "Use \"WASD\" to control the yourself: \"\346\210\221\"", nullptr));
        resetButton->setText(QCoreApplication::translate("MasterMainWindow", "Reset Current Level", nullptr));
        Hint->setText(QCoreApplication::translate("MasterMainWindow", "Hint:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MasterMainWindow: public Ui_MasterMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MASTERMAINWINDOW_H
