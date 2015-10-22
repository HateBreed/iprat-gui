#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "componentbase.h"
#include "information.h"

class Connection : public ComponentBase
{
    Q_ENUMS(connectionType)
private:
    qint16 iActorStart;
    qint16 iActorEnd;
    QList<Information*> iInformationList; // Information transferred in this connection
    explicit Connection(ComponentBase *parent = 0);
    bool searchFromInformationList(Information* information);
public:
    enum connectionType {
        CONN_IN,
        CONN_OUT,
        CONN_BI
    };
    connectionType iType;

    Connection(const connectionType &value, const qint16 &start, const qint16 &end);
    Connection(const connectionType &value, const qint16 &start, const qint16 &end, QList<Information*> *informationList);

    connectionType getType();
    void setType(const connectionType &value);

    qint16 getStartConnection();
    qint16 getEndConnection();
    qint16 *getConnectionEndpoints();

    bool addInformation(Information* information);

signals:

public slots:
};

#endif // CONNECTION_H
