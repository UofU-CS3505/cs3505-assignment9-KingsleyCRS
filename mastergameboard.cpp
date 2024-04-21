 #include "mastergameboard.h"

MasterGameBoard::MasterGameBoard(QWidget *parent) : QWidget(parent), currentLevel(0)
{
    for(int i = 0; i < 5;i++)
        levels[i] = new Map(i);
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
    setFocus();
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
    update();
}

void MasterGameBoard::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen textPen(Qt::white);
    painter.setPen(textPen);
    QFont font = painter.font();
    font.setPointSize(18);
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
}

