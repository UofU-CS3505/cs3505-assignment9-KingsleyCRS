#include "map.h"
#include "iostream"

Map::Map(int level):level(level)
{
    if(level == 0)
    {
        Block* player = new Block("我");
        noun.push_back(player);
        Block* wall = new Block("墙",false);
        noun.push_back(wall);
        Block* dog = new Block("狗",true);
        noun.push_back(dog);
        Block* get = new Block("得",true);
        Block* help = new Block("救",true);
        createEmptyMap();
        setBlock(0,0,player);
        setBlock(1,0,wall);
        setBlock(3,3,dog);
        setBlock(15,15,get);
        setBlock(1,8,help);
        for(int i = 5; i< 10; i++)
            setBlock(i,5,wall);
        for(int i = 5; i < 10;i++)
            setBlock(5,i,wall);
    }
    else if(level == 1)
    {
        Block* player = new Block("我");
        noun.push_back(player);
        Block* wall = new Block("墙",false);
        noun.push_back(wall);
        Block* can = new Block("能",true);
        Block* push = new Block("推",true);
        Block* find1 = new Block("找",true);
        Block* find2 = new Block("到",true);
        Block* treasure1 = new Block("宝",true);
        Block* treasure2 = new Block("藏",true);
        createEmptyMap();
        setBlock(0,0,player);
        setBlock(3,3,find1);
        setBlock(3,4,find2);
        setBlock(18,18,can);
        setBlock(15,16,push);
        setBlock(7,7,treasure1);
        setBlock(7,8,treasure2);
        for(int i = 5; i< 10; i++)
            setBlock(i,5,wall);
        for(int i = 5; i< 11; i++)
            setBlock(i,10,wall);
        for(int i = 5; i < 10;i++)
            setBlock(5,i,wall);
        for(int i = 5; i < 11;i++)
            setBlock(10,i,wall);
    }
    else if(level == 2)
    {

    }
    else if(level == 3)
    {

    }
}

void Map::createEmptyMap()
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            map[i][j] = new Block(); // Dynamically allocates a Block for each pointer
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
    map[i][j] = new Block();
}
Map::~Map() {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            delete map[i][j];
            map[i][j] = nullptr;
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
void Map::movePlayer(QString direction)
{
    Direction dir = getDirection(direction);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if(map[i][j]->canMove)
            {
                switch (dir) {
                case LEFT:
                    if(i<=0)break;
                    if(map[i-1][j]->isEmpty){
                        setBlock(i-1,j,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    if(i>1 && map[i-1][j]->canPush && map[i-2][j]->isEmpty){
                        setBlock(i-2,j,map[i-1][j]);
                        setBlock(i-1,j,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }

                    break;
                case RIGHT:
                    if(i>=19)break;
                    if(map[i+1][j]->isEmpty){
                        setBlock(i+1,j,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    if(i<18 && map[i+1][j]->canPush && map[i+2][j]->isEmpty){
                        setBlock(i+2,j,map[i+1][j]);
                        setBlock(i+1,j,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    break;
                case UP:
                    if(j <= 0)break;
                    if(map[i][j-1]->isEmpty){
                        setBlock(i,j-1,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    if(j>1 && map[i][j-1]->canPush && map[i][j-2]->isEmpty){
                        setBlock(i,j-2,map[i][j-1]);
                        setBlock(i,j-1,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    break;
                case DOWN:
                    if(j>=19)break;
                    if(map[i][j+1]->isEmpty){
                        setBlock(i,j+1,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    if(i<18 && map[i][j+1]->canPush && map[i][j+2]->isEmpty){
                        setBlock(i,j+2,map[i][j+1]);
                        setBlock(i,j+1,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    break;
                }
                checkRules();
                return;
            }
        }
    }
}

void Map::checkRules(){
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            if(map[i][j]->isEmpty || !noun.contains(map[i][j]))continue;
            if((map[i][j]->getName()=="墙"&&map[i+1][j]->getName()=="能"&&map[i+2][j]->getName()=="推") || (map[i][j]->getName()=="墙"&&map[i][j+1]->getName()=="能"&&map[i][j+2]->getName()=="推"))
                    noun[1]->canPush=true;
            if(level == 0)
                if((map[i][j]->getName()=="狗"&&map[i+1][j]->getName()=="得"&&map[i+2][j]->getName()=="救") || (map[i][j]->getName()=="狗"&&map[i][j+1]->getName()=="得"&&map[i][j+2]->getName()=="救"))
                    gameWin(1);
            else if(level == 2);
        }
    }
}

void Map::gameWin(int i)
{
    std::cout << "WIN!!" <<std::endl;
}
