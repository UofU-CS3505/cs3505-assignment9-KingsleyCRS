#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(b2Vec2 (0.0f, -10.0f))
{
    ui->setupUi(this);
    QString blue = "QPushButton{border-radius: 10px;background-color: rgb(14 , 150 , 254); color:white;}"
                   "QPushButton:hover{background-color: rgb(44 , 137 , 255); }"
                   "QPushButton:pressed{background-color:rgb(14 , 135 , 228);padding-left:3px; padding-top:3px; }";
    ui->noob->setStyleSheet(blue);
    QString red = "QPushButton{border-radius: 10px;background-color: rgb(255, 90, 32);; color:white;}"
                  "QPushButton:hover{background-color: rgb(255, 50, 22); }"
                  "QPushButton:pressed{background-color:rgb(255, 120, 25); padding-left:3px; padding-top:3px;}";
    ui->master->setStyleSheet(red);
}

MainWindow::~MainWindow()
{
    delete ui;
}
