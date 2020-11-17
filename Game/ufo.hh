#ifndef UFO_HH
#define UFO_HH

#include "interfaces/iactor.hh"
#include "core/location.hh"

class Ufo : public virtual Interface::IActor
{
public:
    Ufo();

    ~Ufo();

    Interface::Location giveLocation() const;
    void move(Interface::Location loc);
    bool isRemoved() const;
    void remove();

    void setSpeed(int v);

private:
    Interface::Location location_;
    int speed_;
    bool removed_;

};

#endif // UFO_HH
