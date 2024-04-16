#ifndef MASTERMAINWINDOW_H
#define MASTERMAINWINDOW_H

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

private:
    Ui::MasterMainWindow *ui;
};

#endif // MASTERMAINWINDOW_H
