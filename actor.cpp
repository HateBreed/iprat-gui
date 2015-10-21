#include "actor.h"
#include "identificationcreator.h"

QString Actor::getDescription() const
{
    return description;
}

void Actor::setDescription(const QString &value)
{
    description = value;
}

Actor::Actor()
{
    id = identificationCreator::getInstance()->getNextActorId();
}

Actor::Actor(const QString &name)
{
    description = name;
}

Actor::Actor(const QList<Information> _informations, const QList<Connection> _connections, const QList<Task> _tasks, const QList<Function> _functions)
{
    informations = _informations.C
}

