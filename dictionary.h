#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <QVector>
#include <QString>
#include <QPair>
class Dictionary
{
public:
    Dictionary();
    // set game level: which pair of dictionary
    bool setLevel(uint l);

    // get word, meaning pair
    QPair<QString, QString> getPairAt(uint i);
    QVector<QPair<QString, QString>> getRandomPair();
    uint numAllWords;

private:
    // level: words list: word meaning pair
    QVector<QPair<QString, QString>> allWords;
    QVector<QPair<QString, QString>> unKnow;

    // form 0 to 2
    uint level;
};

#endif // DICTIONARY_H
