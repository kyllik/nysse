#ifndef UFO_HH
#define UFO_HH

#include "interfaces/iactor.hh"
#include "interfaces/icity.hh"
#include "core/location.hh"

#include <vector>

const int CAPTURE_RANGE = 5;

class Ufo : public virtual Interface::IActor
{
public:
    Ufo();

    ~Ufo();

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

    void setSpeed(int vx, int vy);
    void setCity(std::shared_ptr<Interface::ICity> city);

    int getXSpeed();
    int getYSpeed();
    int capture();

private:
    std::shared_ptr<Interface::ICity> city_;
    Interface::Location location_;
    int xSpeed_;
    int ySpeed_;
    bool removed_;

};

#endif // UFO_HH
