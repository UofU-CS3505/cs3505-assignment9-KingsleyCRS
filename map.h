#ifndef MAP_H
#define MAP_H
#include "block.h"

class Map
{
public:
    Map(int level);
    ~Map();
    Block* map[10][10];
    void createEmptyMap();
    void setBlock(int i, int j, Block* block);

private:
    int level;

};

#endif // MAP_H
