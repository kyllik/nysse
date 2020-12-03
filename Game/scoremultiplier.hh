#ifndef SCOREMULTIPLIER_HH
#define SCOREMULTIPLIER_HH

#include "interfaces/iactor.hh"
#include "core/location.hh"

class ScoreMultiplier: public virtual Interface::IActor
{
public:
    ScoreMultiplier();
    ~ScoreMultiplier();

    Interface::Location giveLocation() const override;
    void move(Interface::Location loc) override;
    bool isRemoved() const override;
    void remove() override;

    void setMultiplier(int n);
    int getMultiplier() const;
private:
    Interface::Location location_;
    int multiplier_;
    bool removed_;
};

#endif // SCOREMULTIPLIER_HH
