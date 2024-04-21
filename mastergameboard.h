#ifndef MASTERGAMEBOARD_H
#define MASTERGAMEBOARD_H
#include "map.h"
#include <QVector>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>

class MasterGameBoard:public QWidget
{
    Q_OBJECT

public:
    explicit MasterGameBoard(QWidget *parent);
    void updateLevel(int level);
    int currentLevel;


protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    Map* levels[5];

};
#endif // MASTERGAMEBOARD_H
