#include "ufo.hh"

Ufo::Ufo() :
    speed_(0),
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

void Ufo::setSpeed(int v)
{
    speed_ = v;
}

void Ufo::setCity(std::shared_ptr<Interface::ICity> city)
{
    city_ = city;
}

void Ufo::capture(std::shared_ptr<Interface::IActor>)
{

}
