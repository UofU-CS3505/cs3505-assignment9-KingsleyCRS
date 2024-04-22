/********************************************************************************
** Form generated from reading UI file 'noobmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOOBMAINWINDOW_H
#define UI_NOOBMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_noobMainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QLabel *label;
    QLabel *lifeLabel;
    QSplitter *splitter;
    QPushButton *backButton;
    QPushButton *CheckButton;
    QPushButton *nextbutton;
    QLabel *label_3;
    QLabel *question;
    QWidget *NextWidgets;
    QLabel *WellDone;
    QLabel *NiceTry;
    QWidget *widget;
    QVBoxLayout *Choices;
    QPushButton *A;
    QPushButton *B;
    QPushButton *C;
    QPushButton *D;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *noobMainWindow)
    {
        if (noobMainWindow->objectName().isEmpty())
            noobMainWindow->setObjectName("noobMainWindow");
        noobMainWindow->resize(800, 600);
        centralwidget = new QWidget(noobMainWindow);
        centralwidget->setObjectName("centralwidget");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(160, 50, 451, 20));
        progressBar->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 20, 31, 31));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/heart.jpg);"));
        lifeLabel = new QLabel(centralwidget);
        lifeLabel->setObjectName("lifeLabel");
        lifeLabel->setGeometry(QRect(420, 20, 21, 31));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName("splitter");
        splitter->setGeometry(QRect(150, 450, 491, 32));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(50);
        backButton = new QPushButton(splitter);
        backButton->setObjectName("backButton");
        splitter->addWidget(backButton);
        CheckButton = new QPushButton(splitter);
        CheckButton->setObjectName("CheckButton");
        splitter->addWidget(CheckButton);
        nextbutton = new QPushButton(splitter);
        nextbutton->setObjectName("nextbutton");
        nextbutton->setCheckable(false);
        splitter->addWidget(nextbutton);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 80, 341, 91));
        question = new QLabel(centralwidget);
        question->setObjectName("question");
        question->setGeometry(QRect(280, 150, 201, 41));
        NextWidgets = new QWidget(centralwidget);
        NextWidgets->setObjectName("NextWidgets");
        NextWidgets->setGeometry(QRect(220, 220, 331, 151));
        NextWidgets->setAutoFillBackground(true);
        WellDone = new QLabel(NextWidgets);
        WellDone->setObjectName("WellDone");
        WellDone->setGeometry(QRect(100, 60, 141, 111));
        NiceTry = new QLabel(NextWidgets);
        NiceTry->setObjectName("NiceTry");
        NiceTry->setGeometry(QRect(100, 60, 141, 111));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(250, 230, 285, 205));
        Choices = new QVBoxLayout(widget);
        Choices->setObjectName("Choices");
        Choices->setContentsMargins(0, 0, 0, 0);
        A = new QPushButton(widget);
        A->setObjectName("A");

        Choices->addWidget(A);

        B = new QPushButton(widget);
        B->setObjectName("B");

        Choices->addWidget(B);

        C = new QPushButton(widget);
        C->setObjectName("C");

        Choices->addWidget(C);

        D = new QPushButton(widget);
        D->setObjectName("D");

        Choices->addWidget(D);

        noobMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(noobMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
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
        label->setText(QString());
        lifeLabel->setText(QCoreApplication::translate("noobMainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700; color:#ff2600;\">5</span></p></body></html>", nullptr));
        backButton->setText(QCoreApplication::translate("noobMainWindow", "SKIP", nullptr));
        CheckButton->setText(QCoreApplication::translate("noobMainWindow", "CHECK", nullptr));
        nextbutton->setText(QCoreApplication::translate("noobMainWindow", "Next", nullptr));
        label_3->setText(QCoreApplication::translate("noobMainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Select the correct meaning</span></p></body></html>", nullptr));
        question->setText(QCoreApplication::translate("noobMainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">word</span></p></body></html>", nullptr));
        WellDone->setText(QCoreApplication::translate("noobMainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Well Done!!!</span></p></body></html>", nullptr));
        NiceTry->setText(QCoreApplication::translate("noobMainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700;\">Nice Try!!!</span></p></body></html>", nullptr));
        A->setText(QString());
        B->setText(QString());
        C->setText(QString());
        D->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class noobMainWindow: public Ui_noobMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOOBMAINWINDOW_H
