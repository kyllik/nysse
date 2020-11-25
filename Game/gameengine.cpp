#include "gameengine.hh"
#include "core/logic.hh"
#include "creategame.hh"
#include "city.hh"
#include "graphics/simplemainwindow.hh"

#include <iostream>
#include <QImage>
#include <QDebug>


GameEngine::GameEngine() :
    ui_(nullptr), city_(nullptr), logic_(nullptr)
{

}

void GameEngine::start()
{
    city_ = Interface::createGame();

    logic_ = std::make_shared<CourseSide::Logic>();
    logic_->takeCity(city_);

    QImage backgroundSmall = QImage(DEFAULT_BACKGROUND_SMALL);
    QImage backgroundBig = QImage(DEFAULT_BACKGROUND_BIG);
    city_->setBackground(backgroundSmall,backgroundBig);
    city_->startGame();

    logic_->fileConfig();
    logic_->setTime(9,0);
    logic_->finalizeGameStart();
}
