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
    void removeBlock(int i, int j);
    int getSize();

private:
    int level;
    int size;

};

#endif // MAP_H
