#ifndef NOOBMAINWINDOW_H
#define NOOBMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class noobMainWindow;
}

class noobMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit noobMainWindow(QWidget *parent = nullptr);
    ~noobMainWindow();

private:
    Ui::noobMainWindow *ui;
};

#endif // NOOBMAINWINDOW_H
