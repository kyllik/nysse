#include "creategame.hh"
#include "city.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<Interface::ICity> sp;
    sp = std::make_shared<City>();
    return sp;
}
