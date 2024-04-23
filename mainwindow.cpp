#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "iostream"
#include <QPainter>
#include <QPoint>
#include <QPaintEvent>
#include <string>
#include "levelmainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(parent)

{
    ui->setupUi(this);
    this->resize(800, 800);  // 设置窗口大小为800x800

    // 创建顶部的墙
    b2BodyDef topWallBodyDef;
    topWallBodyDef.position.Set(0.0f, 16.0f);  // 位置调整为场景的顶部边缘
    b2Body* topWall = world.Box2Dworld->CreateBody(&topWallBodyDef);
    b2PolygonShape topWallBox;
    topWallBox.SetAsBox(8.0f, 0.5f);
    b2FixtureDef wallFixtureDef;
    wallFixtureDef.shape = &topWallBox;
    wallFixtureDef.friction = 0.5f;
    wallFixtureDef.restitution = 0.8f;
    topWall->CreateFixture(&wallFixtureDef);

    b2BodyDef bottomWallBodyDef;
    bottomWallBodyDef.position.Set(0.0f, 0.0f);
    b2Body* bottomWall = world.Box2Dworld->CreateBody(&bottomWallBodyDef);
    b2PolygonShape bottomWallBox;
    bottomWallBox.SetAsBox(8.0f, 1.0f);
    b2FixtureDef wallFixtureDef1;
    wallFixtureDef1.shape = &bottomWallBox;
    wallFixtureDef1.friction = 0.5f;
    wallFixtureDef1.restitution = 0.8f;
    bottomWall->CreateFixture(&wallFixtureDef1);

    b2BodyDef leftWallBodyDef;
    leftWallBodyDef.position.Set(-8.0f, 8.0f);
    b2Body* leftWall = world.Box2Dworld->CreateBody(&leftWallBodyDef);
    b2PolygonShape leftWallBox;
    leftWallBox.SetAsBox(0.5f, 8.0f);
    b2FixtureDef wallFixtureDef2;
    wallFixtureDef2.shape = &leftWallBox;
    wallFixtureDef2.friction = 0.5f;
    wallFixtureDef2.restitution = 0.8f;
    leftWall->CreateFixture(&wallFixtureDef2);

    // 创建右侧的墙
    b2BodyDef rightWallBodyDef;
    rightWallBodyDef.position.Set(8.0f, 8.0f);  // 场景右侧中点
    b2Body* rightWall = world.Box2Dworld->CreateBody(&rightWallBodyDef);
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
    bodyDef.position.Set(7.0f, 8.0f);
    b2Body* circleBody = world.Box2Dworld->CreateBody(&bodyDef);
    b2CircleShape circleShape;
    circleShape.m_radius = 1.0f;
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.8f;
    circleBody->CreateFixture(&fixtureDef);
    circleBody->SetUserData(new std::string("Circle"));
    circleBody->SetLinearVelocity(b2Vec2(2.0f,25.0f));

    b2BodyDef bodyDef2;
    bodyDef2.type = b2_dynamicBody;
    bodyDef2.position.Set(7.0f, 2.0f);
    b2Body* boxBody = world.Box2Dworld->CreateBody(&bodyDef2);
    b2PolygonShape polygonShape;
    polygonShape.SetAsBox(1.0f, 0.5f);
    b2FixtureDef fixtureDef2;
    fixtureDef2.shape = &polygonShape;
    fixtureDef2.density = 1.0f;
    fixtureDef2.friction = 0.3f;
    fixtureDef2.restitution = 0.8f;
    boxBody->CreateFixture(&fixtureDef2);
    boxBody->SetUserData(new std::string("Box"));
    boxBody->SetLinearVelocity(b2Vec2(2.0f,25.0f));

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    for (int32 i = 0; i < 60; ++i) {
        world.Box2Dworld->Step(timeStep, velocityIterations, positionIterations);
        b2Vec2 position = world.body->GetPosition();
        float32 angle = world.body->GetAngle();
        std::cout << "Step " << i << ": x = " << position.x << ", y = " << position.y << ", angle = " << angle << std::endl;
    }


    connect(ui->noobButton,&QPushButton::clicked,this,&MainWindow::noobClicked);
    connect(ui->masterButton,&QPushButton::clicked,this,&MainWindow::masterClicked);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    timer->start(1000 / 60);


    QTimer* timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, [=]() {
        world.destroyScheduledBodies("Circle"); // 用正确的物体名称替换
    });
    timer2->setSingleShot(true);
    timer2->start(5000); // 5000毫秒后触发
}
MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::masterClicked(){
    master.show();
}
void MainWindow::noobClicked(){
    LevelMainWindow *levelWindow = new LevelMainWindow();  // Create an instance of LevelMainWsindow
    levelWindow->setAttribute(Qt::WA_DeleteOnClose);        // Ensure it will be deleted on close
    levelWindow->show();
}
void MainWindow::updatePhysics() {
    if (!world.body) return;  // Skip physics update if the body has been destroyed

    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    world.Box2Dworld->Step(timeStep, velocityIterations, positionIterations);
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {

    QPainter painter(this);


    QPixmap pix(":/BG.jpg");
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), pix);
    const float scaleFactor = 50;  // 50 pixels per meter
    const float offsetX = 800 / 2;  // Centering in width
    const float offsetY = 800;  // Aligning from the bottom
    for (b2Body* body = world.Box2Dworld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        float x = body->GetPosition().x * scaleFactor + offsetX;
        float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
        std::string* name = static_cast<std::string*>(body->GetUserData());
        if (name) {
            if (*name == "Circle") {
                drawAnimation(painter, ":/nihao.png", x, y);
            } else if (*name == "Box") {
                drawAnimation(painter, ":/welcome.png",x, y);
            }
        }
    }

}



void MainWindow::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
        painter.drawPixmap(x, y, pixmap);
    }
}
