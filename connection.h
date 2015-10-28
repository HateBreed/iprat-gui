#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "componentbase.h"
#include "information.h"

class Connection : public ComponentBase
{
    Q_ENUMS(connectionType)
private:
    quint16 iActorStart;
    quint16 iActorEnd;
    QList<Information*> iInformationList; // Information transferred in this connection
    explicit Connection(ComponentBase *parent = 0);
    bool searchFromInformationList(Information* information);
public:
    enum connectionType {
        CONN_IN=1,
        CONN_OUT,
        CONN_BI
    };
    connectionType iType;

    Connection(const connectionType &value, const quint16 &start, const quint16 &end);
    Connection(const connectionType &value, const quint16 &start, const quint16 &end, QList<Information *> *informationList);

    bool operator==(const Connection &connection);

    Q_INVOKABLE connectionType getType();
    Q_INVOKABLE void setType(const connectionType &value);

    Q_INVOKABLE const quint16& getStartConnection();
    Q_INVOKABLE const quint16& getEndConnection();
    Q_INVOKABLE quint16 *getConnectionEndpoints();

    Q_INVOKABLE bool addInformation(Information* information);

signals:

public slots:
};

#endif // CONNECTION_H
