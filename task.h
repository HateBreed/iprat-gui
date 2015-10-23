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
    Task(const QString &taskDescription, const Task::taskType &abstractType);

    bool operator==(const Task &task);

    int getMultiplicity() const;
    void setMultiplicity(int &value);

    taskType getType() const;
    bool setType(const Task::taskType &abstractType);
    QString getTypeString() const;

    bool addInformation(Information* information);


signals:

public slots:
};

#endif // TASK_H
