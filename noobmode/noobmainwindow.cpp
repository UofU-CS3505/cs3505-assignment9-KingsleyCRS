#include "noobmainwindow.h"
#include "ui_noobmainwindow.h"

noobMainWindow::noobMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::noobMainWindow)
{
    ui->setupUi(this);
    connect(ui->backButton,&QPushButton::clicked,this,&noobMainWindow::startClicked);
}

noobMainWindow::~noobMainWindow()
{
    delete ui;
}
void noobMainWindow::startClicked(){
}
