#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "interfaces/iactor.hh"
#include "interfaces/istop.hh"
#include "actors/nysse.hh"
#include "actors/passenger.hh"
#include "actors/stop.hh"
#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "ufo.hh"

#include <QDebug>
#include <QTime>

const QString DEFAULT_BACKGROUND_SMALL = ":/offlinedata/offlinedata/kartta_pieni_500x500.png";
const QString DEFAULT_BACKGROUND_BIG = ":/offlinedata/offlinedata/kartta_iso_1095x592.png";

class City : public virtual Interface::ICity
{
public:
    City(std::shared_ptr<CourseSide::SimpleMainWindow> ui);

    ~City();

    void setBackground(QImage &basicbackground, QImage &bigbackground) override;
    void setClock(QTime clock) override;
    void addStop(std::shared_ptr<Interface::IStop> stop) override;
    void startGame() override;
    void addActor(std::shared_ptr<Interface::IActor> newactor) override;
    void removeActor(std::shared_ptr<Interface::IActor> actor) override;
    void actorRemoved(std::shared_ptr<Interface::IActor> actor) override;
    bool findActor(std::shared_ptr<Interface::IActor> actor) const override;
    void actorMoved(std::shared_ptr<Interface::IActor> actor) override;
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const override;
    bool isGameOver() const override;


private:
    std::vector< std::shared_ptr<Interface::IActor> > actors_;
    std::vector< std::shared_ptr<Interface::IStop> > stops_;
    std::map< std::shared_ptr<Interface::IActor>, std::shared_ptr<CourseSide::SimpleActorItem> > actorItems_;
    std::map< std::shared_ptr<Interface::IStop>, std::shared_ptr<CourseSide::SimpleActorItem> > stopItems_;
    bool gameOver_;

    QImage backgroundSmall_;
    QImage backGroundBig_;
    QTime clock_;
    std::shared_ptr<CourseSide::SimpleMainWindow> ui_;

};

#endif // CITY_HH
