#include <assert.h>
#include "calculationstate.h"

CalculationState::CalculationState(QObject *parent) : QObject(parent)
{

}

CalculationState::CalculationState(QVector<quint8> &initialValues)
{
    initialize();

    assert(initialValues.count() == ASSESSABLE);

    for(int i = 0; i < ASSESSABLE; i++) {
        quint8 rval = setValue(i,initialValues.at(i));
        assert(rval == 1);
    }
}

quint8 CalculationState::getValue(const quint8 &position) const
{
    assert(position < VALUES);
    switch(position)
    {
    case ATTACK_ACTUALIZATION:
    case PRIVACY_DAMAGE:
    case DATA_CAPABILITIES:
    case ASSET_ACCESS:
    case ASSET_ROLE:
    case DATA_ACCESS:
    case DATA_QUANTITY:
    case DATA_SIGNIFICANCE:
    case DATA_STORAGE_TIME:
    case DATA_IDENTIFIABILITY:
    case DATA_VALUE:
    case USER_DAMAGE:
    case DAMAGE_LEVEL:
    case ASSET_MISUSE_POTENTIAL:
    case ATTACK_GAIN:
    case ASSET_VALUE:
    case IMPACT:
    case LIKELIHOOD:
    case PRIVACY_RISK:
        return state.at(position);
    default:
        //@TODO set appropriate error
        return 0;
    }
}

bool CalculationState::setValue(const quint8 &position, const quint8 &value)
{
    switch(position)
    {
    // 1 to 3
    case DATA_IDENTIFIABILITY:
        if(value > 3 || value < 1) return false;
        //@TODO set appropriate error
        break;
    // 1 to 6
    case ATTACK_ACTUALIZATION:
    case PRIVACY_DAMAGE:
    case DATA_CAPABILITIES:
    case ASSET_ACCESS:
    case ASSET_ROLE:
    case DATA_ACCESS:
    case DATA_QUANTITY:
    case DATA_SIGNIFICANCE:
    case DATA_STORAGE_TIME:
    case DATA_VALUE:
    case USER_DAMAGE:
    case DAMAGE_LEVEL:
    case ASSET_MISUSE_POTENTIAL:
    case ATTACK_GAIN:
    case ASSET_VALUE:
    case IMPACT:
    case LIKELIHOOD:
    case PRIVACY_RISK:
        if(value > 6 || value < 1) return false;
        //@TODO set appropriate error
        break;
    default:
        //@TODO set appropriate error
        return false;
    }

    // Value has changed?
    if(state.at(position) != value)
    {
        state[position] = value;
        if(roundNumber > 0) { // Not the initial round
            increaseChangeCount();
            setLastChangePosition(position);
        }
    }


    return true;
}

quint8 CalculationState::getLastChangePosition() const
{
    return lastChangePosition;
}

void CalculationState::setLastChangePosition(const quint8 &value)
{
    lastChangePosition = value;
}

void CalculationState::nextRound()
{
    //@TODO update history
    ++roundNumber;
}

quint32 CalculationState::getRound() const
{
    return roundNumber;
}

quint8 CalculationState::getChangeCount() const
{
    return changeCount;
}

void CalculationState::increaseChangeCount()
{
    ++changeCount;
}

void CalculationState::initialize()
{
    state = QVector<quint8>(VALUES,0);
    lastChangePosition = 0;

    history = QVector<QVector<quint8> >(HISTORY);
    foreach (QVector<quint8> array, history)
    {
        array.resize(VALUES);
        foreach (quint8 value, array) value = 0;
    }

    lastChangePositionInHistory = QVector<quint8>(HISTORY);

    roundNumber = 0;
    changeCount = 0;
    historyPosition = 0;

}

