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
    int iMultiplicity;
    QString iDescription;
    qint16 iId;
    explicit Information(QObject *parent = 0);

public:
    enum informationIdentifiability{identifiable,identified,nonidentifiable};
    enum informationType{identification, raw, processed, control, configuration, syslog, preferences};

    informationIdentifiability iIdentifiability;
    informationType iType;

    Information(const QString &name,
                informationType type,
                informationIdentifiability identifiability,
                const int multiplicity);



    QString getDescription() const;
    void setDescription(const QString &value);

    qint16 getId() const;

signals:

public slots:
};

#endif // INFORMATION_H
