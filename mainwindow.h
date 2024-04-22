#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <QTimer>
#include "mastermainwindow.h"
#include <Qpixmap>
#include "world.h"
class LevelMainWindow;

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
    void updatePhysics();

signals:
private:
    Ui::MainWindow *ui;
    b2Body* body;
    QTimer timer;
    MasterMainWindow master;
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
    world world;
protected:
    void paintEvent(QPaintEvent *event) override;

};
#endif // MAINWINDOW_H
