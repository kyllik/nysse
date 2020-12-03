#include "scoremultiplier.hh"

ScoreMultiplier::ScoreMultiplier() :
    multiplier_(1),
    removed_(false)
{

}

ScoreMultiplier::~ScoreMultiplier()
{

}

Interface::Location ScoreMultiplier::giveLocation() const
{
    return location_;
}

void ScoreMultiplier::move(Interface::Location loc)
{
    location_ = loc;
}

bool ScoreMultiplier::isRemoved() const
{
    return removed_;
}

void ScoreMultiplier::remove()
{
    removed_ = true;
}

void ScoreMultiplier::setMultiplier(int n)
{
    multiplier_ = n;
}

int ScoreMultiplier::getMultiplier() const
{
    return multiplier_;
}
