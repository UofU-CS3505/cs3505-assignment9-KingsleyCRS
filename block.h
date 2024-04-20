#ifndef BLOCK_H
#define BLOCK_H
#include <QString>

class Block
{
public:
    Block();
    Block(QString name);
    Block(QString name,bool canPush);
    const QString getName();
    bool isEmpty;
    bool canMove;
    bool canPush;

private:
    QString name;

};

#endif // BLOCK_H
