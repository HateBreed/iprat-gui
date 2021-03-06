#include "calculationmodel.h"
#include <QtMath>
#include <QDebug>

quint8 divide(quint8 divident, quint8 divisor)
{

    quint8 res = divident / divisor;
    quint8 rem = (((double)divident / divisor - res) >= 0.5) ? 1 : 0;

    return res + rem;
}

CalculationModel::CalculationModel(QObject *parent) : QObject(parent)
{

}

quint8 CalculationModel::init_data_value(CalculationState &state) { return calc_data_value(state); }

quint8 CalculationModel::init_asset_value(CalculationState &state) { return calc_asset_value(state); }

quint8 CalculationModel::init_user_damage(CalculationState &state)
{
    quint8 value = divide(state.getValue(DATA_CAPABILITIES) + state.getValue(DATA_VALUE),2);
    return state.setValue(USER_DAMAGE,value) ? 1 : 0 ;
}

quint8 CalculationModel::init_damage_level(CalculationState &state)
{
    quint8 value = divide(state.getValue(PRIVACY_DAMAGE) + state.getValue(USER_DAMAGE),2);
    return state.setValue(DAMAGE_LEVEL,value) ? 1 : 0;
}

quint8 CalculationModel::init_data_capabilitites(CalculationState &state)
{
    quint8 identif = state.getValue(DATA_IDENTIFIABILITY);
    quint8 value = state.getValue(DATA_CAPABILITIES);

    quint8 matrix[3][6] = {{1,1,2,3,4,4},
                {1,3,4,4,5,6},
                {3,4,5,6,6,6}};
    //printf("identifiability [%d][%d] = %d\n",identif,value,matrix[identif-1][value-1]);
    value = matrix[identif-1][value-1];

    return state.setValue(DATA_CAPABILITIES,value) ? 1 : 0;
}

quint8 CalculationModel::calc_data_value(CalculationState &state)
{
    quint8 value =  divide((state.getValue(DATA_SIGNIFICANCE) + state.getValue(DATA_ACCESS) + state.getValue(DATA_CAPABILITIES)),3);
    return state.setValue(DATA_VALUE,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_asset_value(CalculationState &state)
{
    quint8 value = divide((state.getValue(ASSET_ROLE) +
                    state.getValue(ASSET_ACCESS) +
                    state.getValue(DATA_CAPABILITIES) +
                    state.getValue(DATA_STORAGE_TIME) +
                    state.getValue(DATA_QUANTITY)), 5);
    return state.setValue(ASSET_VALUE,value) ? 1 : 0;
}

quint8 CalculationModel::calc_damage_level(CalculationState &state)
{
    quint8 value = divide((state.getValue(PRIVACY_DAMAGE) + state.getValue(USER_DAMAGE)),2);
    quint8 attack = state.getValue(ATTACK_ACTUALIZATION);

    quint8 matrix[6][6] = {{1,1,2,2,3,3},
                {1,2,3,3,4,4},
                {1,2,3,4,4,5},
                {1,2,3,4,5,5},
                {1,2,3,4,5,6},
                {2,3,4,5,6,6}};

    value = matrix[attack-1][value-1];
    return state.setValue(DAMAGE_LEVEL,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_asset_misuse_potential(CalculationState &state)
{
    quint8 value = state.getValue(ASSET_MISUSE_POTENTIAL);
    quint8 damage = state.getValue(DAMAGE_LEVEL);
    quint8 dataval = state.getValue(DATA_VALUE);

    quint8 matrix[6][6] = {{1,1,1,1,1,2},
                {1,2,2,3,4,4},
                {1,2,3,4,4,5},
                {1,3,3,4,5,6},
                {1,3,4,5,5,6},
                {2,4,5,5,6,6}};

    value = matrix[dataval-1][damage-1];
    return state.setValue(ASSET_MISUSE_POTENTIAL,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_attack_actualization(CalculationState &state)
{
    quint8 value = state.getValue(ATTACK_ACTUALIZATION);
    quint8 aaccess = state.getValue(ASSET_ACCESS);

    quint8 matrix[6][6] = {{1,1,1,2,2,3},
                {1,2,3,3,3,4},
                {2,2,3,4,5,5},
                {2,3,3,4,5,5},
                {4,4,4,5,5,6},
                {5,5,5,5,6,6}};

    value = matrix[aaccess-1][value-1];

    return state.setValue(ATTACK_ACTUALIZATION,value) ? 1 : 0 ;

}

quint8 CalculationModel::calc_attack_gain(CalculationState &state)
{
    quint8 value = state.getValue(ATTACK_GAIN);
    quint8 datav = state.getValue(DATA_VALUE);
    quint8 dataq = state.getValue(DATA_QUANTITY);

    quint8 matrix[6][6] = {{1,1,1,1,1,2},
                {1,2,2,2,3,4},
                {1,2,3,3,4,5},
                {1,3,4,4,5,6},
                {1,4,5,5,5,6},
                {1,5,6,6,6,6}};

    value = matrix[datav-1][dataq-1];

    return state.setValue(ATTACK_GAIN,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_data_capabilities(CalculationState &state)
{
    quint8 value = state.getValue(DATA_CAPABILITIES);
    quint8 pdamage = state.getValue(PRIVACY_DAMAGE);

    quint8 matrix[6][6] = {{1,2,3,3,3,3},
                {1,2,3,3,3,4},
                {1,2,3,4,5,6},
                {1,3,4,4,5,6},
                {1,3,5,5,5,6},
                {1,4,5,5,6,6}};

    value = matrix[pdamage-1][value-1];

    return state.setValue(DATA_CAPABILITIES,value) ? 1 : 0 ;

}

quint8 CalculationModel::calc_privacy_damage(CalculationState &state)
{
    quint8 value = state.getValue(PRIVACY_DAMAGE);
    quint8 signific = state.getValue(DATA_SIGNIFICANCE);

    quint8 matrix[6][6] = {{1,1,2,3,4,5},
                {1,2,3,4,5,5},
                {1,2,3,4,5,5},
                {1,2,3,4,5,6},
                {1,2,4,5,5,6},
                {1,2,4,5,6,6}};

    value = matrix[signific-1][value-1];

    return state.setValue(PRIVACY_DAMAGE,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_user_damage(CalculationState &state)
{
    quint8 value = divide(state.getValue(DATA_CAPABILITIES) + state.getValue(DATA_VALUE),2);
    quint8 role = state.getValue(ASSET_ROLE);

    quint8 matrix[6][6] = {{1,2,3,4,5,6},
                {1,2,3,4,5,6},
                {1,2,3,4,5,6},
                {2,3,4,4,5,6},
                {3,4,5,5,5,6},
                {4,5,6,6,6,6}};

    value = matrix[role-1][value-1];

    return state.setValue(USER_DAMAGE,value) ? 1 : 0 ;
}

quint8 CalculationModel::calc_nothing(CalculationState &state)
{
    return state.getValue(0) > 1 ? 1 : 0;
}

quint8 CalculationModel::calc_impact(CalculationState &state)
{
    quint8 value = divide(state.getValue(ASSET_VALUE)+state.getValue(DAMAGE_LEVEL),2);
    return state.setValue(IMPACT,value) ? 1 : 0;
}

quint8 CalculationModel::calc_likelihood(CalculationState &state)
{
    quint8 value = divide(state.getValue(ATTACK_ACTUALIZATION) +
                          state.getValue(ASSET_MISUSE_POTENTIAL) +
                          state.getValue(ATTACK_GAIN),3);
    return state.setValue(LIKELIHOOD,value) ? 1 : 0;
}



quint8 CalculationModel::calc_privacy_risk(CalculationState &state) {
    quint8 value = divide(state.getValue(IMPACT)+state.getValue(LIKELIHOOD),2);
    return state.setValue(PRIVACY_RISK,value) ? 1 : 0;

}


void CalculationModel::initializeState(CalculationState &state)
{
    init_data_capabilitites(state);
    state.initialize();
}

void CalculationModel::calculateState(CalculationState &state)
{
    qDebug() << "Calculating state" ;

    quint8 rval = 0;
    do {
        rval = updateState(state);
    } while(state.getChangeCount() > 0 && rval > 0);
}

quint8 CalculationModel::updateState(CalculationState &state) {

    quint8 rval = 0;

    for(int i = 0; i < VALUES; i++) {

        switch(i)
        {
        case ATTACK_ACTUALIZATION:
            rval = calc_attack_actualization(state);
            break;
        case PRIVACY_DAMAGE:
            rval = calc_privacy_damage(state);
            break;
        case DATA_CAPABILITIES:
            rval = calc_data_capabilities(state);
            break;
        case ASSET_ACCESS:
            rval = calc_nothing(state);
            break;
        case ASSET_ROLE:
            rval = calc_nothing(state);
            break;
        case DATA_ACCESS:
            rval = calc_nothing(state);
            break;
        case DATA_QUANTITY:
            rval = calc_nothing(state);
            break;
        case DATA_SIGNIFICANCE:
            rval = calc_nothing(state);
            break;
        case DATA_STORAGE_TIME:
            rval = calc_nothing(state);
            break;
        case DATA_IDENTIFIABILITY:
            rval = calc_nothing(state);
            break;
        case DATA_VALUE:
            rval = calc_data_value(state);
            break;
        case USER_DAMAGE:
            rval = calc_user_damage(state);
            break;
        case DAMAGE_LEVEL:
            rval = calc_damage_level(state);
            break;
        case ASSET_MISUSE_POTENTIAL:
            rval = calc_asset_misuse_potential(state);
            break;
        case ATTACK_GAIN:
            rval = calc_attack_gain(state);
            break;
        case ASSET_VALUE:
            rval = calc_asset_value(state);
            break;
        case IMPACT:
            rval = calc_impact(state);
            break;
        case LIKELIHOOD:
            rval = calc_likelihood(state);
            break;
        case PRIVACY_RISK:
            rval = calc_privacy_risk(state);
            break;
        default:
            //should not ever reach this
            qDebug() << "CalculationModel::update_state : switch with value over the limit: " << i ;
            break;
        }

    }
    qDebug() << "Updates on round" << state.getRound() << ":" << state.getChangeCount();
    state.nextRound();
    return rval;
}
