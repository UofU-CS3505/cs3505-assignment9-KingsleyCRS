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
    flipTimer->start(1200);  // 设置为50毫秒触发一次
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
void MasterMainWindow::animation(){
    world.createWall("left",b2Vec2(-8.0f, 1.0f),b2Vec2(0.5f, 8.0),0.5f,0.8f);
    world.createWall("bot",b2Vec2(8.0f, 1.0f),b2Vec2(0.5f, 8.0),0.5f,0.8f);
    world.createWall("right",b2Vec2(0.0f, 1.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
    world.createBody("dog1",b2Vec2(-7.5f,2.0f),b2Vec2(100.0f, 0.0f),b2Vec2(0.0f, -0.0f),1.0f,0.0f,0.0f,1.0f,true);

}
void MasterMainWindow::paintEvent(QPaintEvent *event) {
        QPainter painter(this);
        world.step();
        update();
        painter.setRenderHint(QPainter::Antialiasing);
        const float scaleFactor = 50;  // 50 pixels per meter
        const float offsetX = 1050/2;  // Centering in width
        const float offsetY = 800;  // Aligning from the bottom
        QPen wallPen(Qt::white);
        wallPen.setWidth(2);
        painter.setPen(wallPen);
        painter.setBrush(Qt::darkGray);


        for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
            qDebug()<<"s";
            if (body->GetType() == b2_staticBody) { // 检查是否为静态体（墙）
                b2Fixture* f = body->GetFixtureList();
                while (f) {
                    b2PolygonShape* poly = dynamic_cast<b2PolygonShape*>(f->GetShape());
                    if (poly) {
                        QPainterPath path;
                        for (int i = 0; i < poly->GetVertexCount(); ++i) {
                            b2Vec2 pt = body->GetWorldPoint(poly->GetVertex(i));
                            float x = pt.x * scaleFactor + offsetX;
                            float y = offsetY - pt.y * scaleFactor;  // Flipping Y coordinate for graphical display
                            if (i == 0) {
                                path.moveTo(x, y);
                            } else {
                                path.lineTo(x, y);
                            }
                        }
                        path.closeSubpath();
                        painter.drawPath(path);
                    }
                    f = f->GetNext();
                }
            } else {
                std::string* name = static_cast<std::string*>(body->GetUserData());
                if (name) {
                    float x = body->GetPosition().x * scaleFactor + offsetX;
                    float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
                    if (dogFlipped) {
                        drawFlippedAnimation(painter, ":/dog1.png", x, y);
                    } else {
                        drawAnimation(painter, ":/dog1.png", x, y);
                    }
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
    dogFlipped = !dogFlipped;  // 改变狗的反转状态
    update();  // 请求重绘界面以显示最新状态
}
void MasterMainWindow::drawFlippedAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        QTransform transform;
        transform.translate(x, y);
        transform.scale(-1, 1);  // 水平翻转图像
        pixmap = pixmap.transformed(transform);
        painter.drawPixmap(x - pixmap.width() / 2, y - pixmap.height() / 2, pixmap);
    }
}

