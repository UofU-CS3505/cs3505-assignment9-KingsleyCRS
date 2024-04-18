#ifndef MODELFORMASTER_H
#define MODELFORMASTER_H
#include "block.h"
#include "map.h"
#include <QVector>
#include <QWidget>


class ModelForMaster:public QWidget
{
    Q_OBJECT

public:
    explicit ModelForMaster(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Block* player;
    Block* wall;
    Map* levels[5];
    int currentLevel;

};

#endif // MODELFORMASTER_H
