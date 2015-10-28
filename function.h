#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "componentbase.h"
#include "connection.h"
#include "information.h"

class Function : public ComponentBase
{
    Q_OBJECT
    Q_ENUMS(functionType)
private:
    QList<quint16> iInformationIdList;
    explicit Function(ComponentBase *parent = 0);
public:
    // Types start from 1 in the generic functional model
    enum functionType {
        MEASUREMENT=1,
        GENERATION,
        MANAGEMENT,
        PROCESSING,
        MONITORING,
        STATISTICS_CREATION,
        VALUE_ADDED_SERVICES,
        ADMINISTRATION,
    };

    Function(const functionType &value, const QString &functionDescription);

    bool operator==(const Function &function);

    Q_INVOKABLE Function::functionType getType() const;

    Q_INVOKABLE bool setType(const functionType &value);

    Q_INVOKABLE QString getTypeString() const;

    Q_INVOKABLE bool addInformation(Information* information);
    Q_INVOKABLE const QList<quint16>* getInformationList();
    Q_INVOKABLE bool hasInformation(Information* information);

signals:

public slots:


};

#endif // FUNCTION_H
