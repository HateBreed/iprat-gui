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
    QList<Information> informations;
    QList<Connection> connections;
    QList<Task> tasks;
    QList<Function> functions;


public:
    Actor();
    Actor(const QString &name);
    Actor(const QList<Information> _informations,
          const QList<Connection> _connections,
          const QList<Task> _tasks,
          const QList<Function> _functions);


    void addInformation(Information &information);
    Information getInformation(const QString &name);
    int getInformationCount();

    void addConnection(Connection &connection);
    Connection getConnection(const QString name);
    int getConnectionCount();

    void addTask(Task  &task);
    Task getTask(const QString name);
    int getTaskCount();

    void addFunction(Function &function);
    Function getFunction(const QString name);
    int getFunctionCount();


    QString getDescription() const;
    void setDescription(const QString &value);

signals:

public slots:
};

#endif // ACTOR_H
