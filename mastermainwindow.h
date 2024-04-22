#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H
#include "gamelosedialog.h"
#include <QMainWindow>

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

    void levelWin();


private slots:
    void on_resetButton_clicked();

    void on_hintButton_clicked();

private:
    Ui::MasterMainWindow *ui;
    GameLoseDialog gamelose;
    void gameLost(int i);
};

#endif // MASTERMAINWINDOW_H
