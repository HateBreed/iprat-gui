#ifndef INFORMATION_H
#define INFORMATION_H

#include <QObject>
#include <QString>

class Information : public QObject
{
    Q_OBJECT
    Q_ENUMS(informationType)
    Q_ENUMS(informationIdentifiability)
private:
    int multiplicity;
    QString description;

public:
    enum informationIdentifiability{identifiable,identified,nonidentifiable};
    enum informationType{identification, raw, processed, control, configuration, syslog, preferences};
    Information();
    Information(const QString &name,
                informationType type,
                informationIdentifiability identifiability,
                const int multiplicity);



signals:

public slots:
};

#endif // INFORMATION_H
