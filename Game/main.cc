#include "gameengine.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    GameEngine *engine = new GameEngine;
    engine->start();

    return a.exec();
}
