#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH
#include "graphics/simplemainwindow.hh"
#include "interfaces/icity.hh"
#include "core/logic.hh"
#include "ufo.hh"
#include <fstream>
#include <streambuf>
#include "offlinereader.hh"

const QString DEFAULT_BACKGROUND_SMALL = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString DEFAULT_BACKGROUND_BIG = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";

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
