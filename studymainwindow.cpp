#include "studymainwindow.h"
#include "ui_studymainwindow.h"
#include <random>

studyMainWindow::studyMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::studyMainWindow)
{
    ui->setupUi(this);
    connect(ui->restartBT, &QPushButton::clicked,this, &studyMainWindow::startClicked);
    connect(ui->knowBT, &QPushButton::clicked,this, &studyMainWindow::knowClicked);
    connect(ui->unknowBT, &QPushButton::clicked,this, &studyMainWindow::unknowClicked);
}

studyMainWindow::~studyMainWindow()
{
    delete ui;
}

void studyMainWindow::startClicked(){
    barValue = 10;
    words.reset();
    ui->unknowBT->setEnabled(true);
    ui->knowBT->setEnabled(true);
    ui->progressBar->setMaximum(words.AllWordsSize);
    ui->progressBar->setValue(0);

    // print one words
    printNext();
}

void studyMainWindow::knowClicked(){
    words.deleteUnknowPairAt(learningAt);
    if (!printNext()){
        ui->unknowBT->setEnabled(false);
        ui->knowBT->setEnabled(false);
        ui->chineseLable->setText("Finished!!! Congratulation!");
        ui->englishLable->setText("Try Next Level");
        ui->progressBar->setValue(words.AllWordsSize);
    } else {
        ui->progressBar->setValue(words.AllWordsSize - words.unknowSize);
    }
}

void studyMainWindow::unknowClicked(){
    printNext();
}

bool studyMainWindow::printNext(){
    if (words.unknowSize == 0)
        return false;
    // get next random word
    std::random_device rd;
    std::mt19937 gen(rd());
    // Define the range
    std::uniform_int_distribution<> distrib(0, words.unknowSize-1);
    learningAt = distrib(gen);
    auto t = words.getUnknowPairAt(learningAt);
    ui->chineseLable->setText(t.first);
    ui->englishLable->setText(t.second);
    return true;
}

void studyMainWindow::closeClicked() {
    this->close();
}


