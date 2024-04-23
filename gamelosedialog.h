#ifndef GAMELOSEDIALOG_H
#define GAMELOSEDIALOG_H

#include <QDialog>

namespace Ui {
class GameLoseDialog;
}

class GameLoseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameLoseDialog(QWidget *parent = nullptr);
    ~GameLoseDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::GameLoseDialog *ui;
};

#endif // GAMELOSEDIALOG_H
