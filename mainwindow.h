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
    void updatePhysics();
    void destroyBody();

signals:
private:
    Ui::MainWindow *ui;
    b2World world;
    b2Body* body;
    QTimer timer;
    MasterMainWindow master;
    noobMainWindow noob;
    void drawRocket(QPainter &painter, int x, int y);
protected:
    void paintEvent(QPaintEvent *event) override;
};
#endif // MAINWINDOW_H
