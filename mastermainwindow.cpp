#include "mastermainwindow.h"
#include "qtimer.h"
#include "ui_mastermainwindow.h"
#include <iostream>

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
{
    ui->setupUi(this);
    setFixedSize(850, 700);
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MasterMainWindow::levelWin);
    timer->start(1000/60);
}

MasterMainWindow::~MasterMainWindow()
{
    delete ui;
}

void MasterMainWindow::on_quitButton_clicked()
{
    this->close();
}


void MasterMainWindow::on_Level1Button_clicked()
{
    ui->gameMap->currentLevel = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
    ui->Goal->setText("Goal: ");
}


void MasterMainWindow::on_Level2Button_clicked()
{
    ui->gameMap->currentLevel = 1;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level3Button_clicked()
{
    ui->gameMap->currentLevel = 2;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level4Button_clicked()
{
    ui->gameMap->currentLevel = 3;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level5Button_clicked()
{
    ui->gameMap->currentLevel = 4;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::levelWin()
{
    for(int i = 0;i < 5;i++)
        if(ui->gameMap->getMapWin(i)) {
            if(i == 0)
                ui->Level2Button->setEnabled(true);
            else if(i == 1)
                ui->Level3Button->setEnabled(true);
            else if(i == 2)
                ui->Level4Button->setEnabled(true);
            else if(i == 3)
                ui->Level5Button->setEnabled(true);
        }

}
