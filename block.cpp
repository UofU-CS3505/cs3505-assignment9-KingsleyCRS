#include "block.h"

Block::Block(QString name) : isEmpty(true) , canMove(true) , canPush(false), name(name){}
const QString Block::getName()
{
    return name;
}
