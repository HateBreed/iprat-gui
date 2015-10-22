#ifndef INFORMATION_H
#define INFORMATION_H

#include <QObject>
#include <QString>
#include "componentbase.h"

class Information : public ComponentBase
{
    Q_ENUMS(informationType)
    Q_ENUMS(informationIdentifiability)
private:
    int iMultiplicity;
    explicit Information(ComponentBase *parent = 0);

public:
    enum informationIdentifiability{
        identifiable,
        identified,
        nonidentifiable};

    enum informationType{
        identification,
        raw,
        processed,
        control,
        configuration,
        syslog,
        preferences};

    informationIdentifiability iIdentifiability;
    informationType iType;

    Information(const QString &name,
                informationType type,
                informationIdentifiability identifiability,
                const int multiplicity);

signals:

public slots:
};

#endif // INFORMATION_H
