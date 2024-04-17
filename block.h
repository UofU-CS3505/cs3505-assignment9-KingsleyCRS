#ifndef BLOCK_H
#define BLOCK_H
#include <QString>

class Block
{
public:
    Block(QString name);
    const QString getName();
    bool isEmpty;
    bool canMove;
    bool canPush;

private:
    QString name;

};

#endif // BLOCK_H
