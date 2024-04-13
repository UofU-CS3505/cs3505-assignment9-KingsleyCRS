#ifndef OTHERMAINWINDOW_H
#define OTHERMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class OtherMainWindow;
}

class OtherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OtherMainWindow(QWidget *parent = nullptr);
    ~OtherMainWindow();

private:
    Ui::OtherMainWindow *ui;
};

#endif // OTHERMAINWINDOW_H
