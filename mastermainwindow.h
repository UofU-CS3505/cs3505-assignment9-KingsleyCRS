#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H
#include "gamelosedialog.h"
#include <QMainWindow>
#include "windialog.h"
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
     void enableAnimation();

public slots:
    void on_quitButton_clicked();

    void on_Level1Button_clicked();

    void on_Level2Button_clicked();

    void on_Level3Button_clicked();

    void on_Level4Button_clicked();

    void on_Level5Button_clicked();



    void levelWin();
signals:
         //void sendWin();

private slots:
    void on_resetButton_clicked();

    void on_hintButton_clicked();

private:
    Ui::MasterMainWindow *ui;
    GameLoseDialog gamelose;
    winDialog gameWin;
    void gameLost(int i);
    void gamewin(int i);



};

#endif // MASTERMAINWINDOW_H
