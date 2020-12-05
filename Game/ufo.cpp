#include "ufo.hh"
#include "QDebug"

Ufo::Ufo() :
    xSpeed_(0),
    ySpeed_(0),
    removed_(false)
{
}

Ufo::~Ufo()
{

}

Interface::Location Ufo::giveLocation() const
{
    return location_;
}

void Ufo::move(Interface::Location loc)
{
    location_ = loc;
}

bool Ufo::isRemoved() const
{
    return removed_;
}

void Ufo::remove()
{
    removed_ = true;
}

void Ufo::setSpeed(int vx,int vy)
{
    xSpeed_ = vx;
    ySpeed_ = vy;
}

void Ufo::setCity(std::shared_ptr<Interface::ICity> city)
{
    city_ = city;
}

int Ufo::getXSpeed()
{
    return xSpeed_;
}

int Ufo::getYSpeed()
{
    return ySpeed_;
}

int Ufo::capture()
{
    int captured = city_->getNearbyActors(location_).size();
    qDebug() << "actors nearby: " << captured;
    for( auto actor : city_->getNearbyActors(location_) ) {
        city_->removeActor(actor);
    }
    qDebug() << location_.giveX() << location_.giveY();
    return captured;
}
