#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <QTimer>
#include "noobmainwindow.h"
#include "mastermainwindow.h"
#include <Qpixmap>

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
    void scheduleForDestruction(b2Body* body);
    void destroyScheduledBodies();

signals:
private:
    Ui::MainWindow *ui;
    b2World world;
    b2Body* body;
    QTimer timer;
    MasterMainWindow master;
    noobMainWindow noob;
    void drawWelcome(QPainter &painter, int x, int y);
    void drawHello(QPainter &painter, int x, int y);
    std::vector<b2Body*> bodiesToDestroy;
    void someGameLogicFunction();



protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
