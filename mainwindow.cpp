#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(b2Vec2 (0.0f, -10.0f))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
