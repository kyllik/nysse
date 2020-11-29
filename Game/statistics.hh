#ifndef STATISTICS_HH
#define STATISTICS_HH

#include "../Course/CourseLib/interfaces/istatistics.hh"

class Statistics : public virtual Interface::IStatistics
{
public:
    Statistics();
    ~Statistics();
    void morePassengers(int num) override;
    void nysseRemoved() override;
    void newNysse() override;
    void nysseLeft() override;

    int getPassengers() const;
    int getBuses() const;
    int getScore() const;
    void addScore(int num);

private:
    int passengers_;
    int buses_;
    int score_;
};

#endif // STATISTICS_HH
