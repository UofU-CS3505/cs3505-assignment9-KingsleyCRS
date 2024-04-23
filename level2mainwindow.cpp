#include "level2mainwindow.h"
#include "ui_level2mainwindow.h"
#include <random>
#include <QTimer>
Level2MainWindow::Level2MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Level2MainWindow)
    ,life(3)
    ,barValue(10)
    ,levelCount(2)
    ,correctCount(0)
    ,numbers(3)
{
    ui->setupUi(this);
    connect(ui->pair_1, &QPushButton::clicked, this, &Level2MainWindow::Pair1Clicked);
    connect(ui->pair_2, &QPushButton::clicked, this, &Level2MainWindow::Pair2Clicked);
    connect(ui->pair_3, &QPushButton::clicked, this, &Level2MainWindow::Pair3Clicked);
    connect(ui->pair_1_1, &QPushButton::clicked, this, &Level2MainWindow::Pair11Clicked);
    connect(ui->pair_2_2, &QPushButton::clicked, this, &Level2MainWindow::Pair22Clicked);
    connect(ui->pair_3_3, &QPushButton::clicked, this, &Level2MainWindow::Pair33Clicked);
}

Level2MainWindow::~Level2MainWindow()
{
    delete ui;
}

void Level2MainWindow::startClicked(){
    barValue = 10;
    life = 5;
    ui->CorrectLabel->hide();
    ui->tryagain->hide();
    ui->progressBar->setValue(barValue);
    QPushButton* buttons[] = {ui->pair_1, ui->pair_2, ui->pair_3, ui->pair_1_1, ui->pair_2_2, ui->pair_3_3};
    for(int i = 0; i < 6; i++) {
        buttons[i]->setCheckable(true);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::iota(numbers.begin(), numbers.end(), 0);

    // Shuffle the vector to randomize order
    std::shuffle(numbers.begin(), numbers.end(), gen);

    problemPair = word.getRandomPair();
    buttons[0]->setText(problemPair.at(0).first);
    buttons[1]->setText(problemPair.at(1).first);
    buttons[2]->setText(problemPair.at(2).first);
    buttons[3]->setText(problemPair.at(numbers[0]).second);
    buttons[4]->setText(problemPair.at(numbers[1]).second);
    buttons[5]->setText(problemPair.at(numbers[2]).second);
}

void Level2MainWindow::Pair1Clicked() {
    ui->pair_2->setChecked(false);
    ui->pair_3->setChecked(false);
    if(ui->pair_1_1->isChecked() && ui->pair_1_1->isEnabled()) {
        if(ui->pair_1_1->text() == problemPair.at(0).second){
            ui->pair_1->setEnabled(false);
            ui->pair_1_1->setEnabled(false);
            ui->pair_1->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2_2->isChecked() && ui->pair_2_2->isEnabled()) {
        if(ui->pair_2_2->text() == problemPair.at(0).second){
            ui->pair_1->setEnabled(false);
            ui->pair_1->setChecked(false);
            ui->pair_2_2->setEnabled(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3_3->isChecked() && ui->pair_3_3->isEnabled()) {
        if(ui->pair_3_3->text() == problemPair.at(0).second){
            ui->pair_1->setEnabled(false);
            ui->pair_3_3->setEnabled(false);
            ui->pair_1->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}

void Level2MainWindow::Pair2Clicked() {
    ui->pair_1->setChecked(false);
    ui->pair_3->setChecked(false);

    if(ui->pair_1_1->isChecked() && ui->pair_1_1->isEnabled()) {
        if(ui->pair_1_1->text() == problemPair.at(1).second){
            ui->pair_2->setEnabled(false);
            ui->pair_2->setChecked(false);
            ui->pair_1_1->setEnabled(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2_2->isChecked() && ui->pair_2_2->isEnabled()) {
        if(ui->pair_2_2->text() == problemPair.at(1).second){
            ui->pair_2->setEnabled(false);
             ui->pair_2->setChecked(false);
            ui->pair_2_2->setEnabled(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3_3->isChecked() && ui->pair_3_3->isEnabled()) {
        if(ui->pair_3_3->text() == problemPair.at(1).second){
            ui->pair_2->setEnabled(false);
             ui->pair_2->setChecked(false);
            ui->pair_3_3->setEnabled(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}
void Level2MainWindow::Pair3Clicked() {
    ui->pair_1->setChecked(false);
    ui->pair_2->setChecked(false);
    if(ui->pair_1_1->isChecked() && ui->pair_1_1->isEnabled()) {
        if(ui->pair_1_1->text() == problemPair.at(2).second){
            ui->pair_3->setEnabled(false);
            ui->pair_1_1->setEnabled(false);
            ui->pair_3->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_3->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2_2->isChecked() && ui->pair_2_2->isEnabled()) {
        if(ui->pair_2_2->text() == problemPair.at(2).second){
            ui->pair_3->setEnabled(false);
            ui->pair_2_2->setEnabled(false);
            ui->pair_3->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_3->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3_3->isChecked() && ui->pair_3_3->isEnabled()) {
        if(ui->pair_3_3->text() == problemPair.at(2).second){
            ui->pair_1->setEnabled(false);
            ui->pair_3->setChecked(false);
            ui->pair_3_3->setEnabled(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}
void Level2MainWindow::Pair11Clicked() {
    ui->pair_2_2->setChecked(false);
    ui->pair_3_3->setChecked(false);
    if(ui->pair_1->isChecked() && ui->pair_1->isEnabled()) {
        if(ui->pair_1->text() == problemPair.at(numbers[0]).first){
            ui->pair_1->setEnabled(false);
            ui->pair_1_1->setEnabled(false);
            ui->CorrectLabel->show();
            ui->pair_1_1->setChecked(false);
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2->isChecked() && ui->pair_2->isEnabled()) {
        if(ui->pair_2->text() == problemPair.at(numbers[0]).first){
            ui->pair_2->setEnabled(false);
            ui->pair_1_1->setEnabled(false);
            ui->pair_1_1->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3->isChecked()&& ui->pair_3->isEnabled()) {
        if(ui->pair_3->text() == problemPair.at(numbers[0]).first){
            ui->pair_3->setEnabled(false);
            ui->pair_1_1->setEnabled(false);
            ui->pair_1_1->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_1_1->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}
void Level2MainWindow::Pair22Clicked() {
    ui->pair_1_1->setChecked(false);
    ui->pair_3_3->setChecked(false);
    if(ui->pair_1->isChecked() && ui->pair_1->isEnabled()) {
        if(ui->pair_1->text() == problemPair.at(numbers[1]).first){
            ui->pair_1->setEnabled(false);
            ui->pair_2_2->setEnabled(false);
            ui->pair_2_2->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2->isChecked() && ui->pair_2->isEnabled()) {
        if(ui->pair_2->text() == problemPair.at(numbers[1]).first){
            ui->pair_2->setEnabled(false);
            ui->pair_2_2->setEnabled(false);
            ui->pair_2_2->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3->isChecked() && ui->pair_3->isEnabled()) {
        if(ui->pair_3->text() == problemPair.at(numbers[1]).first){
            ui->pair_3->setEnabled(false);
            ui->pair_2_2->setEnabled(false);
            ui->pair_2_2->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_2_2->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}
void Level2MainWindow::Pair33Clicked() {
    ui->pair_2_2->setChecked(false);
    ui->pair_1_1->setChecked(false);
    if(ui->pair_1->isChecked() && ui->pair_1->isEnabled()) {
        if(ui->pair_1->text() == problemPair.at(numbers[2]).first){
            ui->pair_1->setEnabled(false);
            ui->pair_3_3->setEnabled(false);
            ui->pair_3_3->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    } else if(ui->pair_2->isChecked() && ui->pair_2->isEnabled()) {
        if(ui->pair_2->text() == problemPair.at(numbers[2]).first){
            ui->pair_2->setEnabled(false);
            ui->pair_3_3->setEnabled(false);
            ui->pair_3_3->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_2->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }

    } else if (ui->pair_3->isChecked() && ui->pair_3->isEnabled()) {
        if(ui->pair_3->text() == problemPair.at(numbers[2]).first){
            ui->pair_3->setEnabled(false);
            ui->pair_3_3->setEnabled(false);
            ui->pair_3_3->setChecked(false);
            ui->CorrectLabel->show();
            QTimer::singleShot(500, this, [this](){
                ui->CorrectLabel->hide();
            });
        } else {
            ui->pair_1->setChecked(false);
            ui->pair_3_3->setChecked(false);
            ui->tryagain->show();
            QTimer::singleShot(500, this, [this](){
                ui->tryagain->hide();
            });
        }
    }
}
