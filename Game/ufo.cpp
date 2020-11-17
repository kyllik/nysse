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
