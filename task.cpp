#include "task.h"

int Task::getMultiplicity() const
{
    return iMultiplicity;
}

void Task::setMultiplicity(int value)
{
    iMultiplicity = value;
}

Task::taskType Task::getType() const
{
    return (taskType)iId;
}

void Task::setType(const Task::taskType &abstractType)
{
    iId = (int)abstractType;
}

Task::Task(const Task::taskType &abstractType)
{
    iId = abstractType;
}

Task::Task(const QString &taskDescription, const Task::taskType &abstractType)
{
    iDescription = QString(taskDescription);
    iId = abstractType;
}

Task::Task(ComponentBase *parent) :
    ComponentBase(parent)
{

}

