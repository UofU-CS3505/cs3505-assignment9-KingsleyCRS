#include "map.h"

Map::Map(int level):win(0),passed(0),level(level)
{
    createWords();
    createMap();
}

void Map::createEmptyMap()
{
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 20; ++j) {
            map[i][j] = new Block();
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
    for(int i=0;i<noun.size();i++){
        noun[i]->hasMoved=false;
    }
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if(noun.contains(map[i][j])&&map[i][j]->canMove&&!map[i][j]->hasMoved)
            {
                map[i][j]->hasMoved=true;
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
                    if(j<18 && map[i][j+1]->canPush && map[i][j+2]->isEmpty){
                        setBlock(i,j+2,map[i][j+1]);
                        setBlock(i,j+1,map[i][j]);
                        removeBlock(i,j);
                        break;
                    }
                    break;
                }


            }
        }
    }
    checkRules();
}

void Map::checkRules(){
    noun[1]->canPush=false;
    for(int i=1;i<noun.size();i++)
        noun[i]->canMove=false;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if(map[i][j]->isEmpty || !noun.contains(map[i][j]))continue;
            if(noun.contains(map[i][j])){
                if((map[i+1][j]->getName()=="能"&&map[i+2][j]->getName()=="动") || (map[i][j+1]->getName()=="能"&&map[i][j+2]->getName()=="动"))
                    map[i][j]->canMove=true;
            }
            if((map[i][j]->getName()=="墙"&&map[i+1][j]->getName()=="能"&&map[i+2][j]->getName()=="推") || (map[i][j]->getName()=="墙"&&map[i][j+1]->getName()=="能"&&map[i][j+2]->getName()=="推"))
                    noun[1]->canPush=true;
            if(level == 0){
                if((map[i][j]->getName()=="狗"&&map[i+1][j]->getName()=="得"&&map[i+2][j]->getName()=="救") || (map[i][j]->getName()=="狗"&&map[i][j+1]->getName()=="得"&&map[i][j+2]->getName()=="救"))
                    win = 1;
            }
            else if(level == 1){
                    if((map[i][j]->getName()=="狗"&&map[i+1][j]->getName()=="吃"&&map[i+2][j]->getName()=="肉") || (map[i][j]->getName()=="狗"&&map[i][j+1]->getName()=="吃"&&map[i][j+2]->getName()=="肉"))
                        win = 1;
            }
        }
    }
}

void Map::createWords()
{
    player = new Block("我");
    noun.push_back(player);
    wall = new Block("墙",false);
    noun.push_back(wall);
    dog = new Block("狗",true);
    noun.push_back(dog);
    get = new Block("得",true);
    help = new Block("救",true);
    eat = new Block("吃",true);
    meat = new Block("肉",true);
    can = new Block("能",true);
    push = new Block("推",true);
    move = new Block("动",true);
    find1 = new Block("找",true);
    find2 = new Block("到",true);
    treasure1 = new Block("宝",true);
    treasure2 = new Block("藏",true);
}
void Map::createMap(){

    if(level == 0)
    {
        createEmptyMap();
        setBlock(0,0,player);
        setBlock(3,3,dog);
        setBlock(7,8,get);
        setBlock(1,8,help);
        for(int i = 0; i< 11; i++)
            setBlock(i,10,wall);
        for(int i = 0; i < 10;i++)
            setBlock(10,i,wall);
    }
    else if(level == 1)
    {
        createEmptyMap();
        setBlock(0,0,player);
        setBlock(3,3,dog);
        setBlock(7,2,eat);
        //meat set to 8,8
        setBlock(1,3,meat);
        setBlock(11,11,can);
        setBlock(15,12,push);
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

        createEmptyMap();
        setBlock(0,0,player);
        setBlock(13,0,dog);
        setBlock(3,9,dog);
        setBlock(2,10,can);
        setBlock(4,17,move);
        for(int i = 0; i< 20; i++){
            setBlock(10,i,wall);
            setBlock(9,i,wall);
        }

    }
    else if(level == 3)
    {

    }
}

QString Map::getHint()
{
    if(level == 0)
    {
        return "狗:dog 得:get 救:save";
    }
    else if(level == 1)
    {
        if(hintPressed == 0){
            hintPressed++;
            return "墙:wall 能:can 推:push";
        }
        else
            return "Make wall pushable, then get the meat";
    }
    else if(level == 2)
    {

    }
    else if(level == 3)
    {

    }
}
