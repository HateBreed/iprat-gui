#ifndef ACTOR_H
#define ACTOR_H

#include <QJsonObject>
#include <QObject>
#include <QList>
#include "componentbase.h"
#include "information.h"
#include "connection.h"
#include "task.h"
#include "function.h"

class Actor : public ComponentBase
{
private:
    QList<Information*> iInformationList; // Withheld list
    QList<Connection*> iConnectionList;
    QList<Task*> iTaskList;
    QList<Function*> iFunctionList;
    explicit Actor(ComponentBase *parent = 0);

    bool searchFromTaskList(const Task* task);
    bool searchFromFunctionList(const Function *function);

public:
    Actor(const QString &name);
    Actor(const char* &name);
    Actor(const QString &name,
          const QList<Information*> _informations,
          const QList<Connection*> _connections,
          const QList<Task*> _tasks,
          const QList<Function*> _functions);


    void addInformation(Information* information);
    const Information* getInformation(const QString &name);
    const Information* getInformation(const qint16 &id);
    int getInformationCount();

    void addConnection(Connection* connection);
    const QList<Connection*> getConnections(enum Connection::connectionType);
    int getConnectionCount();

    void addTask(Task* task);
    const Task* getTask(const QString &name);
    int getTaskCount();

    void addFunction(Function* function);
    const Function* getFunction(const QString &name);
    int getFunctionCount();

    bool connectToActor(const Actor* actor, Connection::connectionType direction, QList<Information *> *transferredInformation);


signals:

public slots:
};

#endif // ACTOR_H
