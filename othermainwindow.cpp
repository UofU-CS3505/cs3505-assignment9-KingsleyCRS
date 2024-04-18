#include "othermainwindow.h"
#include "ui_othermainwindow.h"

OtherMainWindow::OtherMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OtherMainWindow)
{
    ui->setupUi(this);
}

OtherMainWindow::~OtherMainWindow()
{
    delete ui;
}
