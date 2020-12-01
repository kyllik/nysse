#include "creategame.hh"
#include "city.hh"
#include "openingdialog.hh"

std::shared_ptr<Interface::ICity> Interface::createGame()
{
    std::shared_ptr<MainWindow> ui = std::make_shared<MainWindow>();
    std::shared_ptr<Interface::ICity> city;
    city = std::make_shared<City>(ui);
    return city;
}
