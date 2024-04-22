#include "noobmainwindow.h"
#include "ui_noobmainwindow.h"
#include <random>
#include <QFont>
#include <vector>
#include <algorithm>

noobMainWindow::noobMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::noobMainWindow)
    ,life(5)
    ,barValue(10)
    ,levelCount(1)
    ,correctCount(0)
{
    incorrectAnswers = {"天气", "朋友", "学校", "工作", "家庭",
                          "城市", "国家", "音乐", "电影", "食物",
                          "运动", "文化", "节日", "花园", "旅游",
                          "图书", "咖啡", "茶叶", "购物", "空气",
                          "河流", "山脉", "城堡", "银行", "医院",
                          "教室", "老师", "学生", "办公", "钢笔"};
    ui->setupUi(this);
    connect(ui->A, &QPushButton::clicked,this, &noobMainWindow::AClicked);
    connect(ui->B, &QPushButton::clicked,this, &noobMainWindow::BClicked);
    connect(ui->C, &QPushButton::clicked,this, &noobMainWindow::CClicked);
    connect(ui->D, &QPushButton::clicked,this, &noobMainWindow::DClicked);
    connect(ui->CheckButton, &QPushButton::clicked, this, &noobMainWindow::checkClicked);
    connect(ui->nextbutton, &QPushButton::clicked, this, &noobMainWindow::nextClicked);
    connect(ui->backButton, &QPushButton::clicked, this, &noobMainWindow::nextClicked);
    connect(ui->Restart, &QPushButton::clicked, this, &noobMainWindow::startClicked);
    connect(ui->Close, &QPushButton::clicked, this, &noobMainWindow::closeClicked);
}

noobMainWindow::~noobMainWindow()
{
    delete ui;
}
void noobMainWindow::startClicked(){
    // Ensure all widgets are properly initialized in the UI setup before being used.
    ui->end->setVisible(false);
    ui->Close->setVisible(false);
    ui->Restart->setVisible(false);
    ui->nextbutton->setVisible(false);
    ui->NextWidgets->setVisible(false);
    ui->NiceTry->setVisible(false);
    ui->WellDone->setVisible(false);
    ui->progressBar->setValue(barValue);
    ui->A->setVisible(true);
    ui->B->setVisible(true);
    ui->C->setVisible(true);
    ui->D->setVisible(true);
    ui->A->setChecked(false);
    ui->B->setChecked(false);
    ui->C->setChecked(false);
    ui->D->setChecked(false);

    // Initialize random number generation
    std::random_device rd;
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_int_distribution<> dist(0, 3); // Range 0 to 3

    // Create a list of numbers from 0 to 29
    std::vector<int> numbers(30);
    std::iota(numbers.begin(), numbers.end(), 0);  // Fill with 0, 1, 2, ..., 29

    // Shuffle the vector to randomize order
    std::shuffle(numbers.begin(), numbers.end(), gen);

    // Extract the first three numbers for non-repeating random indices
    int randomIndex = numbers[0];

    // Get the word pair; ensure getPairAt is safe to use
    questionWord = word.getPairAt(0, 0); // Assuming getPairAt is valid

    // Set font properties
    QFont font = ui->question->font();
    font.setPointSize(24);
    font.setBold(true);
    ui->question->setFont(font);
    ui->question->setText("\""+questionWord.second+"\"");

    // Randomly decide the correct button for the answer
    int answer = dist(gen);

    // Safe text assignment to buttons
    QPushButton* buttons[] = {ui->A, ui->B, ui->C, ui->D};

    for (int i = 0; i < 4; ++i) {
        if (i == answer) {
            buttons[i]->setText(questionWord.first);
        } else {
            buttons[i]->setText(incorrectAnswers[randomIndex++]);
        }
    }
}

void noobMainWindow::AClicked(){
    ui->A->setCheckable(true);
    ui->B->setChecked(false);
    ui->C->setChecked(false);
    ui->D->setChecked(false);
}

void noobMainWindow::BClicked(){
    ui->A->setChecked(false);
    ui->B->setCheckable(true);
    ui->C->setChecked(false);
    ui->D->setChecked(false);
}

void noobMainWindow::CClicked(){
    ui->A->setChecked(false);
    ui->B->setChecked(false);
    ui->C->setCheckable(true);
    ui->D->setChecked(false);
}

void noobMainWindow::DClicked(){
    ui->A->setChecked(false);
    ui->B->setChecked(false);
    ui->C->setChecked(false);
    ui->D->setCheckable(true);
}

void noobMainWindow::checkClicked(){
    // Set life label font properties
    QFont font = ui->lifeLabel->font();
    font.setPointSize(18);
    font.setBold(true); // Corrected: Set bold properly
    ui->lifeLabel->setFont(font);
    ui->lifeLabel->setStyleSheet("color: red;");
    ui->backButton->setVisible(false);
    ui->CheckButton->setVisible(false);
    // Hide all answer buttons
    ui->A->setVisible(false);
    ui->B->setVisible(false);
    ui->C->setVisible(false);
    ui->D->setVisible(false);

    // Show the next button
    ui->nextbutton->setVisible(true);

    // Determine the correct button and check if it was selected
    QPushButton* correctButton = nullptr;
    if(questionWord.first == ui->A->text()) correctButton = ui->A;
    else if(questionWord.first == ui->B->text()) correctButton = ui->B;
    else if(questionWord.first == ui->C->text()) correctButton = ui->C;
    else if(questionWord.first == ui->D->text()) correctButton = ui->D;

    // Check if the correct button was checked
    if(correctButton && correctButton->isChecked()){
        ui->NextWidgets->setVisible(true);
        ui->WellDone->setVisible(true);
        correctCount++;
    } else {
        ui->NextWidgets->setVisible(true);
        ui->NiceTry->setVisible(true);
        if(life > 0){
            life--;
            ui->lifeLabel->setText(QString::number(life));
        }
    }
}


void noobMainWindow::nextClicked(){
    if(levelCount < 1) {
        levelCount++;
        ui->backButton->setVisible(true);
        ui->CheckButton->setVisible(true);
        ui->A->setChecked(false);
        ui->B->setChecked(false);
        ui->C->setChecked(false);
        ui->D->setChecked(false);
        barValue += 10;
        ui->progressBar->setValue(barValue);
        ui->nextbutton->setVisible(false);
        ui->NextWidgets->setVisible(false);
        ui->NiceTry->setVisible(false);
        ui->WellDone->setVisible(false);
        ui->A->setVisible(true);
        ui->B->setVisible(true);
        ui->C->setVisible(true);
        ui->D->setVisible(true);

        // Initialize random number generation
        std::random_device rd;
        std::mt19937 gen(rd()); // Seed the generator
        std::uniform_int_distribution<> dist(0, 3); // Range 0 to 3

        // Create a list of numbers from 0 to 29
        std::vector<int> numbers(30);
        std::iota(numbers.begin(), numbers.end(), 0);  // Fill with 0, 1, 2, ..., 29

        // Shuffle the vector to randomize order
        std::shuffle(numbers.begin(), numbers.end(), gen);

        // Extract the first three numbers for non-repeating random indices
        int randomIndex = numbers[0];

        // Get the word pair; ensure getPairAt is safe to use
        questionWord = word.getPairAt(levelCount, 0); // Assuming getPairAt is valid

        // Set font properties
        QFont font = ui->question->font();
        font.setPointSize(24);
        font.setBold(true);
        ui->question->setFont(font);
        ui->question->setText("\""+questionWord.second+"\"");

        // Randomly decide the correct button for the answer
        int answer = dist(gen);

        // Safe text assignment to buttons
        QPushButton* buttons[] = {ui->A, ui->B, ui->C, ui->D};

        for (int i = 0; i < 4; ++i) {
            if (i == answer) {
                buttons[i]->setText(questionWord.first);
            } else {
                buttons[i]->setText(incorrectAnswers[randomIndex++]);
            }
        }
    } else {
        this->complete();
    }
}

void noobMainWindow::complete() {
    ui->end->setVisible(true);
    ui->Close->setVisible(true);
    ui->Restart->setVisible(true);
    ui->A->setVisible(false);
    ui->B->setVisible(false);
    ui->C->setVisible(false);
    ui->D->setVisible(false);
    QFont font = ui->congrat->font();
    font.setPointSize(22);
    font.setBold(true);
    ui->congrat->setFont(font);
    ui->congrat->setText("Congratulation!!! You have learned "+ QString::number(correctCount) +" of ten words");
}

void noobMainWindow::closeClicked() {
    this->close();
}
