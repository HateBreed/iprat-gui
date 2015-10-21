#include <QDebug>
#include <stdio.h>
#include "identificationcreator.h"

identificationCreator* identificationCreator::_self = NULL;

identificationCreator::identificationCreator(QObject *parent) :
    QObject(parent)
{
    actorIdPool = 0;
    _self = NULL;
}

identificationCreator* identificationCreator::getInstance()
{
    if (!_self) {
        _self = new identificationCreator;
        printf("Created new identifiaction creator.\n");
    }
    return _self;
}

qint16 identificationCreator::getNextActorId()
{
    return ++actorIdPool;
}
