#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QList>
#include "information.h"

class Task : public QObject
{
    Q_OBJECT
    Q_ENUMS(iType)
private:
    int iMultiplicity;
    QList<Information> iInformationList;
    QString iDescription;
    explicit Task(QObject *parent = 0);

public:
    enum taskType{controlling,source,reading,processing,storing,lowaccess,highaccess};
    taskType iType;
    Task(const enum taskType &abstractType);

    QString getDescription() const;
    void setDescription(const QString &value);

    int getMultiplicity() const;
    void setMultiplicity(int value);

    taskType getType() const;
    void setType(enum taskType);

    QList<Information> addInformation(Information &information);


signals:

public slots:
};

#endif // TASK_H
