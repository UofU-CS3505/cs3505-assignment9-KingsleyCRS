#include "map.h"

Map::Map(int level):win(0),playerDied(0),passed(0),level(level)
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

void Map::updateMap()
{
    round++;
    if(level==3 && round%10==0){
        for(int i = 3; i < 17;i+=2){
            setBlock(i,4,new Block("箭"));
        }
    }
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if (map[i][j]->getName() == "箭") {
                map[i][j]->hasMoved = 0;
            }
        }
    }
    for (int j = 0; j < 19; j++) {
        for (int i = 0; i < 19; i++) {
            if(map[i][j]->getName()=="箭" && !map[i][j]->hasMoved){
                if(map[i][j+1]==player)
                    playerDied=1;
                if(map[i][j+1]->isEmpty ){
                    setBlock(i,j+1,map[i][j]);
                    map[i][j+1]->hasMoved = 1;
                    removeBlock(i,j);
                }else{
                    Block *b = map[i][j];
                    removeBlock(i,j);
                    delete b;
                }
            }
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
    map[i][j] = new Block();  //
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
                    checkCollision(i,j,0);
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
                    checkCollision(i,j,1);
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
                    checkCollision(i,j,2);
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
                    checkCollision(i,j,3);
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
                if((map[i+1][j]==can&&map[i+2][j]==move) || (map[i][j+1]==can&&map[i][j+2]==move)){
                    for(int k=1;k<noun.size();k++){
                        if(noun[k]->getName()==map[i][j]->getName())
                            noun[k]->canMove=true;
                    }
                }
            }
            if((map[i][j]==wall&&map[i+1][j]==can&&map[i+2][j]==push) || (map[i][j]==wall&&map[i][j+1]==can&&map[i][j+2]==push))
                noun[1]->canPush=true;
            if(level == 0){
                if((map[i][j]==dog&&map[i+1][j]==get&&map[i+2][j]==help) || (map[i][j]==dog&&map[i][j+1]==get&&map[i][j+2]==help))
                    win = 1;
            }
            else if(level == 1){
                if((map[i][j]==dog&&map[i+1][j]==eat&&map[i+2][j]==meat) || (map[i][j]==dog&&map[i][j+1]==eat&&map[i][j+2]==meat))
                    win = 1;
            }
            else if(level == 2){
                if((map[i][j]==player&&map[i+1][j]==goInTo&&map[i+2][j]==door) || (map[i][j]==player&&map[i][j+1]==eat&&map[i][j+2]==meat))
                    win = 1;
            }
            else if(level == 3){
                if((map[i][j]==player&&map[i+1][j]==find1&&map[i+2][j]==find2&&map[i+3][j]==treasure1&&map[i+4][j]==treasure2) || (map[i][j]==player&&map[i][j+1]==find1&&map[i][j+2]==find2&&map[i][j+3]==treasure1&&map[i][j+4]==treasure2))
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
    dog2 = new Block("狗",true);
    noun.push_back(dog2);
    get = new Block("得",true);
    help = new Block("救",true);
    eat = new Block("吃",true);
    meat = new Block("肉",true);
    can = new Block("能",true);
    push = new Block("推",true);
    move = new Block("动",true);
    find1 = new Block("找",true);
    find2 = new Block("到",true);
    treasure1 = new Block("宝",false);
    treasure2 = new Block("藏",false);
    water = new Block("水", true);
    fire = new Block("火", false);
    goInTo = new Block("进", true);
    door = new Block("门", false);
    arrow = new Block("箭", false);
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
        setBlock(8,8,meat);
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
        for(int i = 0;i<20;i++){
            setBlock(i,10,fire);
            setBlock(i,11,fire);
        }
        setBlock(4,16,water);
        setBlock(2,18,water);
        setBlock(4,5,dog);
        setBlock(10,5,door);
        setBlock(15,12,dog2);
        setBlock(7,7,can);
        setBlock(5,1,move);
        setBlock(18,18,goInTo);
    }
    else if(level == 3)
    {
        createEmptyMap();
        setBlock(4,4,player);

        for(int i = 0; i < 20;i++){
            setBlock(0,i,fire);
            setBlock(1,i,fire);
            setBlock(2,i,fire);
            setBlock(i,0,fire);
            setBlock(i,1,fire);
            setBlock(i,2,fire);
            setBlock(17,i,fire);
            setBlock(18,i,fire);
            setBlock(19,i,fire);
            setBlock(i,17,fire);
            setBlock(i,18,fire);
            setBlock(i,19,fire);
        }
        for(int i = 3; i < 17;i++){
            setBlock(3,i,wall);
            setBlock(i,3,wall);
            setBlock(16,i,wall);
            setBlock(i,16,wall);
        }
        setBlock(10,14,treasure1);
        setBlock(11,14,treasure2);
        setBlock(9,7,find1);
        setBlock(13,13,find2);
    }

}


QString Map::getHint()
{
    if(level == 0)
    {
        return "我:me/player 狗:dog 得:get 救:save";
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
        if(hintPressed == 0){
            hintPressed++;
            return "墙:wall 能:can 推:push";
        }
        else
            return "Make wall pushable, then get the meat";
    }
    else if(level == 3)
    {
        return "宝藏:Treasure, 找:Find";
    }
}

void Map::checkCollision(int i,int j, int dir)
{
    if(dir == 0){
        if(map[i-1][j] == water && map[i-2][j] == fire)
        {
            removeBlock(i-1,j);
            removeBlock(i-2,j);
        }
        if(map[i][j] == player && (map[i-1][j]== fire || map[i-1][j]== monster))
            playerDied = 1;
    }
    else if(dir == 1)
    {
        if(map[i+1][j] == water && map[i+2][j] == fire)
        {
            removeBlock(i+1,j);
            removeBlock(i+2,j);
        }
        if(map[i][j] == player && (map[i+1][j]== fire || map[i+1][j]== monster))
            playerDied = 1;
    }
    else if(dir == 2)
    {
        if(map[i][j-1] == water && map[i][j-2] == fire)
        {
            removeBlock(i,j-1);
            removeBlock(i,j-2);
        }
        if(map[i][j] == player && (map[i][j-1]== fire || map[i+1][j]== monster))
            playerDied = 1;
    }
    else
    {
        if(map[i][j+1] == water && map[i][j+2] == fire)
        {
            removeBlock(i,j+1);
            removeBlock(i,j+2);
        }
        if(map[i][j] == player && (map[i][j+1]== fire || map[i+1][j]== monster))
            playerDied = 1;
    }
}
