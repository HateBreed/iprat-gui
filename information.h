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
    /**
     * @brief The informationIdentifiability enum PII 2.0 definitions
     */
    enum informationIdentifiability{
        identifiable,
        identified,
        nonidentifiable};

    /**
     * @brief The informationType enum Information types in abstract and functional models
     */
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
                informationType &type,
                informationIdentifiability &identifiability,
                const int &multiplicity);

    bool operator==(const Information &information);

    informationIdentifiability getIdentifiability() const;
    void setIdentifiability(const informationIdentifiability &value);

    informationType getType() const;
    void setType(const informationType &value);

signals:

public slots:
};

#endif // INFORMATION_H
