#include "componentfactory.h"

ComponentFactory* ComponentFactory::iFactory = NULL;

ComponentFactory::ComponentFactory(QObject *parent) : QObject(parent)
{
    iFactory = this;
}


ComponentFactory* ComponentFactory::getInstance()
{
    if(!iFactory) new ComponentFactory;
    return iFactory;
}

Actor *ComponentFactory::createActor(const QString &name)
{
    return new Actor(name);
}

Actor *ComponentFactory::createActor(const QString &name, QList<Information *> &infolist, QList<Connection *> &connlist, QList<Function *> &funclist, QList<Task *> &tasklist)
{
    return new Actor(name,infolist,connlist,tasklist,funclist);
}

Connection *ComponentFactory::createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end)
{
    return new Connection(type, start, end);
}

Connection *ComponentFactory::createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end, QList<Information *> &infolist)
{
    return new Connection(type, start, end, &infolist);
}

Function *ComponentFactory::createFunction(const Function::functionType &value, const QString &description)
{
    return new Function(value, description);
}

Information *ComponentFactory::createInformation(const QString &description, Information::informationType &type, Information::informationIdentifiability &identifiability, const quint8 &multiplicity)
{
    return new Information(description,type,identifiability,multiplicity);
}

Task *ComponentFactory::createTask(const Task::taskType &type, const QString &description)
{
    return new Task(type,description);
}
