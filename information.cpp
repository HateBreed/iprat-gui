#include "information.h"
#include "identificationcreator.h"

QString Information::getDescription() const
{
    return iDescription;
}

void Information::setDescription(const QString &value)
{
    iDescription = QString(value);
}

qint16 Information::getId() const
{
    return iId;
}
Information::Information(QObject *parent) :
    QObject(parent)
{

}

Information::Information(const QString &name, Information::informationType type, Information::informationIdentifiability identifiability, const int multiplicity)
{
    iId = identificationCreator::getInstance()->getNextInformationId();
    iDescription = QString(name);
    iType = type;
    iIdentifiability = identifiability;
    iMultiplicity = multiplicity;

}

