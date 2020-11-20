#include "gameengine.hh"
#include "core/logic.hh"
#include "creategame.hh"
#include "graphics/simplemainwindow.hh"

#include <iostream>
#include <QImage>


GameEngine::GameEngine() :
    ui_(nullptr), city_(nullptr), logic_(nullptr)
{

}

void GameEngine::start()
{
    ui_ = std::make_shared<CourseSide::SimpleMainWindow>();
    ui_->show();
    city_ = Interface::createGame();
    logic_ = std::make_shared<CourseSide::Logic>();
    logic_->takeCity(city_);
    QImage backgroundSmall = QImage(DEFAULT_BACKGROUND_SMALL);
    QImage backgroundBig = QImage(DEFAULT_BACKGROUND_BIG);
    city_->setBackground(backgroundSmall,backgroundBig);
    ui_->setPicture(backgroundSmall);

}
