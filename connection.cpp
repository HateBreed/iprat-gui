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

qint16 Connection::getStartConnection()
{
    return iActorStart;
}

qint16 Connection::getEndConnection()
{
    return iActorEnd;
}

qint16 *Connection::getConnectionEndpoints()
{
    qint16* endpoints = new qint16[2];
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
                       const qint16 &start,
                       const qint16 &end)
{
    iId = identificationCreator::getInstance()->getNextConnectionId();
    iType = value;
    iActorStart = start;
    iActorEnd = end;
}

Connection::Connection(const Connection::connectionType &value, const qint16 &start, const qint16 &end, QList<Information *> *informationList)
{
    Connection(value,start,end);
    iInformationList = QList<Information*>(*informationList);
}


