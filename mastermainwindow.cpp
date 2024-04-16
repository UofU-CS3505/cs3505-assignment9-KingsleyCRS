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
