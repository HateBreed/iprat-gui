#ifndef CALCULATIONMODEL_H
#define CALCULATIONMODEL_H

#include <QObject>
#include "calculationstate.h"

#define TYPE_INITIAL 0
#define TYPE_UPDATE 1


class CalculationModel : public QObject
{
    Q_OBJECT
public:
    explicit CalculationModel(QObject *parent = 0);
    void initializeState(CalculationState &state);
    quint8 updateState(CalculationState &state);
    //quint8 (*calculation[VALUES]) (CalculationState &state);

private:
    quint8 init_data_value(CalculationState &state);
    quint8 init_asset_value(CalculationState &state);
    quint8 init_user_damage(CalculationState &state);
    quint8 init_damage_level(CalculationState &state);
    quint8 init_data_capabilitites(CalculationState &state);

    quint8 calc_data_value(CalculationState &state);
    quint8 calc_asset_value(CalculationState &state);
    quint8 calc_damage_level(CalculationState &state);
    quint8 calc_asset_misuse_potential(CalculationState &state);
    quint8 calc_attack_actualization(CalculationState &state);
    quint8 calc_attack_gain(CalculationState &state);
    quint8 calc_data_capabilities(CalculationState &state);
    quint8 calc_privacy_damage(CalculationState &state);
    quint8 calc_user_damage(CalculationState &state);

    quint8 calc_nothing(CalculationState &state);

    quint8 calc_impact(CalculationState &state);
    quint8 calc_likelihood(CalculationState &state);
    quint8 calc_privacy_risk(CalculationState &state);

    void initialize_functions();
    void update_state_history(CalculationState &state);
    int check_state_history_repetition(CalculationState &state);

signals:

public slots:
};

#endif // CALCULATIONMODEL_H
