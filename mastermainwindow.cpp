#include "mastermainwindow.h"
#include "qtimer.h"
#include "ui_mastermainwindow.h"

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
    ui->Goal->setText("Goal: Save the dog");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level2Button_clicked()
{
    ui->gameMap->currentLevel = 1;
    ui->Goal->setText("Goal: Feed your dog");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();

}


void MasterMainWindow::on_Level3Button_clicked()
{
    ui->gameMap->currentLevel = 2;
    ui->Goal->setText("Goal: Find the Treasure");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level4Button_clicked()
{
    ui->gameMap->currentLevel = 3;
    ui->Goal->setText("Goal: Save the princess");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level5Button_clicked()
{
    ui->gameMap->currentLevel = 4;
    ui->Goal->setText("Goal: Feed your dog");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::levelWin()
{
    for(int i = 0;i < 5;i++)
        if(ui->gameMap->getMapWin(i)) {
            if(i == 0){
                if(!ui->gameMap->levels[i]->passed)
                {
                    ui->gameMap->levels[i]->passed = 1;
                    on_Level2Button_clicked();
                    ui->Level2Button->setEnabled(true);
                }
                else if(ui->gameMap->levels[i]->playerDied)
                {
                    /*todo*/
                }
            }
            else if(i == 1 && !ui->gameMap->levels[i]->passed)
            {
                ui->gameMap->levels[i]->passed = 1;
                on_Level3Button_clicked();
                ui->Level3Button->setEnabled(true);
            }
            else if(i == 2 && !ui->gameMap->levels[i]->passed)
            {
                ui->gameMap->levels[i]->passed = 1;
                on_Level4Button_clicked();
                ui->Level4Button->setEnabled(true);
            }
            else if(i == 3 && !ui->gameMap->levels[i]->passed)
            {
                ui->gameMap->levels[i]->passed = 1;
                on_Level5Button_clicked();
                ui->Level5Button->setEnabled(true);
            }
        }
}

void MasterMainWindow::on_resetButton_clicked()
{
    ui->gameMap->levels[ui->gameMap->currentLevel]->createMap();
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_hintButton_clicked()
{
    QString hint = ui->gameMap->levels[ui->gameMap->currentLevel]->getHint();
    ui->Hint->setText(hint);
    ui->gameMap->update();
    ui->gameMap->setFocus();
}

