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
    Map* levels[5];
    bool getMapWin(int level);
    QTimer *timer1;
    QTimer *timer2;

public slots:
    void triggerMapUpdate();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

};
#endif // MASTERGAMEBOARD_H
