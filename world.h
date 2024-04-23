#ifndef WORLD_H
#define WORLD_H
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QObject>
#include <QList>
#include <QString>

class world: public QObject
{
    Q_OBJECT
public:
public:
    explicit world(QObject *parent = nullptr);
    ~world();

    void step(); // 执行物理世界的单步模拟
public slots:
    void destroyScheduledBodies(QString name);
signals:
    void updated(); // 当世界更新时发出的信号


public:
    b2World *Box2Dworld; // Box2D 世界
    QTimer *timer; // 用于定期更新物理世界
    b2Body *body;

};

#endif // WORLD_H
