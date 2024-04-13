#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <QMainWindow>
#include <QTimer>
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
signals:
private:
    Ui::MainWindow *ui;
    Ui::MainWindow *ui;
    b2World world;
    b2Body* body;
    QTimer timer;
};
#endif // MAINWINDOW_H
