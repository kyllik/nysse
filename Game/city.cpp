#include "city.hh"

#include <QTime>

City::City()
{

}

City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    background_ = basicbackground;
    ui_->setPicture(background_);
}
void City::setClock(QTime clock)
{
    clock_ = clock;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{

}

void City::startGame()
{

}
void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{

}
void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{


}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{

}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{

}
std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{

}
