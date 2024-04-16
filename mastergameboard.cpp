#include "mastergameboard.h"

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(1)
{
    currentLevel = 1;
    player = new Block("Player");
    wall = new Block("Wall");
    for(int i = 0; i < 5;i++)
        levels[i] = new Map(i);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
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
