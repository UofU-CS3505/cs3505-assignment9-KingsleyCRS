#ifndef NOOBMAINWINDOW_H
#define NOOBMAINWINDOW_H
/*
Noobmainwindow header for Noobmainwindow class
By Kai-Chen Chiang,jinchao liang, Rishen Cao, Zelin Yi, Shuangji Li,Yuang sun
*/
#include <QMainWindow>
#include "dictionary.h"

namespace Ui {
class noobMainWindow;
}

class noobMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit noobMainWindow(QWidget *parent = nullptr);
    ~noobMainWindow();
public slots:
    void startClicked();
    void AClicked();
    void BClicked();
    void CClicked();
    void DClicked();
    void checkClicked();
    void nextClicked();
    void closeClicked();
signals:
private:
    Ui::noobMainWindow *ui;
    Dictionary word;
    QPair<QString, QString> questionWord;
    int life;
    int barValue;
    QVector<QPair<QString, QString>> incorrectAnswers;
    int levelCount;
    void complete();
    int correctCount;

};

#endif // NOOBMAINWINDOW_H
