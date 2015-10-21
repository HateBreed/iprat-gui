#include "connection.h"

#include "identificationcreator.h"

Connection::connectionType Connection::getType() const
{
    return type;
}

void Connection::setType(const connectionType &value)
{
    type = value;
}

const QString Connection::getTypeString() const
{
    QString typeString;
    switch(type)
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

qint16 Connection::getId()
{
    return id;
}

qint16 Connection::getStartConnection()
{
    return actorStart;
}

qint16 Connection::getEndConnection()
{
    return actorEnd;
}

qint16 *Connection::getConnectionEndpoints()
{
    qint16* endpoints = new qint16[2];
    endpoints[0] = actorStart;
    endpoints[1] = actorEnd;
    return endpoints;
}

Connection::Connection()
{
    id = identificationCreator::getInstance()->getNextConnectionId();
}

Connection::Connection(const Connection::connectionType &value,
                       const qint16 &start,
                       const qint16 &end)
{
    type = value;
    actorStart = start;
    actorEnd = end;
}


