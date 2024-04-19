/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
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
    QLabel *label;
    QLabel *label_2;
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
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 190, 101, 101));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/WechatIMG114.jpg);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(470, 190, 101, 101));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/WechatIMG115.jpg);"));
        noobButton = new QPushButton(centralwidget);
        noobButton->setObjectName("noobButton");
        noobButton->setGeometry(QRect(190, 330, 111, 51));
        masterButton = new QPushButton(centralwidget);
        masterButton->setObjectName("masterButton");
        masterButton->setGeometry(QRect(470, 330, 111, 51));
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
        label->setText(QString());
        label_2->setText(QString());
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
