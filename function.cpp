#include "function.h"

#include "identificationcreator.h"


QString Function::getDescription() const
{
    return description;
}

void Function::setDescription(const QString &value)
{
    description = value;
}

int Function::getType() const
{
    return type;
}

void Function::setType(const functionType &value)
{
    type = value;
}

QString Function::getTypeString() const
{
    QString typeString;
    switch(type)
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
Function::Function()
{

}

Function::Function(const QString &functionDescription, const Function::functionType &value)
{
    description = QString(functionDescription);
    type = value;
}

