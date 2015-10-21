#include "task.h"

QString Task::getDescription() const
{
    return description;
}

void Task::setDescription(const QString &value)
{
    description = value;
}

int Task::getMultiplicity() const
{
    return multiplicity;
}

void Task::setMultiplicity(int value)
{
    multiplicity = value;
}

Task::Task(const taskType &abstractType)
{
    type = abstractType;
}

