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
    gameTime(0),
    multiplier(1)
{
    ui->setupUi(this);
    ui->gameView->setFixedSize(width_+10, height_+10);
    ui->centralwidget->setFixedSize(width_ + ui->startButton->width() + PADDING, height_ + PADDING);

    ui->startButton->move(width_ + PADDING , PADDING);

    map = new QGraphicsScene(this);
    ui->gameView->setScene(map);
    map->setSceneRect(0,0,width_,height_);

    resize(minimumSizeHint());

    ui->lcdNumber->display(multiplier);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, map, &QGraphicsScene::advance);
    timer->start(tick_);

    ufoObject_ = new Ufo();
    ufoItem_ = new Item(250, 250, Qt::black, UFO_SIZE, UFO_SIZE, 0);
    addItem(ufoItem_);
    ufoItem_->setZValue(100);
    connect(timer, &QTimer::timeout, this, &MainWindow::ufo_move);

    connect(dialog,&OpeningDialog::tellGameLenght,this, &MainWindow::setGameTime);

    multiplierTimer = new QTimer(this);
    connect(multiplierTimer,&QTimer::timeout, this,&MainWindow::spawnMultiplier);

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
        setMultiplier(multiplierCaptured());
        score_->addScore(multiplier*ufoObject_->capture());
        ui->scoreLcdNumber->display(score_->getScore());
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
    multiplierTimer->start(15000);
}

void MainWindow::advanceGameTime()
{
    if(gameTime > 0){
        gameTime -= 1;
        ui->gameTimeLcdNumber->display(gameTime);
    } else {
        endGame();
    }
}

void MainWindow::spawnMultiplier()
{
    std::shared_ptr<ScoreMultiplier> newMultiplier = std::make_shared<ScoreMultiplier>();
    Interface::Location loc;
    float x;
    float y;
    x = static_cast<float>(width_)*static_cast<float>(rand()/static_cast<float>(RAND_MAX));
    y = static_cast<float>(height_)*static_cast<float>(rand()/static_cast<float>(RAND_MAX));
    loc.setXY(static_cast<int>(x),static_cast<int>(y));
    newMultiplier->move(loc);
    newMultiplier->setMultiplier(2);
    Item *newItem = new Item(newMultiplier->giveLocation().giveX(),
                             500-newMultiplier->giveLocation().giveY(),Qt::yellow,20,20);
    multipliers_[newMultiplier] = newItem;
    addItem(newItem);
}

int MainWindow::multiplierCaptured()
{
    for(auto actor: multipliers_){
        qDebug() <<  ufoObject_->giveLocation().giveX() << ufoObject_->giveLocation().giveY();
        qDebug() << 'l' << actor.first->giveLocation().giveX() << actor.first->giveLocation().giveY();
        if (ufoObject_->giveLocation().isClose(actor.first->giveLocation(),20)){
            int newMultiplier = actor.first->getMultiplier();
            actor.first->remove();
            delete multipliers_.at(actor.first);
            multipliers_.erase(actor.first);
            qDebug() << "new multiplier:" << newMultiplier;
            return newMultiplier;
        }
    }
    qDebug() << "new multiplier:" << 1;
    return 1;
}

void MainWindow::setMultiplier(int n)
{
    multiplier = multiplier * n;
    ui->lcdNumber->display(multiplier);
}

void MainWindow::endGame()
{
    multiplierTimer->stop();
    gameTimer->stop();
    ufoObject_->setSpeed(0,0);
    EndingDialog *endDialog = new EndingDialog();
    endDialog->setModal(true);
    connect(endDialog,&EndingDialog::closeGame,this,&MainWindow::close);
    connect(endDialog,&EndingDialog::closeGame,endDialog,&EndingDialog::close);
    endDialog->show();
    endDialog->showScore(score_->getScore());
}
