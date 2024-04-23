#include "windialog.h"
#include "ui_windialog.h"
#include <QPaintEvent>
#include <QPainter>
#include "iostream"
#include <QPainterPath>


winDialog::winDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::winDialog)
    , world(parent)
{
    ui->setupUi(this);
    this->resize(800, 800);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &winDialog::updatePhysics);
    timer->start(1000 / 60);
    world.createWall("top",b2Vec2(0.0f, 16.0f),b2Vec2(8.0f, 1.5f),0.5f,0.8f);
    world.createWall("bot",b2Vec2(0.0f, 0.0f),b2Vec2(8.0f, 1.5f),0.5f,0.8f);
    world.createWall("left",b2Vec2(-8.0f, 8.0f),b2Vec2(1.5f, 8.0f),0.5f,0.8f);
    world.createWall("right",b2Vec2(8.0f, 8.0f),b2Vec2(1.5f, 8.0f),0.5f,0.8f);

    // b2BodyDef planeB;
    // planeB.type = b2_dynamicBody;
    // planeB.position.Set(-5.0f, 5.0f);
    // b2Body* boxBodyB = world.Box2Dworld->CreateBody(&planeB);
    // b2CircleShape circleShapeB;
    // circleShapeB.m_radius = 1.0f;
    // b2FixtureDef fixtureDefplaneB;
    // fixtureDefplaneB.shape = &circleShapeB;
    // fixtureDefplaneB.density = 1.0f;
    // fixtureDefplaneB.friction = 0.0f;
    // fixtureDefplaneB.restitution = 0.8f;
    // boxBodyB->CreateFixture(&fixtureDefplaneB);
    // boxBodyB->SetUserData(new std::string("planeB"));
    // // boxBody->SetLinearVelocity(b2Vec2(1.0f,1.0f));
    // b2Vec2 forceB = b2Vec2(10.0f, 10.0f);
    // // 设置施力点，这里是刚体的质心
    // b2Vec2 pointB = boxBodyB->GetWorldCenter();
    // // 第一个参数是施加的力，第二个参数是力的作用点
    // boxBodyB->ApplyForce(forceB, pointB, true);

    // b2BodyDef planeR;
    // planeR.type = b2_dynamicBody;
    // planeR.position.Set(7.0f, 13.0f);
    // b2Body* boxBodyR = world.Box2Dworld->CreateBody(&planeR);
    // b2CircleShape circleShapeR;
    // circleShapeR.m_radius = 1.0f;
    // b2FixtureDef fixtureDefplaneR;
    // fixtureDefplaneR.shape = &circleShapeR;
    // fixtureDefplaneR.density = 1.0f;
    // fixtureDefplaneR.friction = 0.0f;
    // fixtureDefplaneR.restitution = 0.8f;
    // boxBodyR->CreateFixture(&fixtureDefplaneR);
    // boxBodyR->SetUserData(new std::string("planeR"));
    // // boxBody->SetLinearVelocity(b2Vec2(1.0f,1.0f));
    // b2Vec2 forceR = b2Vec2(-10.0f, -10.0f);
    // // 设置施力点，这里是刚体的质心
    // b2Vec2 pointR = boxBodyR->GetWorldCenter();
    // // 第一个参数是施加的力，第二个参数是力的作用点
    // boxBodyR->ApplyForce(forceR, pointR, true);

    world.createBody("planeR",b2Vec2(-5.0f, 5.0f),b2Vec2(10.0f, 10.0f),b2Vec2(0.0f, 0.0f),1.0f,1.0f,0.0f,0.8f,true);
    world.createBody("planeB",b2Vec2(7.0f, 13.0f),b2Vec2(-10.0f, -10.0f),b2Vec2(0.0f,0.0f),1.0f,1.0f,0.0f,0.8f,true);

}

winDialog::~winDialog()
{
    delete ui;
}
void winDialog::updatePhysics() {
    if (!world.body) return;
    qDebug()<<"s";
    world.step();
    update();
}
void winDialog::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const float scaleFactor = 50;  // 50 pixels per meter
    const float offsetX = 800 / 2;  // Centering in width
    const float offsetY = 800;  // Aligning from the bottom

    for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        float x = body->GetPosition().x * scaleFactor + offsetX;
        float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display

        std::string* name = static_cast<std::string*>(body->GetUserData());
        if (name) {
            if (*name == "planeB") {
                drawAnimation(painter, ":/plane", x, y);

            } else if (*name == "planeR") {
                drawAnimation(painter, ":/plane1", x, y);
            }
        } /*else {
            // 绘制墙体
            for (auto& wallName : {"top", "bot", "left", "right"}) {
                b2Body* wallBody = world.getBody(wallName); // 确保这样的方法存在
                if (wallBody) {
                    const b2Transform& xf = wallBody->GetTransform();
                    for (b2Fixture* f = wallBody->GetFixtureList(); f; f = f->GetNext()) {
                        b2PolygonShape* poly = (b2PolygonShape*)f->GetShape();
                        const int vertexCount = poly->m_count;
                        QPainterPath path;
                        for (int i = 0; i < vertexCount; ++i) {
                            b2Vec2 transformedVec = b2Mul(xf, poly->m_vertices[i]);
                            float x = transformedVec.x * scaleFactor + offsetX;
                            float y = offsetY - transformedVec.y * scaleFactor;  // Flipping Y coordinate
                            if (i == 0) {
                                path.moveTo(x, y);
                            } else {
                                path.lineTo(x, y);
                            }
                        }
                        path.closeSubpath();
                        painter.drawPath(path);
                    }
                }
            }
        }*/
    }
}
void winDialog::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
         painter.drawPixmap(x - pixmap.width()/2, y - pixmap.height()/2, pixmap);
    }
}

