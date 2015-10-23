#include <QDebug>
#include "actor.h"
#include "identificationcreator.h"
#include "utilities.h"

Actor::Actor(ComponentBase *parent) : ComponentBase(parent)
{

}

Actor::~Actor()
{
    foreach (Information* info, iInformationList) if(info) delete info;
    foreach (Connection* conn, iConnectionList) if(conn) delete conn;
    foreach (Function* func, iFunctionList) if(func) delete func;
    foreach (Task* task, iTaskList) if(task) delete task;
}

bool Actor::searchFromTaskList(const Task *task)
{
    QListIterator<Task*> iterator(iTaskList);
    while(iterator.hasNext())
    {
        Task* t = iterator.next();
        if(*t == *task) return true;
    }
    return false;
}

bool Actor::searchFromFunctionList(const Function *function)
{
    QListIterator<Function*> iterator(iFunctionList);
    while (iterator.hasNext())
    {
        Function* f = iterator.next();
        if(*f == *function) return true;
    }
    return false;
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

const Information *Actor::getInformation(const quint16 &id)
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

/**
 * @brief Actor::getConnections
 * @param type
 * @return QList of connection id's, empty if type is invalid, all if type is 0
 */
const QList<quint16> Actor::getConnections(enum Connection::connectionType &type)
{
    QList<quint16> selected;

    // Return all
    if(type == 0)
       foreach (Connection* conn, iConnectionList) selected.append(conn->getId());

    else if (Utilities::isValidConnectionType(type))
    {
        QListIterator<Connection*> iterator(iConnectionList);
        while(iterator.hasNext())
        {
            Connection* item = iterator.next();
            if(item->getType() == type) {
                qDebug() << "Found connection with requested type \"" << Utilities::transferConnectionTypeToString(item->getType()) << "\"";
                selected.append(item->getId());
            }
        }
    }
    return selected; // Empty list if not valid
}

/**
 * @brief Actor::getConnectionCount
 * @return
 */
int Actor::getConnectionCount()
{
    return iConnectionList.size();
}

/**
 * @brief Actor::addTask
 * @param task
 * @return true if added (other with same id does not exist in list), false otherwise
 */
bool Actor::addTask(const Task::taskType &type, const QString &description)
{
    if(!Utilities::isValidTaskType(type)) return false;

    Task* task = new Task(type,description);
    if(searchFromTaskList(task))
    {
        qDebug() << "Found existing task with id " << task->getType();
        delete task;
        return false;
    }
    //else if(getTask(task->getDescription()) != NULL) qDebug() << "Found existing task with name " << task->getDescription();
    iTaskList.append(task);
    qDebug() << "Added task with id " << task->getType();
    return true;
}

/**
 * @brief Actor::getTask
 * @param name
 * @return
 */
const Task& Actor::getTask(const QString &name)
{
    QListIterator<Task*> iterator(iTaskList);
    Task* item;

    while(iterator.hasNext())
    {
        item = iterator.next();
        if(item->getDescription() == name) {
            qDebug() << "Found task with \"" << name << "\"";
            return *item;
        }

    }
    return *item;
}

/**
 * @brief Actor::getTaskCount
 * @return
 */
int Actor::getTaskCount()
{
    return iTaskList.size();
}

/**
 * @brief Actor::addFunction
 * @param type
 * @param description
 * @return
 */
bool Actor::addFunction(const Function::functionType &type, const QString &description)
{
    if(!Utilities::isValidFunctionType(type)) return false;

    Function* function = new Function(type,description);

    if(searchFromFunctionList(function))
    {
        qDebug() << "Found existing function with id " << function->getType();
        delete function;
        return false;
    }
    qDebug() << "Added function with id " << function->getType();
    iFunctionList.append(function);
    return true;
}

/**
 * @brief Actor::getFunction
 * @param name
 * @return
 */
const Function& Actor::getFunction(const QString &name)
{
    QListIterator<Function*> iterator(iFunctionList);
    Function* item;
    while(iterator.hasNext())
    {
        item = iterator.next();
        if(item->getDescription() == name) {
            qDebug() << "Found function with \"" << name << "\"";
            return *item;
        }

    }
    return *item;
}

/**
 * @brief Actor::getFunctionCount
 * @return
 */
int Actor::getFunctionCount()
{
    return iFunctionList.size();
}

/**
 * @brief Actor::connectToActor
 * @param actor
 * @param direction
 * @param transferredInformation
 * @return
 */
bool Actor::connectToActor(const Actor *actor, Connection::connectionType direction, QList<Information *> *transferredInformation)
{
    if(!actor) return false;
    if(getId() == actor->getId()) return false;
    if(!Utilities::isValidConnectionType(direction)) return false;

    Connection* conn = new Connection(direction,getId(), actor->getId(),transferredInformation);

    iConnectionList.append(conn);

    return true;
}

