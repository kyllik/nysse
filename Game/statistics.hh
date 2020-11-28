#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "interfaces/istatistics.hh"

class Statistics : public virtual Interface::IStatistics
{
public:
    Statistics();
    ~Statistics();
    void morePassengers(int num) override;
    void nysseRemoved() override;
    void newNysse() override;
    void nysseLeft() override;

    void addScore(int num);
    int getScore() const;

private:
    int passengers_;
    int buses_;
    int score_;
};

#endif // STATISTICS_HH
