/********************************************************************************
** Form generated from reading UI file 'levelmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVELMAINWINDOW_H
#define UI_LEVELMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LevelMainWindow
{
public:
    QWidget *centralwidget;
    QSplitter *splitter;
    QPushButton *level_1;
    QPushButton *level_2;
    QPushButton *level_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LevelMainWindow)
    {
        if (LevelMainWindow->objectName().isEmpty())
            LevelMainWindow->setObjectName("LevelMainWindow");
        LevelMainWindow->resize(800, 600);
        centralwidget = new QWidget(LevelMainWindow);
        centralwidget->setObjectName("centralwidget");
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(320, 150, 151, 296));
        splitter->setLineWidth(1);
        splitter->setMidLineWidth(0);
        splitter->setOrientation(Qt::Vertical);
        splitter->setHandleWidth(100);
        level_1 = new QPushButton(splitter);
        level_1->setObjectName("level_1");
        splitter->addWidget(level_1);
        level_2 = new QPushButton(splitter);
        level_2->setObjectName("level_2");
        splitter->addWidget(level_2);
        level_3 = new QPushButton(splitter);
        level_3->setObjectName("level_3");
        splitter->addWidget(level_3);
        LevelMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LevelMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        LevelMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LevelMainWindow);
        statusbar->setObjectName("statusbar");
        LevelMainWindow->setStatusBar(statusbar);

        retranslateUi(LevelMainWindow);

        QMetaObject::connectSlotsByName(LevelMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LevelMainWindow)
    {
        LevelMainWindow->setWindowTitle(QCoreApplication::translate("LevelMainWindow", "MainWindow", nullptr));
        level_1->setText(QCoreApplication::translate("LevelMainWindow", "Level 1", nullptr));
        level_2->setText(QCoreApplication::translate("LevelMainWindow", "Level 2", nullptr));
        level_3->setText(QCoreApplication::translate("LevelMainWindow", "Level 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LevelMainWindow: public Ui_LevelMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVELMAINWINDOW_H
