#include "block.h"

Block::Block() : isEmpty(true) , canMove(false) , canPush(false), name(""){
}


Block::Block(QString name) : isEmpty(false) , canMove(false) , canPush(false), name(name){
    if(name=="我")canMove = true;
}


Block::Block(QString name,bool push) : isEmpty(false) , canMove(false) , canPush(push), name(name){
}
const QString Block::getName()
{
    return name;
}
