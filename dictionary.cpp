#include "dictionary.h"
#include <random>
#include <set>

Dictionary::Dictionary() {
    // three level in total
    allWords = {
        {"學生","Student"},{"哈囉","Hello"},{"名字", "Name"},{"我", "Me or I"}, {"你", "You"}, {"他","He"}, {"狗","dog"},{"人","human"},{"他們","They"},{"我們","We"},
        {"第二关","level two"},{"墙","wall"},{"我","me"},{"三","three"},{"四","four"}, {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"},
        {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"}, {"第三关","level three"},{"狗","dog"},{"人","human"},{"五","five"},{"六","six"}
    };

    // make sure all level have same words number
    numLevelWords = allWords.count()/3;
    numAllWords = allWords.count();
}

QPair<QString, QString> Dictionary::getPairAt(uint i, uint level){
    return allWords[level * numLevelWords + i];
}

QVector<QPair<QString, QString>> Dictionary::getRandomPair(uint level){
    QVector<QPair<QString, QString>> a;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(level * numLevelWords, level * numLevelWords + numLevelWords-1);

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

QVector<QPair<QString, QString>> Dictionary::getAllRandomPair(){
    QVector<QPair<QString, QString>> a;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, numAllWords-1);

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

