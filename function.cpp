#include <QDebug>
#include "function.h"

#include "identificationcreator.h"


QString Function::getDescription() const
{
    return iDescription;
}

void Function::setDescription(const QString &value)
{
    iDescription = value;
}

int Function::getType() const
{
    return iType;
}

void Function::setType(const functionType &value)
{
    iType = value;
}

QString Function::getTypeString() const
{
    QString typeString;
    switch(iType)
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

Function::Function(QObject *parent) :
    QObject(parent)
{

}

Function::Function(const QString &functionDescription, const Function::functionType &value)
{
    iDescription = QString(functionDescription);
    iType = value;
}

