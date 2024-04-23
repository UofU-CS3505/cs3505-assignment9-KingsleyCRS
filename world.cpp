#include "world.h"

world::world(QObject *parent) : QObject(parent), box2DWorld(new b2World(b2Vec2(0.0f, 0.0f))) {
    setupWorld();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &world::step);
    timer->start(16);  // Approximately 60 Hz update rate
}

world::~world() {
    delete box2DWorld;
}

void world::setupWorld() {
    // Setup walls or other static elements if needed
}

void world::createBody(std::string name,const b2Vec2& position, const b2Vec2& F, const b2Vec2& V, float radius, float density, float friction, float restitution, bool isDynamic) {
    b2BodyDef bodyDef;
    if (isDynamic) {
        bodyDef.type = b2_dynamicBody;
    }
    bodyDef.position = position;
    b2Body* body = box2DWorld->CreateBody(&bodyDef);

    b2CircleShape circleShape;
    circleShape.m_radius = radius;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = density;
    fixtureDef.friction = friction;
    fixtureDef.restitution = restitution;

    body->CreateFixture(&fixtureDef);
    body->SetUserData(new std::string(name));
    body->ApplyForce(F,body->GetWorldCenter(),true);
    body->SetLinearVelocity(V);
}

void world::destroyBody(QString name) {
    for (b2Body* body = box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        std::string* userData = static_cast<std::string*>(body->GetUserData());
        if (userData && *userData == name.toStdString()) {
            box2DWorld->DestroyBody(body);
            delete userData; // Don't forget to delete the user data to prevent memory leaks
            break; // Assuming we only want to destroy one body with this name
        }
    }
}

void world::createWall( std::string name,const b2Vec2& position, const b2Vec2& size, float friction, float restitution){
    b2BodyDef WallBodyDef;
    WallBodyDef.position.Set(position.x,position.y);
    b2Body* Wall = box2DWorld->CreateBody(&WallBodyDef);
    b2PolygonShape WallBox;
    WallBox.SetAsBox(size.x, size.y);
    b2FixtureDef wallFixtureDef;
    wallFixtureDef.shape = &WallBox;
    wallFixtureDef.friction = friction;
    wallFixtureDef.restitution = restitution;
    Wall->CreateFixture(&wallFixtureDef);
    Wall->SetUserData(new std::string(name));
    // bodies[name] = body;
}
void world::clear() {
    // Properly destroy all bodies and clear the world
}

void world::step() {
    box2DWorld->Step(1.0f / 60.0f, 8, 3);
    emit updated();
}
// b2Body* world::getBody(const std::string& name) {
//     auto it = bodies.find(name);
//     if (it != bodies.end()) {
//         return it->second;
//     }
//     return nullptr;
// }
