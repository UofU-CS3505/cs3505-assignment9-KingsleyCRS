#include "block.h"

Block::Block(QString name) : name(name) , canMove(false) , canPush(false), isEmpty(true){}
const QString Block::getName()
{
    return name;
}
