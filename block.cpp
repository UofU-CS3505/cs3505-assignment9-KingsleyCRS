#include "block.h"

Block::Block() : isEmpty(true) , canMove(false) , canPush(false), hasMoved(false),name(""){
}

Block::~Block(){

}
Block::Block(QString name) : isEmpty(false) , canMove(false) , canPush(false), hasMoved(false),name(name){
    if(name=="我")canMove = true;
}


Block::Block(QString name,bool push) : isEmpty(false) , canMove(false) , canPush(push), hasMoved(false),name(name){
}
const QString Block::getName()
{
    return name;
}
