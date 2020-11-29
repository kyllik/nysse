#include "item.h"

Item::Item(int x, int y, QColor color, int height, int width, bool shape):x_(x),
    y_(y), color_(color), height_(height), width_(width), shape_(shape)
{
    setPos(mapToParent(x_, y_));
}

Item::~Item()
{

}

QRectF Item::boundingRect() const
{
    return QRectF(0, 0, width_, height_);
}

void Item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF bounds = boundingRect();
    QBrush brush(color_);
    painter->setBrush(brush);
    if(shape_==0) {
        painter->drawRect(bounds);
    } else {
        painter->drawEllipse(bounds);
    }

}

void Item::setCoord(int x, int y)
{
    setX( x );
    setY( y );
}
