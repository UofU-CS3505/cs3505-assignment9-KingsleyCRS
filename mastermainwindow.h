#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H
#include "gamelosedialog.h"
#include <QMainWindow>
#include "world.h"
#include <Qpixmap>
/*
MasterMainWindow header for MasterMainwindow class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
namespace Ui {
class MasterMainWindow;
}

class MasterMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MasterMainWindow(QWidget *parent = nullptr);
    ~MasterMainWindow();

public slots:
    void on_quitButton_clicked();

    void on_Level1Button_clicked();

    void on_Level2Button_clicked();

    void on_Level3Button_clicked();

    void on_Level4Button_clicked();

    void levelWin();
signals:

private slots:
    void on_resetButton_clicked();

    void on_hintButton_clicked();

    void handleDialog();

    void on_nextLevelButton_clicked();

private:
    Ui::MasterMainWindow *ui;
    GameLoseDialog gamelose;
    void gameLost();
    void resetCurrentLevel();
    void paintEvent(QPaintEvent *event);
    void animation();
    world world;
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
    QTimer *flipTimer;
    bool dogFlipped = false;
    void flipDog();
    void drawFlippedAnimation(QPainter& painter, const QString& imagePath, int x, int y);
};

#endif // MASTERMAINWINDOW_H
