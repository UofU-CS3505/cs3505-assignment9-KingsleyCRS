/********************************************************************************
** Form generated from reading UI file 'studymainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STUDYMAINWINDOW_H
#define UI_STUDYMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_studyMainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *knowBT;
    QPushButton *unknowBT;
    QPushButton *restartBT;
    QLabel *chineseLable;
    QLabel *englishLable;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *studyMainWindow)
    {
        if (studyMainWindow->objectName().isEmpty())
            studyMainWindow->setObjectName("studyMainWindow");
        studyMainWindow->resize(441, 554);
        centralwidget = new QWidget(studyMainWindow);
        centralwidget->setObjectName("centralwidget");
        knowBT = new QPushButton(centralwidget);
        knowBT->setObjectName("knowBT");
        knowBT->setGeometry(QRect(30, 410, 81, 31));
        unknowBT = new QPushButton(centralwidget);
        unknowBT->setObjectName("unknowBT");
        unknowBT->setGeometry(QRect(180, 410, 80, 31));
        restartBT = new QPushButton(centralwidget);
        restartBT->setObjectName("restartBT");
        restartBT->setGeometry(QRect(330, 410, 80, 31));
        chineseLable = new QLabel(centralwidget);
        chineseLable->setObjectName("chineseLable");
        chineseLable->setGeometry(QRect(50, 140, 341, 91));
        QFont font;
        font.setPointSize(22);
        chineseLable->setFont(font);
        chineseLable->setAlignment(Qt::AlignCenter);
        englishLable = new QLabel(centralwidget);
        englishLable->setObjectName("englishLable");
        englishLable->setGeometry(QRect(50, 240, 341, 91));
        englishLable->setFont(font);
        englishLable->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(30, 50, 381, 20));
        progressBar->setValue(24);
        studyMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(studyMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 441, 20));
        studyMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(studyMainWindow);
        statusbar->setObjectName("statusbar");
        studyMainWindow->setStatusBar(statusbar);

        retranslateUi(studyMainWindow);

        QMetaObject::connectSlotsByName(studyMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *studyMainWindow)
    {
        studyMainWindow->setWindowTitle(QCoreApplication::translate("studyMainWindow", "MainWindow", nullptr));
        knowBT->setText(QCoreApplication::translate("studyMainWindow", "Know", nullptr));
        unknowBT->setText(QCoreApplication::translate("studyMainWindow", "Unknow", nullptr));
        restartBT->setText(QCoreApplication::translate("studyMainWindow", "Restart", nullptr));
        chineseLable->setText(QCoreApplication::translate("studyMainWindow", "\344\270\255\346\226\207", nullptr));
        englishLable->setText(QCoreApplication::translate("studyMainWindow", "English", nullptr));
    } // retranslateUi

};

namespace Ui {
    class studyMainWindow: public Ui_studyMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STUDYMAINWINDOW_H
