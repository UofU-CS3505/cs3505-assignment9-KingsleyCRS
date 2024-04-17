#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "iostream"
#include <QPainter>
#include <QPoint>
#include <QPaintEvent>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(b2Vec2 (0.0f, 3.0f))

{
    ui->setupUi(this);
    this->resize(800, 800);  // 设置窗口大小为800x600

    // 创建顶部的墙
    b2BodyDef topWallBodyDef;
    topWallBodyDef.position.Set(0.0f, 15.5f);
    b2Body* topWall = world.CreateBody(&topWallBodyDef);

    b2PolygonShape topWallBox;
    topWallBox.SetAsBox(8.0f, 0.5f);  // 墙的半宽8米，半高0.5米
    b2FixtureDef wallFixtureDef;
    wallFixtureDef.shape = &topWallBox;
    wallFixtureDef.friction = 0.5f;
    wallFixtureDef.restitution = 0.8f;

    topWall->CreateFixture(&wallFixtureDef);

    // 创建动态的球体
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 0.0f);  // 初始位置在窗口底部中央
    b2Body* body = world.CreateBody(&bodyDef);


    b2CircleShape circleShape;
    circleShape.m_radius = 0.5f;  // 球体半径1米

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.8f;

    body->CreateFixture(&fixtureDef);
    float32 timeStep = 1.0f / 60.0f;
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


    QTimer* timer2 = new QTimer(this);
    connect(timer2, &QTimer::timeout, this, &MainWindow::destroyBody);
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
        float qt_x = body->GetPosition().x * scaleFactor + offsetX;
        float qt_y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display

        if (body->GetType() == b2_staticBody) {
            painter.setBrush(QBrush(Qt::gray));
            float wallHeightPixels = 0.5 * scaleFactor;
            float wallTopY = qt_y - wallHeightPixels;
            float wallBottomY = qt_y + wallHeightPixels;
            painter.drawRect(QRectF(offsetX - 400, wallTopY, 800, wallBottomY - wallTopY));
        } else if (body->GetType() == b2_dynamicBody) {

            drawRocket(painter,qt_x,qt_y);
        }
    }
}
void MainWindow::destroyBody() {
    if (body) {
        world.DestroyBody(body);
        body = nullptr;
        update();

    }
}
void MainWindow::drawRocket(QPainter &painter, int x, int y){
    int rocketCenterX = x;
    int rocketCenterY = y;

    painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(rocketCenterX - 10, rocketCenterY - 60, 20, 60);

    painter.setBrush(QBrush(Qt::red));
    QPoint points[3] = {
        QPoint(rocketCenterX, rocketCenterY - 70),
        QPoint(rocketCenterX - 10, rocketCenterY - 60),
        QPoint(rocketCenterX + 10, rocketCenterY - 60)
    };
    painter.drawPolygon(points, 3);

    painter.setBrush(QBrush(Qt::green));
    QPoint leftFin[3] = {
        QPoint(rocketCenterX - 10, rocketCenterY - 15),
        QPoint(rocketCenterX - 20, rocketCenterY),
        QPoint(rocketCenterX - 10, rocketCenterY)
    };
    painter.drawPolygon(leftFin, 3);

    QPoint rightFin[3] = {
        QPoint(rocketCenterX + 10, rocketCenterY - 15),
        QPoint(rocketCenterX + 20, rocketCenterY),
        QPoint(rocketCenterX + 10, rocketCenterY)
    };
    painter.drawPolygon(rightFin, 3);

    painter.setBrush(QBrush(Qt::yellow));
    QPoint flames[3] = {
        QPoint(rocketCenterX, rocketCenterY + 10),
        QPoint(rocketCenterX - 5, rocketCenterY + 25),
        QPoint(rocketCenterX + 5, rocketCenterY + 25)
    };
    painter.drawPolygon(flames, 3);
}
