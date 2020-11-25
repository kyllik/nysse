#include "creategame.hh"
#include "city.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<CourseSide::SimpleMainWindow> ui = std::make_shared<CourseSide::SimpleMainWindow>();
    std::shared_ptr<Interface::ICity> city;
    city = std::make_shared<City>(ui);
    return city;
}
