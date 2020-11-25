#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH
#include "graphics/simplemainwindow.hh"
#include "interfaces/icity.hh"
#include "core/logic.hh"
#include "ufo.hh"
#include <fstream>
#include <streambuf>
#include "offlinereader.hh"

class GameEngine
{
public:
    GameEngine();

    void start();
    void end();

private:
    std::shared_ptr<CourseSide::SimpleMainWindow> ui_;
    std::shared_ptr<Interface::ICity> city_;
    std::shared_ptr<CourseSide::Logic> logic_;
    std::shared_ptr<Ufo> ufo_;
};

#endif // GAMEENGINE_HH
