#include "gameengine.hh"
#include "core/logic.hh"
#include "creategame.hh"
#include "graphics/simplemainwindow.hh"

#include <iostream>
#include <QImage>

GameEngine::GameEngine() :
    ui_(nullptr)
{

}

void GameEngine::startGame()
{
    ui_ = std::make_shared<CourseSide::SimpleMainWindow>();
    ui_->show();
}
