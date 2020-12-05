#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QKeyEvent>

const int PADDING = 10;
const int UFO_SIZE = 20;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    dialog(new OpeningDialog),
    score_(new Statistics),
    gameTime(0)
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

    connect(dialog,&OpeningDialog::tellGameLenght,this, &MainWindow::setGameTime);

    gameTimer = new QTimer(this);
    connect(gameTimer,&QTimer::timeout, this,&MainWindow::advanceGameTime);
    dialog->exec();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_W) {
        ufoObject_->setSpeed(0,-1);
    }

    if(event->key()==Qt::Key_S) {
        ufoObject_->setSpeed(0,1);
    }

    if(event->key()==Qt::Key_A) {
        ufoObject_->setSpeed(-1,0);
    }

    if(event->key()==Qt::Key_D) {
        ufoObject_->setSpeed(1,0);
    }
    if(event->key()==Qt::Key_Space) {
        ufoObject_->capture();
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

Ufo* MainWindow::returnUfo()
{
    return ufoObject_;
}

void MainWindow::on_startButton_clicked()
{
    qDebug() << "Start clicked";
    emit gameStarted();
}

void MainWindow::ufo_move()
{
    if(480>ufoItem_->x()+ufoObject_->getXSpeed() && 0<ufoItem_->x()+ufoObject_->getXSpeed() &&
            480>ufoItem_->y()+ufoObject_->getYSpeed() && 0<ufoItem_->y()+ufoObject_->getYSpeed()) {
        ufoItem_->moveBy(ufoObject_->getXSpeed(), ufoObject_->getYSpeed());
        Interface::Location loc;
        loc.setXY(ufoItem_->x(),500-ufoItem_->y());
        ufoObject_->move(loc);
    }
}

void MainWindow::setGameTime(int time)
{
    gameTime = time;
    ui->gameTimeLcdNumber->display(gameTime);
    gameTimer->start(1000);
}

void MainWindow::advanceGameTime()
{
    if(gameTime > 0){
        gameTime -= 1;
        ui->gameTimeLcdNumber->display(gameTime);
    } else {
        gameTimer->stop();
        ufoObject_->setSpeed(0,0);
        endGame();
    }
}

void MainWindow::endGame()
{
    EndingDialog *endDialog = new EndingDialog();
    connect(endDialog,&EndingDialog::closeGame,this,&MainWindow::close);
    connect(endDialog,&EndingDialog::closeGame,endDialog,&EndingDialog::close);
    endDialog->show();
    endDialog->showScore(score_->getScore());
}
