#ifndef DICTIONARY_H
#define DICTIONARY_H
/* Dictionary header for dictionary class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
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
