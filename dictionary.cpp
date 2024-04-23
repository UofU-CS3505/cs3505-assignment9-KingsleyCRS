#include "dictionary.h"
#include <random>
#include <set>

Dictionary::Dictionary() {
    // three level in total
    allWords = {
        {"學生","Student"},{"哈囉","Hello"},{"名字", "Name"},{"我", "Me or I"}, {"你", "You"}, {"他","He"}, {"狗","dog"},{"人","human"},{"他們","They"},{"我們","We"}, {"老師","Teacher"},
        {"第二关","level two"},{"墙","wall"},{"我","me"},{"三","three"},{"四","four"}, {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"}, {"六","six"},
        {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"}, {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"}, {"六","six"}
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
