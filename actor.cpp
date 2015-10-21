#include <QDebug>
#include "actor.h"
#include "identificationcreator.h"

const QString Actor::getDescription() const
{
    return description;
}

void Actor::setDescription(const QString &value)
{
    description = QString(value);
}

qint16 Actor::getId() const
{
    return id;
}

Actor::Actor()
{
    id = identificationCreator::getInstance()->getNextActorId();
}

Actor::Actor(const QString &name)
{
    id = identificationCreator::getInstance()->getNextActorId();
    description = QString(name);
}

Actor::Actor(const char *&name)
{
    id = identificationCreator::getInstance()->getNextActorId();
    description = QString(name);
}

Actor::Actor(const QList<Information*> _informations,
             const QList<Connection*> _connections,
             const QList<Task*> _tasks,
             const QList<Function*> _functions)
{
    id = identificationCreator::getInstance()->getNextActorId();
    informations = QList<Information*>(_informations);
    connections = QList<Connection*>(_connections);
    tasks = QList<Task*>(_tasks);
    functions = QList<Function*>(_functions);
}

void Actor::addInformation(Information* information)
{
    informations.append(information);
}

const Information* Actor::getInformation(const QString &name)
{
    QListIterator<Information*> iterator(informations);

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
    QListIterator<Information*> iterator(informations);

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
    return informations.size();
}

void Actor::addConnection(Connection* connection)
{
    connections.append(connection);
}

const QList<Connection*> Actor::getConnections(enum Connection::connectionType type)
{
    QListIterator<Connection*> iterator(connections);
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
    return connections.size();
}

void Actor::addTask(Task* task)
{
    tasks.append(task);
}

const Task* Actor::getTask(const QString name)
{
    QListIterator<Task*> iterator(tasks);

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
    return tasks.size();
}

void Actor::addFunction(Function* function)
{
    functions.append(function);
}

const Function* Actor::getFunction(const QString name)
{
    QListIterator<Function*> iterator(functions);

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
    return functions.size();
}

