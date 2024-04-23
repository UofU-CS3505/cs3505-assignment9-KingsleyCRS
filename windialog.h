#ifndef WINDIALOG_H
#define WINDIALOG_H
#include "world.h"
#include <QDialog>

namespace Ui {
class winDialog;
}

class winDialog : public QDialog
{
    Q_OBJECT

public:
    explicit winDialog(QWidget *parent = nullptr);
    ~winDialog();

public slots:
    void updatePhysics();
private:
    Ui::winDialog *ui;
    world world;
    void drawAnimation(QPainter& painter, const QString& imagePath, int x, int y);
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // WINDIALOG_H
