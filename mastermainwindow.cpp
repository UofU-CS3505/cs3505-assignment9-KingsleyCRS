#include "mastermainwindow.h"
#include "qtimer.h"
#include "ui_mastermainwindow.h"

MasterMainWindow::MasterMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MasterMainWindow)
    //, world(parent)
{
    ui->setupUi(this);
    setFixedSize(800, 800);


    // b2BodyDef bodyDef;
    // bodyDef.type = b2_dynamicBody;
    // bodyDef.position.Set(7.0f, 8.0f);
    // b2Body* circleBody = world.Box2Dworld->CreateBody(&bodyDef);
    // b2CircleShape circleShape;
    // circleShape.m_radius = 1.0f;
    // b2FixtureDef fixtureDef;
    // fixtureDef.shape = &circleShape;
    // fixtureDef.density = 1.0f;
    // fixtureDef.friction = 0.3f;
    // fixtureDef.restitution = 0.8f;
    // circleBody->CreateFixture(&fixtureDef);
    // circleBody->SetUserData(new std::string("Circle"));
    // circleBody->SetLinearVelocity(b2Vec2(2.0f,25.0f));



    QTimer* timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&MasterMainWindow::levelWin);
    timer->start(1000/60);

    // QTimer *timer2 = new QTimer(this);
    // connect(timer2, &QTimer::timeout, this, &MasterMainWindow::updatePhysics);
    // timer2->start(1000 / 60);
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
    for(int i = 0;i < 5;i++){
        bool win = ui->gameMap->getMapWin(i);
        if(i == 0){
            if(win && !ui->gameMap->levels[i]->passed)
            {

                ui->gameMap->levels[i]->passed = 1;
                on_Level2Button_clicked();
                ui->Level2Button->setEnabled(true);


            }
            else if(ui->gameMap->levels[i]->playerDied)
            {
                gameLost(i);
            }
        }
        else if(i == 1)
        {
            if(win && !ui->gameMap->levels[i]->passed){
                ui->gameMap->levels[i]->passed = 1;
                on_Level3Button_clicked();
                ui->Level3Button->setEnabled(true);
            }
            else if(ui->gameMap->levels[i]->playerDied)
            {
                gameLost(i);
            }
        }
        else if(i == 2)
        {
            if(win && !ui->gameMap->levels[i]->passed){
                ui->gameMap->levels[i]->passed = 1;
                on_Level4Button_clicked();
                ui->Level4Button->setEnabled(true);
            }
            else if(ui->gameMap->levels[i]->playerDied)
            {
                gameLost(i);
            }
        }
        else if(i == 3)
        {
            if(win && !ui->gameMap->levels[i]->passed){
                ui->gameMap->levels[i]->passed = 1;
                on_Level5Button_clicked();
                ui->Level5Button->setEnabled(true);
            }
            else if(ui->gameMap->levels[i]->playerDied)
            {
                gameLost(i);
            }
        }
        else if(i == 4)
        {
            /*todo, player win the game*/
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

void MasterMainWindow::gameLost(int i){
    gamelose.show();
    on_resetButton_clicked();
    ui->gameMap->levels[i]->playerDied = 0;
}

// void MasterMainWindow::updatePhysics() {
//     if (!world.body) return;  // Skip physics update if the body has been destroyed

//     float32 timeStep = 1.0f / 60.0f;
//     int32 velocityIterations = 6;
//     int32 positionIterations = 2;
//     world.Box2Dworld->Step(timeStep, velocityIterations, positionIterations);
//     update();
// }

// void MasterMainWindow::paintEvent(QPaintEvent *event) {
//     QPainter painter(this);
//     const float scaleFactor = 50;  // 50 pixels per meter
//     const float offsetX = 800 / 2;  // Centering in width
//     const float offsetY = 800;  // Aligning from the bottom
//     for (b2Body* body = world.Box2Dworld->GetBodyList(); body != nullptr; body = body->GetNext()) {
//         float x = body->GetPosition().x * scaleFactor + offsetX;
//         float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
//         std::string* name = static_cast<std::string*>(body->GetUserData());
//         if (name) {
//             if (*name == "Circle") {
//                 drawAnimation(painter, ":/nihao.png", x, y);
//             }
//         }
//     }

// }
// void MasterMainWindow::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
//     QPixmap pixmap(imagePath);
//     if(!pixmap.isNull()) {
//         painter.drawPixmap(x, y, pixmap);
//     }
// }
