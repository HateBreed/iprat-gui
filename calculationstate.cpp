#include <assert.h>
#include <QDebug>
#include "calculationstate.h"

CalculationState::CalculationState(QObject *parent) : QObject(parent)
{

}

CalculationState::CalculationState(QVector<quint8> &initialValues)
{
    assert(initialValues.count() == ASSESSABLE);

    state = QVector<quint8>(VALUES,0);

    history = QVector<QVector<quint8> >();

    lastChangePositionInHistory = QVector<quint8>(HISTORY);

    roundNumber = 0;
    changeCount = 0;
    lastChangePosition = -1;
    historyPosition = 0;
    isInitialized = false;

    for(int i = 0; i < ASSESSABLE; i++) {
        bool rval = setValue(i,initialValues.at(i));
        assert(rval);
    }

    printCurrentState();
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
        qDebug() << "R:" << QString::number(getRound()) << "change of value @" << QString::number(position) << "from" << QString::number(state[position]) << "to" << QString::number(value);
        state[position] = value;
        if(roundNumber > 0) { // Not the initial round
            increaseChangeCount();
            setLastChangePosition(position);
        }
        qDebug() << "changes total:" << QString::number(getChangeCount());
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
    updateHistory();
    changeCount = 0;
    lastChangePosition = -1;
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

void CalculationState::printCurrentState() const
{
    QString printstring = "Values: ";
    foreach(quint8 value, state)
    {
        printstring.append(QString::number(value) + ",");
    }
    qDebug() << "R: " << getRound() << printstring;
}

void CalculationState::printHistory() const
{

    foreach(QVector<quint8> vector, history)
    {
        QString printstring = "";
        foreach(quint8 value, vector)
        {
            printstring.append(QString::number(value));
            printstring.append(",");
        }
        if(vector.size() > 0) qDebug() << "History size=" << history.count() << "Values:" << printstring;
    }

}

bool CalculationState::isStateInitialized() const
{
    return isInitialized;
}

void CalculationState::setStateInitialized()
{
    isInitialized = true;
}

void CalculationState::updateHistory()
{
    if(history.count() == HISTORY) history.pop_front();
    history.push_back(QVector<quint8>(this->state));
    qDebug() << "Updated history, size: " << history.count();
    printHistory();
}

void CalculationState::increaseChangeCount()
{
    ++changeCount;
}

void CalculationState::initialize()
{
    if(!isStateInitialized())
    {
        setStateInitialized();
        nextRound();
    }
    else
    {
        qDebug("CalculationState::initialize() alredy initialized");
    }
}

