#include "connection.h"

#include "identificationcreator.h"

Connection::connectionType Connection::getType() const
{
    return iType;
}

void Connection::setType(const connectionType &value)
{
    iType = value;
}

const QString Connection::getTypeString() const
{
    QString typeString;
    switch(iType)
    {
    case CONN_BI:
        typeString = "Bidirectional";
        break;
    case CONN_IN:
        typeString = "Direction IN";
        break;
    case CONN_OUT:
        typeString = "Direction OUT";
        break;
    default:
        typeString = "";
    }
    return typeString;
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

Connection::Connection(ComponentBase *parent) :
    ComponentBase(parent)
{

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


