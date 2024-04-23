#include "world.h"

world::world(QObject *parent)
    : QObject(parent), Box2Dworld(new b2World(b2Vec2(0.0f, -9.8f))) { // 重力设置为 -9.8 m/s^2 向下
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &world::step);
    timer->start(1000 / 60); // 每秒更新60次
}
world::~world() {
    delete timer;
    delete Box2Dworld;
}

void world::step() {
    Box2Dworld->Step(1.0f / 60.0f, 6, 2);
    emit updated();
}
void world::destroyScheduledBodies(QString name) {
    for (b2Body* body = Box2Dworld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        std::string* userData = static_cast<std::string*>(body->GetUserData());
        if (userData && *userData == name.toStdString()) {
            Box2Dworld->DestroyBody(body);
            delete userData; // Don't forget to delete the user data to prevent memory leaks
            break; // Assuming we only want to destroy one body with this name
        }
    }
}
