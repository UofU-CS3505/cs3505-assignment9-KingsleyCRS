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
    QTimer *updateTimer;
    QTimer *MapUpdateTimer;
    QElapsedTimer *levelWinTimer;
    world world;
    void animation();
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
    void playWinEffect(QPainter& painter, bool displayingEffect);
    bool displayingEffect;
public slots:
    void triggerMapUpdate();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;


};
#endif // MASTERGAMEBOARD_H
