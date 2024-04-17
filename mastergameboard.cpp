#include "mastergameboard.h"

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(0)
{
    for(int i = 0; i < 5;i++)
        levels[i] = new Map(i);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    setFocusPolicy(Qt::StrongFocus);
}
void MasterGameBoard::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_A:
        movePlayer("left");
        break;
    case Qt::Key_D:
        movePlayer("right");
        break;
    case Qt::Key_W:
        movePlayer("up");
        break;
    case Qt::Key_S:
        movePlayer("down");
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }
    update();
}

void MasterGameBoard::updateLevel(int level)
{

}

void MasterGameBoard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen textPen(Qt::white);
    painter.setPen(textPen);
    QFont font = painter.font();
    font.setPointSize(18);
    painter.setFont(font);
    Map *currentMap = levels[currentLevel];
    int blockSize = 60;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            int x = i * blockSize;
            int y = j * blockSize;
            if(!currentMap->map[i][j]->isEmpty)
                painter.drawText(QRect(x, y, blockSize, blockSize), Qt::AlignCenter, levels[currentLevel]->map[i][j]->getName());
        }
    }
}
enum Direction { LEFT, RIGHT, UP, DOWN };

Direction getDirection(const QString& direction) {
    if (direction == "left") return LEFT;
    if (direction == "right") return RIGHT;
    if (direction == "up") return UP;
    if (direction == "down") return DOWN;
}
void MasterGameBoard::movePlayer(QString direction)
{
    Direction dir = getDirection(direction);
    Map *currentMap = levels[currentLevel];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(currentMap->map[i][j]->getName().startsWith("我"))
            {
                switch (dir) {
                case LEFT:
                    if(j > 1){
                        currentMap->setBlock(i-1,j,currentMap->map[i][j]);
                        currentMap->removeBlock(i,j);
                    }
                    break;
                case RIGHT:
                    if(j < 9){
                        currentMap->setBlock(i+1,j,currentMap->map[i][j]);
                        currentMap->removeBlock(i,j);
                    }
                    break;
                case UP:
                    if(i < 9){
                        currentMap->setBlock(i,j-1,currentMap->map[i][j]);
                        currentMap->removeBlock(i,j);
                    }
                    break;
                case DOWN:
                    if(i > 1){
                        currentMap->setBlock(i,j+1,currentMap->map[i][j]);
                        currentMap->removeBlock(i,j);
                    }
                    break;
                }
                return;
            }
        }
    }
}
