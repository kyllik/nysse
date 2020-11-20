#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH
#include "graphics/simplemainwindow.hh"
#include "interfaces/icity.hh"

class GameEngine
{
public:
    GameEngine();

    void startGame();
    void endGame();

private:
    std::shared_ptr<CourseSide::SimpleMainWindow> ui_;
};

#endif // GAMEENGINE_HH
