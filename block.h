#ifndef BLOCK_H
#define BLOCK_H
#include <QString>
/*
block header for block class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
class Block
{
public:
    Block();
    ~Block();
    Block(QString name);
    Block(QString name,bool canPush);
    const QString getName();
    bool isEmpty;
    bool canMove;
    bool canPush;
    bool hasMoved;

private:
    QString name;

};

#endif // BLOCK_H
