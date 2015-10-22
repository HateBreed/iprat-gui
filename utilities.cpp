#include "utilities.h"



Utilities::Utilities(QObject *parent) : QObject(parent)
{

}

bool Utilities::isValidTaskType(const Task::taskType &type)
{
    // True, when string is not empty, false other
    return !Utilities::transferTaskTypetoString(type).isEmpty();
}

QString Utilities::transferTaskTypetoString(const Task::taskType &type)
{
    QString string;
    switch(type) {
    case Task::controlling:
        string = QString("Controlling");
        break;
    case Task::source:
        string = QString("Source");
        break;
    case Task::reading:
        string = QString("Reading");
        break;
    case Task::processing:
        string = QString("Processing");
        break;
    case Task::storing:
        string = QString("Storing");
        break;
    case Task::lowaccess:
        string = QString("Low level accessing");
        break;
    case Task::highaccess:
        string = QString("High level accessing");
        break;
    default:
        string = QString("");
    }
    return string;
}

bool Utilities::isValidFunctionType(const Function::functionType &type)
{
    return !Utilities::transferFunctionTypeToString(type).isEmpty();
}

QString Utilities::transferFunctionTypeToString(const Function::functionType &type)
{
    QString typeString;
    switch(type)
    {
    case Function::ADMINISTRATION:
        typeString = "Administration";
        break;
    case Function::GENERATION:
        typeString = "Generation";
        break;
    case Function::MANAGEMENT:
        typeString = "Management";
        break;
    case Function::MEASUREMENT:
        typeString = "Measurement";
        break;
    case Function::MONITORING:
        typeString = "Monitoring";
        break;
    case Function::PROCESSING:
        typeString = "Processing";
        break;
    case Function::STATISTICS_CREATION:
        typeString = "Statistics creation";
        break;
    case Function::VALUE_ADDED_SERVICES:
        typeString = "Value added services";
        break;
    default:
        typeString = "";
    }
    return typeString;
}

bool Utilities::isValidConnectionType(const Connection::connectionType &type)
{
    return !Utilities::transferConnectionTypeToString(type).isEmpty();
}

QString Utilities::transferConnectionTypeToString(const Connection::connectionType &type)
{
    QString typeString;
    switch(type)
    {
    case Connection::CONN_BI:
        typeString = "Bidirectional";
        break;
    case Connection::CONN_IN:
        typeString = "Direction IN";
        break;
    case Connection::CONN_OUT:
        typeString = "Direction OUT";
        break;
    default:
        typeString = "";
    }
    return typeString;
}
