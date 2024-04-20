#ifndef MAP_H
#define MAP_H
#include "block.h"
#include <QVector>
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

private:
    QVector<Block*> noun;
    QVector<Block*> adv;
    QVector<Block*> adj;
    int level;
    void checkRules();

};

#endif // MAP_H
