#include "map.h"

Map::Map(int level):level(level),size(10)
{
    if(level == 0)
    {

        Block* map[size][size];
        Block* player = new Block("我");
        Block* wall = new Block("墙");
        createEmptyMap();
        setBlock(0,0,player);
        setBlock(1,0,wall);
        for(int i = 5; i< 10; i++)
            setBlock(i,5,wall);
        for(int i = 5; i < 10;i++)
            setBlock(5,i,wall);
    }
}

int Map::getSize()
{
    return size;
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

void Map::removeBlock(int i, int j)
{
    map[i][j] = new Block("");
}
Map::~Map() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            delete map[i][j];
            map[i][j] = nullptr;
        }
    }
}


