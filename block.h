#ifndef BLOCK_H
#define BLOCK_H
#include <QString>

class Block
{
public:
    Block(QString name);
    const QString getName();
    bool isEmpty;

private:
    QString name;
    bool canMove;
    bool canPush;


};

#endif // BLOCK_H
