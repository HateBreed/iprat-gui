#ifndef ACTOR_H
#define ACTOR_H

#include <QJsonObject>
#include <QObject>
#include <QList>
#include "information.h"
#include "connection.h"
#include "task.h"
#include "function.h"

class Actor : public QObject
{
private:
    QString description;
    qint16 id; //unique
    QList<Information*> informations;
    QList<Connection*> connections;
    QList<Task*> tasks;
    QList<Function*> functions;
    Actor();

public:

    Actor(const QString &name);
    Actor(const QList<Information*> _informations,
          const QList<Connection*> _connections,
          const QList<Task*> _tasks,
          const QList<Function*> _functions);


    void addInformation(Information &information);
    const Information* getInformation(const QString &name);
    const Information* getInformation(const qint16 &id);
    int getInformationCount();

    void addConnection(Connection &connection);
    const QList<Connection*> getConnections(enum Connection::connectionType);
    int getConnectionCount();

    void addTask(Task  &task);
    const Task* getTask(const QString name);
    int getTaskCount();

    void addFunction(Function &function);
    const Function* getFunction(const QString name);
    int getFunctionCount();


    const QString getDescription() const;
    void setDescription(const QString &value);

signals:

public slots:
};

#endif // ACTOR_H
