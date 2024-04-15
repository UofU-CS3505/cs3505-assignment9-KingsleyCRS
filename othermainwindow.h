#ifndef OTHERMAINWINDOW_H
#define OTHERMAINWINDOW_H
#include <Box2D/Box2D.h>
#include <stdio.h>
#include <QMainWindow>
#include <QTimer>

namespace Ui {
class OtherMainWindow;
}

class OtherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtherMainWindow(QWidget *parent = nullptr);
    ~OtherMainWindow();
public slots:
signals:
private:
    Ui::OtherMainWindow *ui;
};

#endif // OTHERMAINWINDOW_H
