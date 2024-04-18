#ifndef MODELFORMASTER_H
#define MODELFORMASTER_H
#include "block.h"
#include "map.h"
#include <QVector>
#include <QObject>


class ModelForMaster:public QObject
{
    Q_OBJECT

public:
    explicit ModelForMaster(QObject *parent = nullptr);

protected:


private:
    Block* player;
    Block* wall;
    Map* levels[5];
    int currentLevel;

};

#endif // MODELFORMASTER_H
