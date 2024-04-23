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
    QPair<QString, QString> getUnknowPairAt(uint i);
    void deleteUnknowPairAt(uint i);
    void reset();
    uint AllWordsSize;
    uint unknowSize;

private:
    // level: words list: word meaning pair
    QVector<QPair<QString, QString>> allWords;
    QVector<QPair<QString, QString>> unKnow;
};

#endif // DICTIONARY_H
