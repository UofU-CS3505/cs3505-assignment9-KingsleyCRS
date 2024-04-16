#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <QTimer>
#include "noobmainwindow.h"
#include "mastermainwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void noobClicked();
    void masterClicked();
signals:
private:
    Ui::MainWindow *ui;
    b2World world;
    b2Body* body;
    QTimer timer;
    MasterMainWindow master;
    noobMainWindow noob;
};
#endif // MAINWINDOW_H
