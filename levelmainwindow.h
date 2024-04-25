#ifndef LEVELMAINWINDOW_H
#define LEVELMAINWINDOW_H
#include "noobmainwindow.h"
#include "studymainwindow.h"
#include <QMainWindow>
#include "level2mainwindow.h"
/*
LevelMainWindow header for LevelMainWindow class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
class noobMainWindow;
namespace Ui {
class LevelMainWindow;
}

class LevelMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LevelMainWindow(QWidget *parent = nullptr);
    ~LevelMainWindow();
public slots:
    void level_1Clicked();
    void level_2Clicked();
    void level_3Clicked();
private:
    Ui::LevelMainWindow *ui;
    noobMainWindow *noob;
    Level2MainWindow *level2;
    studyMainWindow *study;
};

#endif // LEVELMAINWINDOW_H
