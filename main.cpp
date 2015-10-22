#include "mainwindow.h"
#include <QApplication>
#include "identificationcreator.h"
#include <QDebug>
#include "actor.h"
#include "componentbase.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<Actor*> actors;
    Actor* actor;
    for(int i = 0; i < 10; i++)
    {
        actor = new Actor("test");
        actor->addTask(new Task(Task::controlling));
        actor->addTask(new Task(Task::source));
        actor->addFunction(new Function("Something",Function::ADMINISTRATION));
        actor->addFunction(new Function("Something2",Function::MEASUREMENT));
        actors.append(actor);
    }

    QListIterator<Actor*> iter(actors);
    while(iter.hasNext())
    {
        Actor* a = iter.next();
        qDebug() << "Actor" << a->getId() << " named \"" << a->getDescription() << "\".";
        qDebug() << "With " << a->getTaskCount() << " tasks, " << a->getFunctionCount() << " functions, " << a->getConnectionCount()
                 << " connections.";
    }


    return a.exec();
}
