/********************************************************************************
** Form generated from reading UI file 'noobmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOOBMAINWINDOW_H
#define UI_NOOBMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_noobMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *noobMainWindow)
    {
        if (noobMainWindow->objectName().isEmpty())
            noobMainWindow->setObjectName("noobMainWindow");
        noobMainWindow->resize(800, 600);
        centralwidget = new QWidget(noobMainWindow);
        centralwidget->setObjectName("centralwidget");
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(260, 240, 100, 32));
        noobMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(noobMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 36));
        noobMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(noobMainWindow);
        statusbar->setObjectName("statusbar");
        noobMainWindow->setStatusBar(statusbar);

        retranslateUi(noobMainWindow);

        QMetaObject::connectSlotsByName(noobMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *noobMainWindow)
    {
        noobMainWindow->setWindowTitle(QCoreApplication::translate("noobMainWindow", "MainWindow", nullptr));
        backButton->setText(QCoreApplication::translate("noobMainWindow", "start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class noobMainWindow: public Ui_noobMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOOBMAINWINDOW_H
