#include "mastermainwindow.h"
#include "ui_mastermainwindow.h"

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
{
    ui->setupUi(this);
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

}


void MasterMainWindow::on_Level2Button_clicked()
{

}


void MasterMainWindow::on_Level3Button_clicked()
{

}


void MasterMainWindow::on_Level4Button_clicked()
{

}


void MasterMainWindow::on_Level5Button_clicked()
{

}

