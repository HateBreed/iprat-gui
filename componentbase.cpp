#include <QDebug>
#include "componentbase.h"
#include "identificationcreator.h"

quint16 ComponentBase::getId() const
{
    return iId;
}

QString ComponentBase::getDescription() const
{
    return iDescription;
}

void ComponentBase::setDescription(const QString &value)
{
    iDescription = value;
}

ComponentBase::ComponentBase(QObject *parent) : QObject(parent)
{

}

