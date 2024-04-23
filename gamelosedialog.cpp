#include "gamelosedialog.h"
#include "ui_gamelosedialog.h"

GameLoseDialog::GameLoseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameLoseDialog)
{
    ui->setupUi(this);
}

GameLoseDialog::~GameLoseDialog()
{
    delete ui;
}

void GameLoseDialog::on_buttonBox_accepted()
{

}

