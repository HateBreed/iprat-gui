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
    creator = this;
    qDebug() << "Created new identifiaction creator.";
}

identificationCreator* identificationCreator::getInstance()
{
    if (!creator) new identificationCreator;
    return creator;
}

quint16 identificationCreator::getNextActorId()
{
    return ++iActorIdPool;
}

quint16 identificationCreator::getNextConnectionId()
{
    return ++iConnectionIdPool;
}

quint16 identificationCreator::getNextInformationId()
{
    return ++iInformationIdPool;
}
