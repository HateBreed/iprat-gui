#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include "information.h"

class Connection : public QObject
{
    Q_OBJECT
    Q_ENUMS(connectionType)
private:

    QList<Information> datalist;
public:
    enum connectionType {CONN_IN,CONN_OUT,CONN_BI};
    Connection();
    Connection(enum connectionType);



signals:

public slots:
};

#endif // CONNECTION_H
