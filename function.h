#ifndef FUNCTION_H
#define FUNCTION_H

#include <QObject>
#include "connection.h"
#include "information.h"

class Function : public QObject
{
    Q_OBJECT
private:
    QString iDescription;
    QList<qint16> iInformationIdList;
    explicit Function(QObject *parent = 0);
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
    functionType iType;


    Function(const QString &functionDescription, const functionType &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getType() const;
    void setType(const functionType &value);

    QString getTypeString() const;

    bool addInformation(Information* information);
    const QList<qint16>* getInformationList();
    bool hasInformation(Information* information);

signals:

public slots:


};

#endif // FUNCTION_H
