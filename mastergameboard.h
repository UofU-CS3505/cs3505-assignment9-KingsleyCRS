#ifndef MASTERGAMEBOARD_H
#define MASTERGAMEBOARD_H
#include "map.h"
#include <QVector>
#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "world.h"
#include <QElapsedTimer>

class MasterGameBoard:public QWidget
{
    Q_OBJECT

public:
    explicit MasterGameBoard(QWidget *parent);
    void updateLevel();
    int currentLevel;
    Map* levels[5];
    bool getMapWin(int level);
    QTimer *updateTimer;
    QTimer *MapUpdateTimer;
    QElapsedTimer *levelWinTimer;
    world world;
    void animation();
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
    bool levelWinTimerStart;
    void resetCurrentLevel();
    void playWinEffect(QPainter& painter, QPaintEvent *event, Map *currentMap);
public slots:
    void triggerMapUpdate();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;


};
#endif // MASTERGAMEBOARD_H
