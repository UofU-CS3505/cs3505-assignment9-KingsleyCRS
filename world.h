#ifndef WORLD_H
#define WORLD_H
/*
World header for World class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
#include <QObject>
#include <Box2D/Box2D.h>
#include <QTimer>

class world : public QObject {
    Q_OBJECT

public:
    explicit world(QObject *parent = nullptr);
    ~world();
    void createWall( std::string name,const b2Vec2& position, const b2Vec2& size, float friction, float restitution);
    void createBody( std::string name,const b2Vec2& position, const b2Vec2& F, const b2Vec2& V,float radius, float density, float friction, float restitution, bool isDynamic = true);
    void destroyBody(QString name);
    void clear();
    b2World* box2DWorld;
    b2Body* body;
signals:
    void updated();  // Signal to notify about updates (for repaint requests or similar)

public slots:
    void step();  // Slot to step the simulation
    // b2Body* getBody(const std::string& name);

private:
      // Pointer to the Box2D world
    QTimer* timer;        // Timer to trigger physics steps
    void setupWorld();
    // std::map<std::string, b2Body*> bodies;

};
#endif // WORLD_H
