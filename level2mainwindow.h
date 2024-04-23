#ifndef LEVEL2MAINWINDOW_H
#define LEVEL2MAINWINDOW_H

#include <QMainWindow>
#include "dictionary.h"

namespace Ui {
class Level2MainWindow;
}

class Level2MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Level2MainWindow(QWidget *parent = nullptr);
    ~Level2MainWindow();
public slots:
    void startClicked();
    void Pair1Clicked();
    void Pair2Clicked();
    void Pair3Clicked();
    void Pair11Clicked();
    void Pair22Clicked();
    void Pair33Clicked();
private:
    Ui::Level2MainWindow *ui;
    Dictionary word;
    int life;
    int barValue;
    QVector<QPair<QString, QString>> problemPair;
    int levelCount;
    int correctCount;
    std::vector<int> numbers;
};

#endif // LEVEL2MAINWINDOW_H
