#include "mastermainwindow.h"
#include "qtimer.h"
#include "ui_mastermainwindow.h"

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
{
    ui->setupUi(this);
    setFixedSize(1050, 750);
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MasterMainWindow::levelWin);
    connect(&gamelose, &GameLoseDialog::accepted, this, &MasterMainWindow::handleDialog);
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
    ui->Goal->setText("Goal: Kill the Monster");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->MapUpdateTimer->start(200);
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
    for(int i = 0;i < 5;i++){
        bool win = ui->gameMap->getMapWin(i);
        if(win){
            if(i == 0){
                if(!ui->gameMap->levels[i]->passed)
                {
                    ui->gameMap->levels[i]->passed = 1;
                    ui->Level2Button->setEnabled(true);
                }
            }
            else if(i == 1)
            {
                if(!ui->gameMap->levels[i]->passed){
                    ui->gameMap->levels[i]->passed = 1;
                    ui->Level3Button->setEnabled(true);
                }
            }
            else if(i == 2)
            {
                if(!ui->gameMap->levels[i]->passed){
                    ui->gameMap->levels[i]->passed = 1;
                    ui->Level4Button->setEnabled(true);
                }
            }
            else if(i == 3)
            {
                if(!ui->gameMap->levels[i]->passed){
                    ui->gameMap->levels[i]->passed = 1;
                    ui->Level5Button->setEnabled(true);
                }
            }
            else if(i == 4)
            {
                /*todo, player win the game*/
            }
        }
        if(ui->gameMap->levels[i]->playerDied)
        {
            gameLost();
        }
    }
    if(ui->gameMap->levels[ui->gameMap->currentLevel]->win)
        ui->nextLevelButton->setEnabled(true);
}

void MasterMainWindow::on_resetButton_clicked()
{
    ui->gameMap->levels[ui->gameMap->currentLevel]->createMap();
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;;
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

void MasterMainWindow::gameLost(){
    gamelose.show();
    on_resetButton_clicked();
}

void MasterMainWindow::handleDialog()
{
    ui->gameMap->levels[ui->gameMap->currentLevel]->playerDied = 0;
}

void MasterMainWindow::on_nextLevelButton_clicked()
{
    ui->gameMap->updateLevel();
    ui->nextLevelButton->setEnabled(false);
    update();
    ui->gameMap->setFocus();
}

