/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *noobButton;
    QPushButton *masterButton;
    QMenuBar *menubar;
    QMenu *menuYour_Chinese_Teacher;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 800);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        noobButton = new QPushButton(centralwidget);
        noobButton->setObjectName("noobButton");
        noobButton->setGeometry(QRect(320, 460, 171, 71));
        noobButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Screenshot 2024-04-20 190618.png);"));
        masterButton = new QPushButton(centralwidget);
        masterButton->setObjectName("masterButton");
        masterButton->setGeometry(QRect(320, 540, 171, 71));
        masterButton->setStyleSheet(QString::fromUtf8("border-image: url(:/Screenshot 2024-04-20 190618.png);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuYour_Chinese_Teacher = new QMenu(menubar);
        menuYour_Chinese_Teacher->setObjectName("menuYour_Chinese_Teacher");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuYour_Chinese_Teacher->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        noobButton->setText(QCoreApplication::translate("MainWindow", "Novice mode", nullptr));
        masterButton->setText(QCoreApplication::translate("MainWindow", "Master mode", nullptr));
        menuYour_Chinese_Teacher->setTitle(QCoreApplication::translate("MainWindow", "Your Chinese Teacher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
