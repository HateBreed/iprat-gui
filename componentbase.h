#ifndef COMPONENTBASE_H
#define COMPONENTBASE_H

#include <QObject>
#include <QString>

class ComponentBase : public QObject
{
    Q_OBJECT
protected:
    quint16 iId;
    QString iDescription;
public:
    explicit ComponentBase(QObject *parent = 0);
    quint16 getId() const;

    QString getDescription() const;
    void setDescription(const QString &value);

signals:

public slots:
};

#endif // COMPONENTBASE_H
