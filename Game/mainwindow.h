#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "item.h"
#include "ufo.hh"

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

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();
    void ufo_move();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    Item* last_;
    Item* ufoItem_;
    Ufo* ufoObject_;
    int ufo_x_speed_=0;
    int ufo_y_speed_=0;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 5; //ms
};

#endif // MAINWINDOW_H
