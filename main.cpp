#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>
#include "identificationcreator.h"
#include "utilities.h"
#include "actor.h"
#include "componentbase.h"

qint16 randTask()
{
    qint16 id = 0;
    while(!Utilities::isValidTaskType((Task::taskType)id))
        id = qrand() % 10;
    return id;
}

qint16 randFunction()
{
    qint16 id = 0;
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
    Actor* actor;
    qsrand((uint)QTime::currentTime().msec());

    for(int i = 0; i < 3; i++)
    {
        actor = new Actor("test");
        for(int i = 0; i < 8 ; i++, actor->addTask(new Task(Task::taskType(randTask()))));
        for(int j = 0; j < 8 ; j++, actor->addFunction(new Function("Something", Function::functionType(randFunction()))));
        actors.append(actor);
    }

    actor->connectToActor(actors.at(0),Connection::CONN_OUT,NULL);

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
