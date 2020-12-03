#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "endingdialog.hh"
#include "openingdialog.hh"
#include "item.h"
#include "ufo.hh"
#include "statistics.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void keyPressEvent(QKeyEvent* event) override;

    void setSize(int w, int h);
    void setTick(int t);

    virtual void addActor(int locX, int locY);
    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);

    void addItem(Item* item);
public slots:
    void setGameTime(int time);
signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();
    void ufo_move();
    void advanceGameTime();

private:

   void endGame();

    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    OpeningDialog *dialog;
    Item* last_;
    Item* ufoItem_;
    Ufo* ufoObject_;
    QTimer *gameTimer;
    Statistics *score_;


    int gameTime;
    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 5; //ms
};

#endif // MAINWINDOW_H
