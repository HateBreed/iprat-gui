#include <QDebug>
#include "actor.h"
#include "identificationcreator.h"

Actor::Actor(ComponentBase *parent) : ComponentBase(parent)
{

}

Actor::Actor(const QString &name)
{
    iId = identificationCreator::getInstance()->getNextActorId();
    iDescription = QString(name);
}

Actor::Actor(const char *&name)
{
    iId = identificationCreator::getInstance()->getNextActorId();
    iDescription = QString(name);
}

Actor::Actor(const QString &name,
             const QList<Information*> _informations,
             const QList<Connection*> _connections,
             const QList<Task*> _tasks,
             const QList<Function*> _functions)
{
    iDescription = QString(name);
    iId = identificationCreator::getInstance()->getNextActorId();
    iInformationList = QList<Information*>(_informations);
    iConnectionList = QList<Connection*>(_connections);
    iTaskList = QList<Task*>(_tasks);
    iFunctionList = QList<Function*>(_functions);
}

void Actor::addInformation(Information* information)
{
    iInformationList.append(information);
}

const Information* Actor::getInformation(const QString &name)
{
    QListIterator<Information*> iterator(iInformationList);

    while(iterator.hasNext())
    {
        Information* item = iterator.next();
        if(item->getDescription() == name) {
            qDebug() << "Found information with \"" << name << "\"";
            return item;
        }

    }
    return NULL;
}

const Information *Actor::getInformation(const qint16 &id)
{
    QListIterator<Information*> iterator(iInformationList);

    while(iterator.hasNext())
    {
        Information* item = iterator.next();
        if(item->getId() == id) {
            qDebug() << "Found information with \"" << id << "\"";
            return item;
        }

    }
    return NULL;
}

int Actor::getInformationCount()
{
    return iInformationList.size();
}

void Actor::addConnection(Connection* connection)
{
    iConnectionList.append(connection);
}

const QList<Connection*> Actor::getConnections(enum Connection::connectionType type)
{
    QListIterator<Connection*> iterator(iConnectionList);
    QList<Connection*> selected;

    while(iterator.hasNext())
    {
        Connection* item = iterator.next();
        if(item->getType() == type) {
            qDebug() << "Found connection with requested type \"" << item->getTypeString() << "\"";
            selected.append(item);
        }

    }
    return selected;
}

int Actor::getConnectionCount()
{
    return iConnectionList.size();
}

void Actor::addTask(Task* task)
{
    iTaskList.append(task);
}

const Task* Actor::getTask(const QString &name)
{
    QListIterator<Task*> iterator(iTaskList);

    while(iterator.hasNext())
    {
        Task* item = iterator.next();
        if(item->getDescription() == name) {
            qDebug() << "Found task with \"" << name << "\"";
            return item;
        }

    }
    return NULL;
}

int Actor::getTaskCount()
{
    return iTaskList.size();
}

void Actor::addFunction(Function* function)
{
    iFunctionList.append(function);
}

const Function* Actor::getFunction(const QString &name)
{
    QListIterator<Function*> iterator(iFunctionList);

    while(iterator.hasNext())
    {
        Function* item = iterator.next();
        if(item->getDescription() == name) {
            qDebug() << "Found function with \"" << name << "\"";
            return item;
        }

    }
    return NULL;
}

int Actor::getFunctionCount()
{
    return iFunctionList.size();
}

