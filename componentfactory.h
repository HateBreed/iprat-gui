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
    static ComponentFactory *getInstance();
    Actor* createActor(const QString &name);
    Actor* createActor(const QString &name,
                       QList<Information*> &infolist,
                       QList<Connection*> &connlist,
                       QList<Function*> &funclist,
                       QList<Task*> &tasklist);
    Connection* createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end);
    Connection* createConnection(const Connection::connectionType &type, const quint16 &start, const quint16 &end, QList<Information*> &infolist);
    Function* createFunction(const Function::functionType &value, const QString &description);
    Information* createInformation(const QString &description, Information::informationType &type, Information::informationIdentifiability &identifiability, const quint8 &multiplicity);
    Task* createTask(const Task::taskType &type, const QString &description);
private:
    explicit ComponentFactory(QObject *parent = 0);
    static ComponentFactory* iFactory;

signals:

public slots:
};

#endif // COMPONENTFACTORY_H
