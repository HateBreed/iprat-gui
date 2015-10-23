#include "information.h"
#include "identificationcreator.h"


Information::Information(ComponentBase *parent) :
    ComponentBase(parent)
{

}

informationType Information::getType() const
{
    return iType;
}

void Information::setType(const informationType &value)
{
    iType = value;
}

informationIdentifiability Information::getIdentifiability() const
{
    return iIdentifiability;
}

void Information::setIdentifiability(const informationIdentifiability &value)
{
    iIdentifiability = value;
}

Information::Information(const QString &name, Information::informationType &type, Information::informationIdentifiability &identifiability, const int &multiplicity)
{
    iId = identificationCreator::getInstance()->getNextInformationId();
    iDescription = QString(name);
    iType = type;
    iIdentifiability = identifiability;
    iMultiplicity = multiplicity;

}

bool Information::operator==(const Information &information)
{
    if( this->getId() == information.getId()) return true;
    // Allow multiple same type information with different identibiability (?)
    else if(this->getIdentifiability() == information.getIdentifiability() &&
            this->getType() == information.getType()) return true;
    return false;
}

