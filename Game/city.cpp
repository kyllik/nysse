#include "city.hh"

#include <QTime>
#include <iostream>
#include <vector>

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
    int x = stop->getLocation().giveX();
    int y = stop->getLocation().giveY();

    std::shared_ptr<CourseSide::SimpleActorItem> stopItem =
            std::make_shared<CourseSide::SimpleActorItem>(x,y);
    stopItems_.insert(std::pair<std::shared_ptr<Interface::IStop>,
                      std::shared_ptr<CourseSide::SimpleActorItem>>(stop,stopItem));
    ui_->addActor(x,500-y);
}

void City::startGame()
{
    ui_->show();
    ui_->setPicture(backgroundSmall_);
}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    actors_.push_back(newactor);

    Interface::Location newactorLocation = newactor->giveLocation();
    RectItem* nActor = new RectItem(newactorLocation.giveX(), 500-newactorLocation.giveY());
    ui_->addItem(nActor);

    actorItems_[newactor] = nActor;
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
