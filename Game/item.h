#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include "interfaces/iactor.hh"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <iostream>
#include <memory>
#include <QVector>
#include <map>


class Item : public QGraphicsItem
{
public:
    Item(int x, int y, QColor color = Qt::red, int height = 10, int width = 10, bool shape = 1);
    virtual ~Item();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    QColor color_;
    int height_ = 10;
    int width_ = 10;
    bool shape_;
};

#endif // RECTITEM_H
