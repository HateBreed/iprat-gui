#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "componentbase.h"
#include "connection.h"
#include "information.h"

class Function : public ComponentBase
{
    Q_OBJECT
private:
    QList<qint16> iInformationIdList;
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

    Function(const QString &functionDescription, const functionType &value);

    Function::functionType getType() const;
    void setType(const functionType &value);

    QString getTypeString() const;

    bool addInformation(Information* information);
    const QList<qint16>* getInformationList();
    bool hasInformation(Information* information);

signals:

public slots:


};

#endif // FUNCTION_H
