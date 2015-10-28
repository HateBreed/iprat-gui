#include <QDebug>
#include "function.h"

#include "identificationcreator.h"
#include "utilities.h"


Function::functionType Function::getType() const
{
    return (functionType)iId;
}

bool Function::setType(const functionType &value)
{
    if(!Utilities::isValidFunctionType(value)) return false;
    iId = value;
    return true;
}

QString Function::getTypeString() const
{
    return Utilities::transferFunctionTypeToString(getType());
}

bool Function::addInformation(Information *information)
{
    if(iInformationIdList.contains(information->getId())) return false;
    iInformationIdList.append(information->getId());
    return true;
}

const QList<quint16> *Function::getInformationList()
{
    return &iInformationIdList;
}

bool Function::hasInformation(Information *information)
{
    return(iInformationIdList.contains(information->getId()));
}

Function::Function(ComponentBase *parent) :
    ComponentBase(parent)
{

}

Function::Function(const Function::functionType &value, const QString &functionDescription)
{
    iDescription = QString(functionDescription);

    iId = value;
    //qDebug() << "Function Id = " << getType() << "\"" << getTypeString() << "\"";
}

bool Function::operator==(const Function &function)
{
    return this->getType() == function.getType();
}

