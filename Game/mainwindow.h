#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "item.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

    void setSize(int w, int h);
    void setTick(int t);

    virtual void addActor(int locX, int locY);
    void updateCoords(int nX, int nY);
    void setPicture(QImage &img);

    void addItem(QGraphicsItem* item);

signals:
    void gameStarted();

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QVector<QGraphicsItem*> actors_;
    Item* last_;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms
};

#endif // MAINWINDOW_H
