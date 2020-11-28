#include "statistics.hh"

Statistics::Statistics():
    passengers_(0), buses_(0), score_(0)
{

}

Statistics::~Statistics()
{

}

void Statistics::morePassengers(int num)
{
    passengers_ += num;
}

void Statistics::nysseRemoved()
{
    buses_ -= 1;
}

void Statistics::newNysse()
{
    buses_ += 1;
}

void Statistics::nysseLeft()
{

}

void Statistics::addScore(int num)
{
    score_ += num;
}

int Statistics::getScore() const
{
    return score_;
}
