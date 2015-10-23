#ifndef IDENTIFICATIONCREATOR_H
#define IDENTIFICATIONCREATOR_H

#include <QObject>

class identificationCreator : public QObject
{
    Q_OBJECT
private:
        quint16 iActorIdPool;
        quint16 iConnectionIdPool;
        quint16 iInformationIdPool;
        static identificationCreator* creator;

        explicit identificationCreator(QObject *parent = 0);
public:
        static identificationCreator* getInstance();
        quint16 getNextActorId();
        quint16 getNextConnectionId();
        quint16 getNextInformationId();


signals:

public slots:

};

#endif // IDENTIFICATIONCREATOR_H
