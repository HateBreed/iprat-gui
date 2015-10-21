#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QList>
#include "information.h"

class Task : public QObject
{
    Q_OBJECT
    Q_ENUMS(type)
private:
    int multiplicity;
    QList<Information> datalist;
    QString description;
public:
    enum type{controlling,source,reading,processing,storing,lowaccess,highaccess};
    Task();

    QString getDescription() const;
    void setDescription(const QString &value);

    int getMultiplicity() const;
    void setMultiplicity(int value);

    type getType() const;
    void setType(enum type);

    QList<Information> addInformation(Information &_info);


signals:

public slots:
};

#endif // TASK_H
