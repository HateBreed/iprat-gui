#ifndef ACTOR_H
#define ACTOR_H

#include <QJsonObject>
#include <QObject>
#include <QList>
#include "componentbase.h"
#include "calculationstate.h"
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
    CalculationState state;

public:
    ~Actor();
    Actor(const QString &name);
    Actor(const char* &name);
    Actor(const QString &name,
          const QList<Information*> &informations,
          const QList<Connection*> &connections,
          const QList<Task*> &tasks,
          const QList<Function*> &functions);


    Q_INVOKABLE bool addInformation(Information* information);
    Q_INVOKABLE const Information* getInformation(const QString &name);
    Q_INVOKABLE const Information* getInformation(const quint16 &id);
    Q_INVOKABLE int getInformationCount();

    Q_INVOKABLE const QList<quint16> getConnections(Connection::connectionType &type);
    Q_INVOKABLE int getConnectionCount();

    Q_INVOKABLE bool addTask(const Task::taskType &type, const QString &description);
    Q_INVOKABLE const Task &getTask(const QString &name);
    Q_INVOKABLE int getTaskCount();

    Q_INVOKABLE bool addFunction(const Function::functionType &type, const QString &description);
    Q_INVOKABLE const Function& getFunction(const QString &name);
    Q_INVOKABLE int getFunctionCount();

    Q_INVOKABLE bool connectToActor(const Actor* actor, Connection::connectionType direction);
    Q_INVOKABLE bool connectToActor(const Actor* actor, Connection::connectionType direction, QList<Information *> *transferredInformation);
    Q_INVOKABLE bool disconnectFromActor(const Actor* actor, quint16 connectionId);

    Q_INVOKABLE void calculateRiskValue();

signals:

public slots:
};

#endif // ACTOR_H
