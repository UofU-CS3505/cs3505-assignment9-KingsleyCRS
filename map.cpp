#include "map.h"

Map::Map(int level):level(level)
{
    if(level == 1)
    {
        Block* player = new Block("我");
        Block* wall = new Block("墙");
        createEmptyMap();
        setBlock(0,0,player);
        for(int i = 5; i< 10; i++)
            setBlock(i,5,wall);
        for(int i = 5; i < 10;i++)
            setBlock(5,i,wall);
    }
}

void Map::createEmptyMap()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            map[i][j] = new Block(""); // Dynamically allocates a Block for each pointer
        }
    }
}
void Map::setBlock(int i, int j, Block* block)
{
    map[i][j] = block;
    map[i][j]->isEmpty = false;
}

Map::~Map() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            delete map[i][j];
            map[i][j] = nullptr;
        }
    }
}


