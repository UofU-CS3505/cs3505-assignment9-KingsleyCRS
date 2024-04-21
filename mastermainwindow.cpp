#include "mastermainwindow.h"
#include "ui_mastermainwindow.h"

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
{
    ui->setupUi(this);
    setFixedSize(800, 700);
}

MasterMainWindow::~MasterMainWindow()
{
    delete ui;
}

void MasterMainWindow::on_pushButton_clicked()
{
    this->close();
}


void MasterMainWindow::on_Level1Button_clicked()
{
    ui->gameMap->currentLevel = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
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

