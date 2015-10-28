#ifndef COMPONENTFACTORY_H
#define COMPONENTFACTORY_H

#include <QObject>
#include <QList>
#include "actor.h"
#include "connection.h"
#include "function.h"
#include "information.h"
#include "task.h"

class ComponentFactory : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE static ComponentFactory *getInstance();
    Q_INVOKABLE Actor* createActor(const QString &name);
    Q_INVOKABLE Actor* createActor(const QString &name,
                       QList<Information*> &infolist,
                       QList<Connection*> &connlist,
                       QList<Function*> &funclist,
                       QList<Task*> &tasklist);
    Q_INVOKABLE Connection* createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end);
    Q_INVOKABLE Connection* createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end, QList<Information*> &infolist);
    Q_INVOKABLE Function* createFunction(const Function::functionType &value, const QString &description);
    Q_INVOKABLE Information* createInformation(const QString &description, Information::informationType &type, Information::informationIdentifiability &identifiability, const quint8 &multiplicity);
    Q_INVOKABLE Task* createTask(const Task::taskType &type, const QString &description);
private:
    explicit ComponentFactory(QObject *parent = 0);
    static ComponentFactory* iFactory;

signals:

public slots:
};

#endif // COMPONENTFACTORY_H
