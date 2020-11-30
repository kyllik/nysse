#include "city.hh"

#include <QTime>
#include <iostream>
#include <vector>
#include <QDebug>

City::City(std::shared_ptr<MainWindow> ui) :
    gameOver_(false),
    ui_(ui)
{
}

City::~City()
{

}

void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    backgroundSmall_ = basicbackground;
    backGroundBig_ = bigbackground;
}

void City::setClock(QTime clock)
{
    clock_ = clock;
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    stops_.push_back(stop);

    Interface::Location stopLocation = stop->getLocation();
    Item* newitem = new Item(stopLocation.giveX(), 500-stopLocation.giveY());

    stopItems_[stop] = newitem;

    ui_->addItem(newitem);
}

void City::startGame()
{
    ui_->show();
    ui_->setPicture(backgroundSmall_);
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);

    QColor color;
    int height, width;
    bool shape;

    std::shared_ptr<Interface::IVehicle> nysse = std::dynamic_pointer_cast<Interface::IVehicle>(newactor);
    if(nysse==nullptr) {
        color = Qt::green;
        height = 5;
        width = 5;
        shape = 1;
    } else {
        color = Qt::blue;
        height = 10;
        width = 20;
        shape = 0;
    }

    Interface::Location newactorLocation = newactor->giveLocation();
    Item* newitem = new Item(newactorLocation.giveX(), 500-newactorLocation.giveY(), color, height, width, shape);
    ui_->addItem(newitem);

    actorItems_[newactor] = newitem;
}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    actor->remove();
}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{

}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for (std::shared_ptr<Interface::IActor> actorInGame : actors_){
        if(actorInGame == actor){
            if(not actorInGame->isRemoved()){
                return true;
            }
        }
    }
    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    actorItems_.at(actor)->setX(actor->giveLocation().giveX());
    actorItems_.at(actor)->setY(500-actor->giveLocation().giveY());
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor> > nearbyActors = {};
    for (std::shared_ptr<Interface::IActor> actor : actors_){
        if (actor->giveLocation().isClose(loc)){
            nearbyActors.push_back(actor);
        }
    }
    return nearbyActors;
}

bool City::isGameOver() const
{
    return gameOver_;
}
