#include "block.h"

Block::Block(QString name) : isEmpty(true) , canMove(false) , canPush(false), name(name){}
const QString Block::getName()
{
    return name;
}
