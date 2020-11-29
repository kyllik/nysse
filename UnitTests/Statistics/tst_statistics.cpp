#include <QtTest>
#include "statistics.hh"
class statistics : public QObject
{
    Q_OBJECT

public:
    statistics();
    ~statistics();

private slots:
    void passengers();
    void passengers_data();
    void buses();
    void buses_data();
    void score();
    void score_data();

};

statistics::statistics()
{

}

statistics::~statistics()
{

}

void statistics::passengers()
{
   QFETCH(int, addition1);
   QFETCH(int, addition2);
   QFETCH(int, addition3);
   QFETCH(int, deduction);
   QFETCH(int, addition4);

   Statistics s;
   s.morePassengers(addition1);
   QVERIFY2(s.getPassengers() == addition1, "Wrong result on first case");
   s.morePassengers(addition2);
   QVERIFY2(s.getPassengers() == addition1+addition2, "Wrong result on second case");
   s.morePassengers(addition3);
   QVERIFY2(s.getPassengers() == addition1+addition2+addition3, "Wrong result on third case");
   s.morePassengers(deduction);
   QVERIFY2(s.getPassengers() == addition1+addition2+addition3+deduction,
            "Wrong result on fourth case");
   s.morePassengers(addition4);
   QVERIFY2(s.getPassengers() == addition1+addition2+addition3+deduction+addition4,
            "Wrong result on fifth case");
}

void statistics::passengers_data()
{
   QTest::addColumn<int>("addition1");
   QTest::addColumn<int>("addition2");
   QTest::addColumn<int>("addition3");
   QTest::addColumn<int>("deduction");
   QTest::addColumn<int>("addition4");

   QTest::newRow("passenger test") << 5 << 5 << 18 << -7 << 9;
}

void statistics::buses()
{
   QFETCH(int, buses_added);
   Statistics s;
   for (int i=0; i < buses_added; i++){
       s.newNysse();
   }
   QVERIFY2(s.getBuses() == buses_added, "Wrong result");
}

void statistics::buses_data()
{
    QTest::addColumn<int>("buses_added");

    QTest::newRow("bus test 1") << 1;
    QTest::newRow("bus test 10") << 10;
    QTest::newRow("bus test 80") << 80;
}

void statistics::score()
{
    QFETCH(int, addition1);
    QFETCH(int, addition2);
    QFETCH(int, addition3);
    QFETCH(int, deduction);
    QFETCH(int, addition4);

    Statistics s;
    s.addScore(addition1);
    QVERIFY2(s.getScore() == addition1, "Wrong result on first case");
    s.addScore(addition2);
    QVERIFY2(s.getScore() == addition1+addition2, "Wrong result on second case");
    s.addScore(addition3);
    QVERIFY2(s.getScore() == addition1+addition2+addition3, "Wrong result on third case");
    s.addScore(deduction);
    QVERIFY2(s.getScore() == addition1+addition2+addition3+deduction,
             "Wrong result on fourth case");
    s.addScore(addition4);
    QVERIFY2(s.getScore() == addition1+addition2+addition3+deduction+addition4,
             "Wrong result on fifth case");
}

void statistics::score_data()
{
    QTest::addColumn<int>("addition1");
    QTest::addColumn<int>("addition2");
    QTest::addColumn<int>("addition3");
    QTest::addColumn<int>("deduction");
    QTest::addColumn<int>("addition4");

    QTest::newRow("score test") << 500 << 500 << 1800 << -700 << 970;
}

QTEST_APPLESS_MAIN(statistics)

#include "tst_statistics.moc"
