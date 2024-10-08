#include "levelmainwindow.h"
#include "ui_levelmainwindow.h"

LevelMainWindow::LevelMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LevelMainWindow)
{
    ui->setupUi(this);
    setFixedSize(600,620);

    QString bronze = "QPushButton{"
                     "border-radius: 10px;"
                     "background-color: rgb(205, 127, 50);"
                     "color:white;}"
                     "QPushButton:hover{background-color: rgb(218, 165, 32); }"
                     "QPushButton:pressed{"
                     "background-color: rgb(184, 115, 51);"
                     "padding-left:3px;"
                     "padding-top:3px; }";
    ui->level_1->setStyleSheet(bronze);
    connect(ui->level_1,&QPushButton::clicked,this,&LevelMainWindow::level_1Clicked);
    connect(ui->level_3,&QPushButton::clicked,this,&LevelMainWindow::level_3Clicked);

    QString silver = "QPushButton{"
                     "border-radius: 10px;"
                     "background-color: rgb(192, 192, 192);"
                     "color:black;}"  // Black text on silver may look better
                     "QPushButton:hover{background-color: rgb(211, 211, 211); }"
                     "QPushButton:pressed{"
                     "background-color: rgb(169, 169, 169);"
                     "padding-left:3px;"
                     "padding-top:3px; }";

    ui->level_2->setStyleSheet(silver);
    connect(ui->level_2,&QPushButton::clicked,this,&LevelMainWindow::level_2Clicked);
    QString gold = "QPushButton{"
                   "border-radius: 10px;"
                   "background-color: rgb(255, 215, 0);"
                   "color:black;}"  // Black text on gold may look better
                   "QPushButton:hover{background-color: rgb(255, 223, 0); }"
                   "QPushButton:pressed{"
                   "background-color: rgb(238, 201, 0);"
                   "padding-left:3px;"
                   "padding-top:3px; }";

    ui->level_3->setStyleSheet(gold);
}

void LevelMainWindow::level_1Clicked(){
    noob = new noobMainWindow;
    noob->startClicked();
    noob->show();
    noob->setAttribute(Qt::WA_DeleteOnClose);
}

void LevelMainWindow::level_2Clicked(){
    level2 = new Level2MainWindow;
    level2 ->startClicked();
    level2 ->show();
    level2 ->setAttribute(Qt::WA_DeleteOnClose);
}

void LevelMainWindow::level_3Clicked(){
    qDebug()<<"haha";
    study = new studyMainWindow;
    study -> startClicked();
    study -> show();
    study -> setAttribute(Qt::WA_DeleteOnClose);
}


LevelMainWindow::~LevelMainWindow()
{
    delete ui;
}
