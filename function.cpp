#include <QDebug>
#include "function.h"

#include "identificationcreator.h"


Function::functionType Function::getType() const
{
    return (functionType)iId;
}

void Function::setType(const functionType &value)
{
    iId = value;
}

QString Function::getTypeString() const
{
    QString typeString;
    switch(iId)
    {
    case ADMINISTRATION:
        typeString = "Administration";
        break;
    case GENERATION:
        typeString = "Generation";
        break;
    case MANAGEMENT:
        typeString = "Management";
        break;
    case MEASUREMENT:
        typeString = "Measurement";
        break;
    case MONITORING:
        typeString = "Monitoring";
        break;
    case PROCESSING:
        typeString = "Processing";
        break;
    case STATISTICS_CREATION:
        typeString = "Statistics creation";
        break;
    case VALUE_ADDED_SERVICES:
        typeString = "Value added services";
        break;
    default:
        typeString = "";
    }
    return typeString;
}

Function::Function(ComponentBase *parent) :
    ComponentBase(parent)
{

}

Function::Function(const QString &functionDescription, const Function::functionType &value)
{
    iDescription = QString(functionDescription);

    iId = value;
    //qDebug() << "Function Id = " << getType() << "\"" << getTypeString() << "\"";
}

