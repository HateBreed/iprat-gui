#ifndef UTILITIES_H
#define UTILITIES_H

#include <QObject>
#include "task.h"
#include "function.h"
#include "connection.h"

class Utilities : public QObject
{
    Q_OBJECT
private:
    static Utilities* utility;
public:
    explicit Utilities(QObject *parent = 0);
    static bool isValidTaskType(const Task::taskType type);
    static QString transferTaskTypetoString(Task::taskType type);
    static bool isValidFunctionType(const Function::functionType type);
    static QString transferFunctionTypeToString(const Function::functionType type);
    static bool isValidConnectionType(const Connection::connectionType type);
    static QString transferConnectionTypeToString(Connection::connectionType type);


signals:

public slots:
};

#endif // UTILITIES_H
