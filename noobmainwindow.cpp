#include "noobmainwindow.h"
#include "ui_noobmainwindow.h"

noobMainWindow::noobMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::noobMainWindow)
{
    ui->setupUi(this);
}

noobMainWindow::~noobMainWindow()
{
    delete ui;
}
