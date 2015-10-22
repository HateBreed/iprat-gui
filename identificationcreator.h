#ifndef IDENTIFICATIONCREATOR_H
#define IDENTIFICATIONCREATOR_H

#include <QObject>

class identificationCreator : public QObject
{
    Q_OBJECT
private:
        qint16 iActorIdPool;
        qint16 iConnectionIdPool;
        qint16 iInformationIdPool;
        static identificationCreator* creator;

        explicit identificationCreator(QObject *parent = 0);
public:
        static identificationCreator* getInstance();
        qint16 getNextActorId();
        qint16 getNextConnectionId();
        qint16 getNextInformationId();


signals:

public slots:

};

#endif // IDENTIFICATIONCREATOR_H
