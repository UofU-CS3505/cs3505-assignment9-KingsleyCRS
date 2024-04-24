#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "iostream"
#include <QPainter>
#include <QPoint>
#include <QPaintEvent>
#include <string>
#include "levelmainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , world(parent)

{
    ui->setupUi(this);
    this->resize(800, 800);
    this->setFixedSize(800, 800);


    world.createWall("top",b2Vec2(0.0f, 19.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
    world.createWall("bot",b2Vec2(0.0f, 0.0f),b2Vec2(8.0f, 0.5f),0.5f,0.8f);
    world.createWall("left",b2Vec2(-8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);
    world.createWall("right",b2Vec2(8.0f, 8.0f),b2Vec2(0.5f, 8.0f),0.5f,0.8f);


    world.createBody("Box",b2Vec2(1.0f, 8.0f),b2Vec2(-30.0f, -20.0f),b2Vec2(10.0f, -10.0f),1.0f,1.0f,1.0f,1.0f,true);
    world.createBody("Circle",b2Vec2(2.0f, 3.0f),b2Vec2(-30.0f, -10.0f),b2Vec2(10.0f, -0.0f),1.0f,1.0f,1.0f,1.0f,true);

    connect(ui->noobButton,&QPushButton::clicked,this,&MainWindow::noobClicked);
    connect(ui->masterButton,&QPushButton::clicked,this,&MainWindow::masterClicked);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    timer->start(1000 / 60);

}
MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::masterClicked(){
    master.show();
}
void MainWindow::noobClicked(){
    LevelMainWindow *levelWindow = new LevelMainWindow();  // Create an instance of LevelMainWsindow
    levelWindow->setAttribute(Qt::WA_DeleteOnClose);        // Ensure it will be deleted on close
    levelWindow->show();
}
void MainWindow::updatePhysics() {
    if (!world.body) return;  // Skip physics update if the body has been destroyed
    world.step();
    update();
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPixmap pix(":/BG.jpg");
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), pix);
    const float scaleFactor = 50;  // 50 pixels per meter
    const float offsetX = 800 / 2;  // Centering in width
    const float offsetY = 800;  // Aligning from the bottom
    for (b2Body* body = world.box2DWorld->GetBodyList(); body != nullptr; body = body->GetNext()) {
        float x = body->GetPosition().x * scaleFactor + offsetX;
        float y = offsetY - body->GetPosition().y * scaleFactor;  // Flipping Y coordinate for graphical display
        std::string* name = static_cast<std::string*>(body->GetUserData());
        if (name) {
            if (*name == "Circle") {
                drawAnimation(painter, ":/nihao.png", x, y);
            } else if (*name == "Box") {
                drawAnimation(painter, ":/welcome.png",x, y);
            }
        }
    }
}


void MainWindow::drawAnimation(QPainter& painter, const QString& imagePath, int x, int y) {
    QPixmap pixmap(imagePath);
    if(!pixmap.isNull()) {
        painter.drawPixmap(x - pixmap.width()/2, y - pixmap.height()/2, pixmap);
    }
}
