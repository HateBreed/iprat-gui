#include "connection.h"

#include "identificationcreator.h"

Connection::connectionType Connection::getType()
{
    return iType;
}

void Connection::setType(const connectionType &value)
{
    iType = value;
}

const quint16& Connection::getStartConnection()
{
    return iActorStart;
}

const quint16& Connection::getEndConnection()
{
    return iActorEnd;
}

quint16 *Connection::getConnectionEndpoints()
{
    quint16* endpoints = new quint16[2];
    endpoints[0] = iActorStart;
    endpoints[1] = iActorEnd;
    return endpoints;
}

bool Connection::addInformation(Information *information)
{
    if(searchFromInformationList(information)) return true;
    iInformationList.append(information);
    return true;
}

Connection::Connection(ComponentBase *parent) :
    ComponentBase(parent)
{

}

bool Connection::searchFromInformationList(Information *information)
{
    QListIterator<Information*> iterator(iInformationList);
    while(iterator.hasNext())
    {
        Information* i = iterator.next();
        if(i->getId() == information->getId()) return true;
    }
    return false;
}

Connection::Connection(const Connection::connectionType &value,
                       const quint16 &start,
                       const quint16 &end)
{
    iId = identificationCreator::getInstance()->getNextConnectionId();
    iType = value;
    iActorStart = start;
    iActorEnd = end;
}

Connection::Connection(const Connection::connectionType &value, const quint16 &start, const quint16 &end, QList<Information *> *informationList)
{
    Connection(value,start,end);
    if(informationList) iInformationList = QList<Information*>(*informationList);
}

bool Connection::operator==(const Connection &connection)
{
    if(getType() == connection.iType) return true;
    else if(getId() == connection.iId) return true;
    else return false;
}


