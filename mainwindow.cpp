#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "iostream"
#include "ui_mastermainwindow.h"
#include <QPainter>
#include <QPoint>
#include <QPaintEvent>
#include <string>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(b2Vec2 (0.0f, -1.0f))

{
    ui->setupUi(this);
    this->resize(800, 800);  // 设置窗口大小为800x800
    // 创建顶部的墙
    b2BodyDef topWallBodyDef;
    topWallBodyDef.position.Set(0.0f, 16.0f);  // 位置调整为场景的顶部边缘
    b2Body* topWall = world.CreateBody(&topWallBodyDef);
    b2PolygonShape topWallBox;
    topWallBox.SetAsBox(8.0f, 0.5f);
    b2FixtureDef wallFixtureDef;
    wallFixtureDef.shape = &topWallBox;
    wallFixtureDef.friction = 0.5f;
    wallFixtureDef.restitution = 0.8f;
    topWall->CreateFixture(&wallFixtureDef);

    b2BodyDef bottomWallBodyDef;
    bottomWallBodyDef.position.Set(0.0f, 0.0f);
    b2Body* bottomWall = world.CreateBody(&bottomWallBodyDef);
    b2PolygonShape bottomWallBox;
    bottomWallBox.SetAsBox(8.0f, 1.0f);
    b2FixtureDef wallFixtureDef1;
    wallFixtureDef1.shape = &bottomWallBox;
    wallFixtureDef1.friction = 0.5f;
    wallFixtureDef1.restitution = 0.8f;
    bottomWall->CreateFixture(&wallFixtureDef1);

    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(-8.0f, 8.0f);
    b2Body* leftWall = world.CreateBody(&leftWallBodyDef);
    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(0.2f, 8.0f);
    b2FixtureDef wallFixtureDef2;
    wallFixtureDef2.shape = &leftWallBox;
    wallFixtureDef2.friction = 0.5f;
    wallFixtureDef2.restitution = 0.8f;
    leftWall->CreateFixture(&wallFixtureDef2);

    // 创建右侧的墙
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(8.0f, 8.0f);  // 场景右侧中点
    b2Body* rightWall = world.CreateBody(&rightWallBodyDef);
    b2PolygonShape rightWallBox;
    rightWallBox.SetAsBox(1.0f, 8.0f);
    b2FixtureDef wallFixtureDef3;
    wallFixtureDef3.shape = &rightWallBox;
    wallFixtureDef3.friction = 0.5f;
    wallFixtureDef3.restitution = 0.8f;
    rightWall->CreateFixture(&wallFixtureDef3);

    // 创建动态的球体
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(5.0f, 8.0f);
    b2Body* circleBody = world.CreateBody(&bodyDef);
    b2CircleShape circleShape;
    circleShape.m_radius = 1.0f;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.8f;
    circleBody->CreateFixture(&fixtureDef);
    circleBody->SetUserData(new std::string("Circle"));
    circleBody->SetLinearVelocity(b2Vec2(-3.0f,0.0f));
    float timeStep = 1.0f / 60.0f;


    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(-8.0f, 2.0f);
    b2Body* boxBody = world.CreateBody(&bodyDef2);
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(1.0f, 0.5f);
    b2FixtureDef fixtureDef2;
    fixtureDef2.shape = &polygonShape;
    fixtureDef2.density = 1.0f;
    fixtureDef2.friction = 0.3f;
    fixtureDef2.restitution = 0.8f;
    boxBody->CreateFixture(&fixtureDef2);
    boxBody->SetUserData(new std::string("Box"));
    boxBody->SetLinearVelocity(b2Vec2(0.0f,0.0f));
    b2Vec2 force = b2Vec2(0, 90.0f);
    boxBody->ApplyForce(force, boxBody->GetWorldCenter(), true);


    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    for (int32 i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = body->GetPosition();
        float32 angle = body->GetAngle();
        std::cout << "Step " << i << ": x = " << position.x << ", y = " << position.y << ", angle = " << angle << std::endl;
    }
    QString blue = "QPushButton{border-radius: 10px;background-color: rgb(14 , 150 , 254); color:white;}"
                   "QPushButton:hover{background-color: rgb(44 , 137 , 255); }"
                   "QPushButton:pressed{background-color:rgb(14 , 135 , 228);padding-left:3px; padding-top:3px; }";
    ui->noobButton->setStyleSheet(blue);
    QString red = "QPushButton{border-radius: 10px;background-color: rgb(255, 90, 32);; color:white;}"
                  "QPushButton:hover{background-color: rgb(255, 50, 22); }"
                  "QPushButton:pressed{background-color:rgb(255, 120, 25); padding-left:3px; padding-top:3px;}";
    ui->masterButton->setStyleSheet(red);
    connect(ui->noobButton,&QPushButton::clicked,this,&MainWindow::noobClicked);
    connect(ui->masterButton,&QPushButton::clicked,this,&MainWindow::masterClicked);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    timer->start(1000 / 60);

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::masterClicked(){
    master.show();
}
void MainWindow::noobClicked(){
    noob.show();
}
void MainWindow::updatePhysics() {
    if (!body) return;  // Skip physics update if the body has been destroyed

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    world.Step(timeStep, velocityIterations, positionIterations);
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    const float scaleFactor = 50;  // 50 pixels per meter
    const float offsetX = 800 / 2;  // Centering in width
    const float offsetY = 800;  // Aligning from the bottom
    for (b2Body* body = world.GetBodyList(); body != nullptr; body = body->GetNext()) {
        float x = body->GetPosition().x * scaleFactor + offsetX;
        float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
        std::string* name = static_cast<std::string*>(body->GetUserData());
        if (name) {
            if (*name == "Circle") {
                drawTextExample(painter,x,y);
            } else if (*name == "Box") {
                //drawRocket(painter,x,y);
            }
        }
    }
}

void MainWindow::drawTextExample(QPainter &painter, int x, int y){
    QFont font("STSong", 60, QFont::Bold);
    font.setPointSize(50);
    painter.setFont(font);
    painter.setPen(Qt::blue);
    painter.drawText(x, y, "👋你好");
}
// void MainWindow::drawRocket(QPainter &painter, int x, int y){
//     QPixmap pixmap("/Users/liang/Projects/cs3505-assignment9-KingsleyCRS/rocket.png");
//     QPixmap scalePixmap = pixmap.scaled(150, 150, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//     painter.drawPixmap(x, y, scalePixmap);
// }
