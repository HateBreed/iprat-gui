#include "information.h"
#include "identificationcreator.h"


Information::Information(ComponentBase *parent) :
    ComponentBase(parent)
{

}

Information::Information(const QString &name, Information::informationType &type, Information::informationIdentifiability &identifiability, const int &multiplicity)
{
    iId = identificationCreator::getInstance()->getNextInformationId();
    iDescription = QString(name);
    iType = type;
    iIdentifiability = identifiability;
    iMultiplicity = multiplicity;

}

