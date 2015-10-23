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
    ~Actor();
    Actor(const QString &name);
    Actor(const char* &name);
    Actor(const QString &name,
          const QList<Information*> _informations,
          const QList<Connection*> _connections,
          const QList<Task*> _tasks,
          const QList<Function*> _functions);


    void addInformation(Information* information);
    const Information* getInformation(const QString &name);
    const Information* getInformation(const quint16 &id);
    int getInformationCount();

    const QList<quint16> getConnections(Connection::connectionType &type);
    int getConnectionCount();

    bool addTask(const Task::taskType &type, const QString &description);
    const Task &getTask(const QString &name);
    int getTaskCount();

    bool addFunction(const Function::functionType &type, const QString &description);
    const Function& getFunction(const QString &name);
    int getFunctionCount();

    bool connectToActor(const Actor* actor, Connection::connectionType direction);
    bool connectToActor(const Actor* actor, Connection::connectionType direction, QList<Information *> *transferredInformation);
    bool disconnectFromActor(const Actor* actor, quint16 connectionId);

signals:

public slots:
};

#endif // ACTOR_H
