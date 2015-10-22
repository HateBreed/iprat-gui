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
    QList<Information> iInformationList;
    explicit Connection(ComponentBase *parent = 0);
public:
    enum connectionType {
        CONN_IN,
        CONN_OUT,
        CONN_BI
    };
    connectionType iType;

    Connection(const connectionType &value, const qint16 &start, const qint16 &end);

    connectionType getType() const;
    void setType(const connectionType &value);

    const QString getTypeString() const;

    qint16 getStartConnection();
    qint16 getEndConnection();
    qint16 *getConnectionEndpoints();

signals:

public slots:
};

#endif // CONNECTION_H
