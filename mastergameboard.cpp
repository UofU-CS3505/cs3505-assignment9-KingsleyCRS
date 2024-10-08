 #include "mastergameboard.h"
#include "qtimer.h"
#include <qpainterpath.h>

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(0),world(parent),displayingEffect(0)
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
    if(currentMap->win)
        playWinEffect(painter, displayingEffect);
    if(levelWinTimer->elapsed() >= 3000 || !currentMap->win){
        world.destroyBody("Red");
        world.destroyBody("Blue");
        displayingEffect = 0;
    }
}
void MasterGameBoard::animation(){
        world.createWall("top",b2Vec2(0.0f, 19.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        world.createWall("bot",b2Vec2(0.0f, 0.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        world.createWall("left",b2Vec2(-10.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        world.createWall("right",b2Vec2(8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        world.createBody("Red",b2Vec2(-7.0f,6.0f),b2Vec2(500.0f, 500.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
        world.createBody("Blue",b2Vec2(7.0f,16.0f),b2Vec2(-500.0f, -500.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
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

void MasterGameBoard::updateLevel()
{
    if(currentLevel < 4)
        currentLevel++;
}

void MasterGameBoard::playWinEffect(QPainter& painter, bool displaying)
{
    if(!displaying){
        levelWinTimer->start();
        animation();
    }
    displayingEffect = 1;
    const float scaleFactor = 50;
    const float offsetX = 800/2;
    const float offsetY = 800;
    painter.setRenderHint(QPainter::Antialiasing);
    QPen wallPen(Qt::white);
    wallPen.setWidth(0);
    painter.setPen(wallPen);
    painter.setBrush(Qt::darkGray);
    for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        if (body->GetType() == b2_staticBody) {
            b2Fixture* f = body->GetFixtureList();
            while (f) {
                b2PolygonShape* poly = dynamic_cast<b2PolygonShape*>(f->GetShape());
                if (poly) {
                    QPainterPath path;
                    for (int i = 0; i < poly->GetVertexCount(); ++i) {
                        b2Vec2 pt = body->GetWorldPoint(poly->GetVertex(i));
                        float x = pt.x * scaleFactor + offsetX;
                        float y = offsetY - pt.y * scaleFactor;
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
                float y = offsetY - body->GetPosition().y * scaleFactor;
                if (*name == "Red") {
                    drawAnimation(painter, ":/plane1.png", x, y);
                } else if (*name == "Blue") {
                    drawAnimation(painter, ":/plane.png", x, y);
                }
            }
        }
    }
}
