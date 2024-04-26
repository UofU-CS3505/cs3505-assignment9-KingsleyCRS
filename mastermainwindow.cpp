#include "mastermainwindow.h"
#include "qtimer.h"
#include "ui_mastermainwindow.h"
#include "world.h"
#include <qpainterpath.h>

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
{
    ui->setupUi(this);
    setFixedSize(880,720);
    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MasterMainWindow::levelWin);
    connect(&gamelose, &GameLoseDialog::accepted, this, &MasterMainWindow::handleDialog);
    timer->start(1000/60);
    animation();
    flipTimer = new QTimer(this);
    connect(flipTimer, &QTimer::timeout, this, &MasterMainWindow::flipDog);
    flipTimer->start(7500);
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
    ui->Goal->setText("Goal: Enter the Gate");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->update();
    ui->gameMap->setFocus();
}


void MasterMainWindow::on_Level4Button_clicked()
{
    ui->gameMap->currentLevel = 3;
    ui->Goal->setText("Goal: Find the Treasure");
    ui->Hint->setText("Hint:");
    ui->gameMap->levels[ui->gameMap->currentLevel]->hintPressed = 0;
    ui->gameMap->MapUpdateTimer->start(200);
    ui->gameMap->update();
    ui->gameMap->setFocus();
}



void MasterMainWindow::levelWin()
{
    for(int i = 0;i < 4;i++){
        if(ui->gameMap->levels[i]->win){
            if(i == 0)
                ui->Level2Button->setEnabled(true);
            else if(i == 1)
                ui->Level3Button->setEnabled(true);
            else if(i == 2)
                ui->Level4Button->setEnabled(true);
        }
        if(ui->gameMap->levels[i]->playerDied)
            gameLost();
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
}

void MasterMainWindow::handleDialog()
{
    ui->gameMap->levels[ui->gameMap->currentLevel]->playerDied = 0;
    on_resetButton_clicked();
}

void MasterMainWindow::on_nextLevelButton_clicked()
{
    ui->gameMap->updateLevel();
    if(ui->gameMap->currentLevel == 3)
        ui->gameMap->MapUpdateTimer->start(200);
    ui->nextLevelButton->setEnabled(false);
    ui->Hint->setText("Hint:");
    update();
    ui->gameMap->setFocus();
}
void MasterMainWindow::animation(){
    world.createWall("left",b2Vec2(-11.0f, 1.0f),b2Vec2(0.5f, 8.0),0.0f,0.0f);
    world.createWall("bot",b2Vec2(8.0f, 5.0f),b2Vec2(0.5f, 13.0),0.0f,0.0f);
    world.createWall("right",b2Vec2(0.0f, 1.0f),b2Vec2(8.0f, 0.5f),0.0f,0.0f);
    world.createBody("dog1",b2Vec2(-10.5f,3.0f),b2Vec2(0.0f, 0.0f),b2Vec2(1.1f, -0.0f),0.5f,0.0f,0.0f,1.00f,true);
}
void MasterMainWindow::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        world.step();
        update();
        QPixmap pix(":/importBG.png");
        painter.fillRect(event->rect(), pix);
        painter.setRenderHint(QPainter::Antialiasing);
        const float scaleFactor = 50;
        const float offsetX = 1050/2;
        const float offsetY = 800;
        QPen wallPen(Qt::white);
        wallPen.setWidth(2);
        painter.setPen(wallPen);
        painter.setBrush(Qt::darkGray);

        for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
                std::string* name = static_cast<std::string*>(body->GetUserData());
                if (name) {
                    float x = body->GetPosition().x * scaleFactor + offsetX;
                    float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
                    if (*name=="dog1") {
                        if(dogFlipped)
                            drawFlippedAnimation(painter, ":/dog1.png", x, y);
                        else
                            drawAnimation(painter,":/dog1.png", x, y);
                    }
                }
        }
}

void MasterMainWindow::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
        painter.drawPixmap(x - pixmap.width()/2, y - pixmap.height()/2, pixmap);
    }
}
void MasterMainWindow::flipDog() {
    dogFlipped = !dogFlipped;
    update();
}
void MasterMainWindow::drawFlippedAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        QTransform transform;
        transform.translate(x, y);
        transform.scale(-1, 1);
        pixmap = pixmap.transformed(transform);
        painter.drawPixmap(x - pixmap.width() / 2, y - pixmap.height() / 2, pixmap);
    }
}

