#include "dictionary.h"
#include <random>
#include <set>

Dictionary::Dictionary() {
    // three level in total
    allWords = {
        {"我","I， Me"},{"你好","Hello; Hi"},{"狗", "Dog"},{"得", "Have to; \n Get something"},
        {"救", "Rescue, Save"}, {"吃","Eat"}, {"肉","Meat"},
        {"人","Human"},{"他们","They"},{"我们","We"},
        {"老师","Teacher"},{"能","Can"},{"墙","Wall"},
        {"推","Push"},{"动","Move"},{"找","Find"},
        {"找到","Found"},{"宝藏","Precious deposits"},{"水","Water"},
        {"火","Fire"},{"进","Enter"}, {"门","Door"},
        {"箭","Arrow"}
    };
    unKnow = allWords;

    // make sure all level have same words number
    AllWordsSize = allWords.count();
    unknowSize = AllWordsSize;
}

QPair<QString, QString> Dictionary::getPairAt(uint i){
    return allWords[i];
}

QPair<QString, QString> Dictionary::getUnknowPairAt(uint i){
    return unKnow[i];
}

void Dictionary::deleteUnknowPairAt(uint i){
    unKnow.removeAt(i);
    unknowSize = unKnow.count();
}

QVector<QPair<QString, QString>> Dictionary::getRandomPair(){
    QVector<QPair<QString, QString>> a;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, AllWordsSize-1);

    std::set<int> unique_numbers;
    while (unique_numbers.size() < 4) {
        int number = distrib(gen);
        unique_numbers.insert(number);
    }
    for (auto t : unique_numbers){
        a.push_back(allWords[t]);
    }
    return a;
}

void Dictionary::reset(){
    unKnow = allWords;
    unknowSize = unKnow.size();
}
