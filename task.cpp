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

bool Task::setType(const Task::taskType &abstractType)
{
    if(!isValidType(abstractType)) return false;

    iId = (int)abstractType;
    return true;
}

QString Task::getTypeString() const
{
    return transferTypetoString(getType());
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

bool Task::isValidType(const Task::taskType &type)
{
    // True, when string is not empty, false other
    return !transferTypetoString(type).isEmpty();
}

QString Task::transferTypetoString(Task::taskType type) const
{
    QString string;
    switch(type) {
    case controlling:
        string = QString("Controlling");
        break;
    case source:
        string = QString("Source");
        break;
    case reading:
        string = QString("Reading");
        break;
    case processing:
        string = QString("Processing");
        break;
    case storing:
        string = QString("Storing");
        break;
    case lowaccess:
        string = QString("Low level accessing");
        break;
    case highaccess:
        string = QString("High level accessing");
        break;
    default:
        string = QString("");
    }
    return string;
}

