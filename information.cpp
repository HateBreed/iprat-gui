#include "information.h"
#include "identificationcreator.h"

QString Information::getDescription() const
{
    return description;
}

void Information::setDescription(const QString &value)
{
    description = value;
}

qint16 Information::getId() const
{
    return id;
}
Information::Information()
{
    id = identificationCreator::getInstance()->getNextInformationId();
}

