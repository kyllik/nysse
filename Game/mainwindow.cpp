#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>

const int PADDING = 10;
const int UFO_SIZE = 20;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_+10, height_+10);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());
    //ui->gameView->fitInView(0,0, MAPWIDTH, MAPHEIGHT, Qt::KeepAspectRatio);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    ufoObject_ = new Ufo();
    ufoItem_ = new Item(250, 250, Qt::black, UFO_SIZE, UFO_SIZE, 0);
    addItem(ufoItem_);
    ufoItem_->setZValue(100);
    connect(timer, &QTimer::timeout, this, &MainWindow::ufo_move);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W) {
        ufo_x_speed_ = 0;
        ufo_y_speed_ = -1;
    }

    if(event->key()==Qt::Key_S) {
        ufo_x_speed_ = 0;
        ufo_y_speed_ = 1;
    }

    if(event->key()==Qt::Key_A) {
        ufo_x_speed_ = -1;
        ufo_y_speed_ = 0;
    }

    if(event->key()==Qt::Key_D) {
        ufo_x_speed_ = 1;
        ufo_y_speed_ = 0;
    }
}

void MainWindow::setSize(int w, int h)
{
    width_ = w;
    height_ = h;
}

void MainWindow::setTick(int t)
{
    tick_ = t;
}

void MainWindow::addActor(int locX, int locY)
{
    Item* nActor = new Item(locX, locY);
    actors_.push_back(nActor);
    map->addItem(nActor);
    last_ = nActor;
}

void MainWindow::updateCoords(int nX, int nY)
{
    last_->setCoord(nX, nY);
}

void MainWindow::setPicture(QImage &img)
{
    map->setBackgroundBrush(img);
}

void MainWindow::addItem(Item *item)
{
    map->addItem(item);
    actors_.push_back(item);
    last_ = item;
}

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
    ufo_x_speed_=1;
}

void MainWindow::ufo_move()
{
    if(480>ufoItem_->x()+ufo_x_speed_ && 0<ufoItem_->x()+ufo_x_speed_ &&
            480>ufoItem_->y()+ufo_y_speed_ && 0<ufoItem_->y()+ufo_y_speed_) {
        ufoItem_->moveBy(ufo_x_speed_, ufo_y_speed_);
    }
}
