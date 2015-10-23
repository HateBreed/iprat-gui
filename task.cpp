#include <QDebug>
#include "task.h"
#include "utilities.h"

int Task::getMultiplicity() const
{
    return iMultiplicity;
}

void Task::setMultiplicity(int &value)
{
    iMultiplicity = value;
}

Task::taskType Task::getType() const
{
    return (taskType)iId;
}

bool Task::setType(const Task::taskType &abstractType)
{
    if(!Utilities::isValidTaskType(abstractType)) return false;

    iId = (int)abstractType;
    return true;
}

QString Task::getTypeString() const
{
    return Utilities::transferTaskTypetoString(getType());
}

bool Task::addInformation(Information *information)
{
    if(searchFromList(information)) return false;
    iInformationList.append(information);
    return true;
}

Task::Task(const Task::taskType &abstractType)
{
    iId = abstractType;
    //qDebug() << "Task Id = " << getType() << "\"" << getTypeString() << "\"";
}

Task::Task(const QString &taskDescription, const Task::taskType &abstractType)
{
    iDescription = QString(taskDescription);
    iId = abstractType;

}

bool Task::operator==(const Task &task)
{
    return this->getType() == task.getType();
}

Task::Task(ComponentBase *parent) :
    ComponentBase(parent)
{

}

bool Task::searchFromList(const Information *information)
{
    QListIterator<Information*> iterator(iInformationList);
    while(iterator.hasNext()) {
        Information* i = iterator.next();
        if(i->getId() == information->getId()) return true; // Should not ever happen
        if(i->getDescription() == information->getDescription()) return true;
    }
    return false;
}

