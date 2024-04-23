#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H
#include "gamelosedialog.h"
#include <QMainWindow>
#include "world.h"
#include <Qpixmap>
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

    void on_Level5Button_clicked();

    //void updatePhysics();

    void levelWin();
signals:
         //void sendWin();

private slots:
    void on_resetButton_clicked();

    void on_hintButton_clicked();

    void handleDialog();

private:
    Ui::MasterMainWindow *ui;
    GameLoseDialog gamelose;
    void gameLost();
    void resetCurrentLevel();
    // void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
    // world world;
    void paintEvent(QPaintEvent *event);
    void animation();
    // protected:
    //     void paintEvent(QPaintEvent *event) override;
    world world;
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);

    QTimer *flipTimer;  // 用于触发狗的反转
    bool dogFlipped = false;  // 跟踪狗是否已反转
    void flipDog();  // 狗的反转函数
    void drawFlippedAnimation(QPainter& painter, const QString& imagePath, int x, int y);
};

#endif // MASTERMAINWINDOW_H
