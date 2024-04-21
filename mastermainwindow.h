#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H

#include "mastergameboard.h"
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
    void on_pushButton_clicked();

    void on_Level1Button_clicked();

    void on_Level2Button_clicked();

    void on_Level3Button_clicked();

    void on_Level4Button_clicked();

    void on_Level5Button_clicked();

private:
    Ui::MasterMainWindow *ui;
};

#endif // MASTERMAINWINDOW_H
