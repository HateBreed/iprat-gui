#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>
#include "identificationcreator.h"
#include "utilities.h"
#include "actor.h"
#include "componentbase.h"
#include "componentfactory.h"

quint16 randTask()
{
    quint16 id = 0;
    while(!Utilities::isValidTaskType((Task::taskType)id))
        id = qrand() % 10;
    return id;
}

quint16 randFunction()
{
    quint16 id = 0;
    while(!Utilities::isValidFunctionType((Function::functionType)id))
        id = qrand() % 10;
    return id;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QList<Actor*> actors;
    qsrand((uint)QTime::currentTime().msec());
    ComponentFactory* factory = ComponentFactory::getInstance();

    for(int i = 0; i < 3; i++)
    {
        Actor* actor = factory->createActor("test");
        qDebug() << "Created actor" << actor->getId();
        for(int i = 0; i < 8 ; i++, actor->addTask((Task::taskType)randTask(),QString("")));
        for(int j = 0; j < 8 ; j++, actor->addFunction((Function::functionType)randFunction(),QString("Something")));
        actors.append(actor);
    }

    actors.at(2)->connectToActor(actors.at(0),Connection::CONN_OUT,NULL);

    QListIterator<Actor*> iter(actors);
    while(iter.hasNext())
    {
        Actor* a = iter.next();
        qDebug() << "Actor" << a->getId() << " named \"" << a->getDescription() << "\".";
        qDebug() << "With " << a->getTaskCount() << " tasks, " << a->getFunctionCount() << " functions, " << a->getConnectionCount()
                 << " connections.";
    }
    foreach(Actor* ac, actors) if(ac) delete ac;


    return a.exec();
}
