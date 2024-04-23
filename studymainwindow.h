#ifndef STUDYMAINWINDOW_H
#define STUDYMAINWINDOW_H

#include <QMainWindow>
#include "dictionary.h"

namespace Ui {
class studyMainWindow;
}

class studyMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit studyMainWindow(QWidget *parent = nullptr);
    ~studyMainWindow();
    void reset();

public slots:
    void startClicked();
    void knowClicked();
    void unknowClicked();
    void closeClicked();

private:
    Ui::studyMainWindow *ui;
    Dictionary words;
    int barValue = 10;
    uint learningAt = 0;

    // false if already learned all words
    bool printNext();
};

#endif // STUDYMAINWINDOW_H
