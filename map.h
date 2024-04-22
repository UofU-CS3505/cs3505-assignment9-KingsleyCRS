#ifndef MAP_H
#define MAP_H
#include "block.h"
#include <QVector>
#include <QObject>

class Map
{
public:
    Map(int level);
    ~Map();
    Block* map[20][20];
    void createEmptyMap();
    void setBlock(int i, int j, Block* block);
    void removeBlock(int i, int j);
    void movePlayer(QString direction);
    bool isWall(QString dir,int i, int j);
    bool win;
    bool playerDied;
    bool passed;
    void createMap();
    void createWords();
    QString getHint();
    int hintPressed;

private:
    QVector<Block*> noun;
    QVector<Block*> adv;
    QVector<Block*> adj;
    int level;
    void checkRules();
    void checkCollision(int i, int j,int dir);
    Block* player;
    Block* wall;
    Block* dog;
    Block* get;
    Block* help;
    Block* eat;
    Block* meat;
    Block* can;
    Block* push;
    Block* move;
    Block* find1;
    Block* find2;
    Block* treasure1;
    Block* treasure2;
    Block* water;
    Block* fire;
    Block* princess1;
    Block* princess2;
    Block* monster1;
    Block* monster2;
    Block* sword;
};

#endif // MAP_H
