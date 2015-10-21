#include "mainwindow.h"
#include <QApplication>
#include "identificationcreator.h"
#include <QDebug>
#include "actor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<Actor*> actors;
    for(int i = 0; i < 10; i++)
    {
        Actor* actor;
        actor = new Actor("test");
        actors.append(actor);
    }

    QListIterator<Actor*> iter(actors);
    while(iter.hasNext())
    {
        Actor* a = iter.next();
        qDebug() << "Actor" << a->getId() << " named \"" << a->getDescription() << "\".";
    }


    return a.exec();
}
