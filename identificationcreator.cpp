#include <QDebug>
#include <stdio.h>
#include "identificationcreator.h"

identificationCreator* identificationCreator::creator = NULL;

identificationCreator::identificationCreator(QObject *parent) :
    QObject(parent)
{
    iActorIdPool = 0;
    iConnectionIdPool = 0;
    iInformationIdPool = 0;
    creator = NULL;
}

identificationCreator* identificationCreator::getInstance()
{
    if (!creator) {
        creator = new identificationCreator;
        qDebug() << "Created new identifiaction creator.";
    }
    return creator;
}

qint16 identificationCreator::getNextActorId()
{
    return ++iActorIdPool;
}

qint16 identificationCreator::getNextConnectionId()
{
    return ++iConnectionIdPool;
}

qint16 identificationCreator::getNextInformationId()
{
    return ++iInformationIdPool;
}
