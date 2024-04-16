#ifndef MASTERGAMEBOARD_H
#define MASTERGAMEBOARD_H
#include "block.h"
#include "map.h"
#include <QVector>
#include <QWidget>
#include <QPainter>

class MasterGameBoard:public QWidget
{
    Q_OBJECT

public:
    explicit MasterGameBoard(QWidget *parent);
    void updateLevel(int level);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Block* player;
    Block* wall;
    Map* levels[5];
    int currentLevel;

};
#endif // MASTERGAMEBOARD_H
