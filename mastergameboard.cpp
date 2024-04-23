 #include "mastergameboard.h"
#include "qtimer.h"

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(0),world(parent),levelWinTimerStart(0)
{
    for(int i = 0; i < 5;i++)
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
    int blockSize = 40;
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            int x = i * blockSize;
            int y = j * blockSize;
            if(!currentMap->map[i][j]->isEmpty)
                painter.drawText(QRect(x, y, blockSize, blockSize), Qt::AlignCenter, levels[currentLevel]->map[i][j]->getName());
        }
    }
    if(currentMap->win){
        if(!levelWinTimerStart && !currentMap->passed){
            levelWinTimer->start();
            levelWinTimerStart = 1;
            animation();
        }
        if(levelWinTimer->elapsed() >= 5000){
            levelWinTimerStart = 0;
            world.destroyBody("Box");
            currentMap->passed =1;
        }
        painter.setRenderHint(QPainter::Antialiasing);
        const float scaleFactor = 50;  // 50 pixels per meter
        const float offsetX = 800;  // Centering in width
        const float offsetY = 800;  // Aligning from the bottom
        for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
            float x = body->GetPosition().x * scaleFactor + offsetX;
            float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
            std::string* name = static_cast<std::string*>(body->GetUserData());
            if (name) {
                if (*name == "Circle") {
                    //drawAnimation(painter, ":/nihao.png", x, y);
                } else if (*name == "Box") {
                    drawAnimation(painter, ":/welcome.png",x, y);
                }
            }
        }
    }

}
void MasterGameBoard::animation(){
        // world.createWall("top",b2Vec2(0.0f, 19.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        // world.createWall("bot",b2Vec2(0.0f, 0.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
        // world.createWall("left",b2Vec2(-8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        // world.createWall("right",b2Vec2(8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
        world.createBody("Box",b2Vec2(-20.0f, 20.0f),b2Vec2(100.0f, -100.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
        world.createBody("Circle",b2Vec2(2.0f, 2.0f),b2Vec2(-10.0f, -10.0f),b2Vec2(0.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);
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
        painter.drawPixmap(x, y, pixmap);
    }
}
