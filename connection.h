#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "information.h"

class Connection : public QObject
{
    Q_OBJECT
    Q_ENUMS(connectionType)
private:
    qint16 id;
    qint16 actorStart;
    qint16 actorEnd;
    QList<Information> datalist;
    Connection();
public:
    enum connectionType {
        CONN_IN,
        CONN_OUT,
        CONN_BI
    };
    connectionType type;
    Connection(const connectionType &value, const qint16 &start, const qint16 &end);

    connectionType getType() const;
    void setType(const connectionType &value);

    const QString getTypeString() const;

    qint16 getId();
    qint16 getStartConnection();
    qint16 getEndConnection();
    qint16 *getConnectionEndpoints();

signals:

public slots:
};

#endif // CONNECTION_H
