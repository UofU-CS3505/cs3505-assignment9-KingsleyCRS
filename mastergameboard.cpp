 #include "mastergameboard.h"
#include "qtimer.h"
#include <qpainterpath.h>

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(0),world(parent),levelWinTimerStart(0)
{
    for(int i = 0; i < 4;i++)
        levels[i] = new Map(i);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    setFocus();
    updateTimer = new QTimer(this);
    MapUpdateTimer = new QTimer(this);
    levelWinTimer = new QElapsedTimer();
    connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
    connect(MapUpdateTimer, &QTimer::timeout, this, &MasterGameBoard::triggerMapUpdate);
    updateTimer->start(1);
}
void MasterGameBoard::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        levels[currentLevel]-> movePlayer("left");
        break;
    case Qt::Key_D:
        levels[currentLevel]-> movePlayer("right");
        break;
    case Qt::Key_W:
        levels[currentLevel]-> movePlayer("up");
        break;
    case Qt::Key_S:
        levels[currentLevel]-> movePlayer("down");
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }
}

void MasterGameBoard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen textPen(Qt::white);
    painter.setPen(textPen);
    QFont font = painter.font();
    font.setPointSize(20);
    painter.setFont(font);
    Map *currentMap = levels[currentLevel];
    int blockSize = 30;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            int x = i * blockSize;
            int y = j * blockSize;
            if(!currentMap->map[i][j]->isEmpty)
                painter.drawText(QRect(x, y, blockSize, blockSize), Qt::AlignCenter, levels[currentLevel]->map[i][j]->getName());
        }
    }
    if(currentMap->win){
        playWinEffect(painter, event, currentMap);
    }

}
void MasterGameBoard::animation(){
        world.createWall("top",b2Vec2(0.0f, 19.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        world.createWall("bot",b2Vec2(0.0f, 0.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        world.createWall("left",b2Vec2(-10.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        world.createWall("right",b2Vec2(8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        world.createBody("Red",b2Vec2(-2.0f,10.0f),b2Vec2(100.0f, -100.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
        world.createBody("Blue",b2Vec2(0.0f,8.0f),b2Vec2(-10.0f, -10.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
}

bool MasterGameBoard::getMapWin(int level)
{
    return levels[level]->win;
}

void MasterGameBoard::triggerMapUpdate(){
    if(!levels[currentLevel]->playerDied)
        levels[currentLevel]->updateMap();
    update();
}

void MasterGameBoard::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
        painter.drawPixmap(x - pixmap.width()/2, y - pixmap.height()/2, pixmap);
    }
}
void MasterGameBoard::resetCurrentLevel() {

    levels[currentLevel] = new Map(currentLevel);
}

void MasterGameBoard::updateLevel()
{
    if(currentLevel < 4)
        currentLevel++;
}

void MasterGameBoard::playWinEffect(QPainter& painter, QPaintEvent *event, Map *currentMap)
{
    if(!levelWinTimerStart && !currentMap->passed){
        levelWinTimer->start();
        levelWinTimerStart = 1;
        animation();
    }
    if(levelWinTimer->elapsed() >= 5000){
        levelWinTimerStart = 0;
        world.destroyBody("Red");
        world.destroyBody("Blue");
        //赢时间结束后设置会原来的怎么设置
        resetCurrentLevel();
        currentMap->passed =1;
    }
    QPixmap pix(":/sky.jpg");//赢的时候设置背景
    painter.fillRect(event->rect(), pix);
    painter.setRenderHint(QPainter::Antialiasing);
    const float scaleFactor = 50;  // 50 pixels per meter
    const float offsetX = 800/2;  // Centering in width
    const float offsetY = 800;  // Aligning from the bottom
    painter.setRenderHint(QPainter::Antialiasing);
    QPen wallPen(Qt::white);
    wallPen.setWidth(0);
    painter.setPen(wallPen);
    painter.setBrush(Qt::darkGray);
    for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        if (body->GetType() == b2_staticBody) { // 检查是否为静态体（墙）
            b2Fixture* f = body->GetFixtureList();
            while (f) {
                b2PolygonShape* poly = dynamic_cast<b2PolygonShape*>(f->GetShape());
                if (poly) {
                    QPainterPath path;
                    for (int i = 0; i < poly->GetVertexCount(); ++i) {
                        b2Vec2 pt = body->GetWorldPoint(poly->GetVertex(i));
                        float x = pt.x * scaleFactor + offsetX;
                        float y = offsetY - pt.y * scaleFactor;  // Flipping Y coordinate for graphical display
                        if (i == 0) {
                            path.moveTo(x, y);
                        } else {
                            path.lineTo(x, y);
                        }
                    }
                    path.closeSubpath();
                    painter.drawPath(path);
                }
                f = f->GetNext();
            }
        } else {
            std::string* name = static_cast<std::string*>(body->GetUserData());
            if (name) {
                float x = body->GetPosition().x * scaleFactor + offsetX;
                float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
                if (*name == "Red") {
                    drawAnimation(painter, ":/plane1.png", x, y);
                } else if (*name == "Blue") {
                    drawAnimation(painter, ":/plane2.png", x, y);
                }
            }
        }
    }
}
