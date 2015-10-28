#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QList>
#include "componentbase.h"
#include "information.h"

class Task : public ComponentBase
{
    Q_ENUMS(taskType)
private:

    int iMultiplicity;
    QList<Information*> iInformationList;
    explicit Task(ComponentBase *parent = 0);

    bool searchFromList(const Information* information);
public:

    enum taskType{
        controlling=1,
        source,
        reading,
        processing,
        storing,
        lowaccess,
        highaccess
    };

    Task(const Task::taskType &abstractType);
    Task(const Task::taskType &abstractType, const QString &taskDescription);

    bool operator==(const Task &task);

    Q_INVOKABLE int getMultiplicity() const;
    Q_INVOKABLE void setMultiplicity(int &value);

    Q_INVOKABLE taskType getType() const;
    Q_INVOKABLE bool setType(const Task::taskType &abstractType);
    Q_INVOKABLE QString getTypeString() const;

    Q_INVOKABLE bool addInformation(Information* information);
    Q_INVOKABLE const QList<Information *> *getInformationList();
    Q_INVOKABLE bool hasInformation(Information* information);


signals:

public slots:
};

#endif // TASK_H
