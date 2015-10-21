#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "connection.h"

class Function : public QObject
{

private:
    QString description;
    QList<qint16> informations;
    Function();
public:
    enum functionType {
        MEASUREMENT,
        GENERATION,
        MANAGEMENT,
        PROCESSING,
        MONITORING,
        STATISTICS_CREATION,
        VALUE_ADDED_SERVICES,
        ADMINISTRATION,
    };
    functionType type;

    Function(const QString &functionDescription, const functionType &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getType() const;
    void setType(const functionType &value);

    QString getTypeString() const;

signals:

public slots:


};

#endif // FUNCTION_H
