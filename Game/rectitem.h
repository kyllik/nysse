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

const int WIDTH = 10;
const int HEIGHT = 10;

class RectItem : public QGraphicsItem
{
public:
    RectItem(int x, int y, int type = 0);
    virtual ~RectItem();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setCoord(int x, int y);

private:
    int x_;
    int y_;
    int type_;
};

#endif // RECTITEM_H
