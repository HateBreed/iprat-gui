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
    static void initializeState(CalculationState &state);
    static void calculateState(CalculationState &state);


private:
    static quint8 init_data_value(CalculationState &state);
    static quint8 init_asset_value(CalculationState &state);
    static quint8 init_user_damage(CalculationState &state);
    static quint8 init_damage_level(CalculationState &state);
    static quint8 init_data_capabilitites(CalculationState &state);

    static quint8 calc_data_value(CalculationState &state);
    static quint8 calc_asset_value(CalculationState &state);
    static quint8 calc_damage_level(CalculationState &state);
    static quint8 calc_asset_misuse_potential(CalculationState &state);
    static quint8 calc_attack_actualization(CalculationState &state);
    static quint8 calc_attack_gain(CalculationState &state);
    static quint8 calc_data_capabilities(CalculationState &state);
    static quint8 calc_privacy_damage(CalculationState &state);
    static quint8 calc_user_damage(CalculationState &state);

    static quint8 calc_nothing(CalculationState &state);

    static quint8 calc_impact(CalculationState &state);
    static quint8 calc_likelihood(CalculationState &state);
    static quint8 calc_privacy_risk(CalculationState &state);

    static quint8 updateState(CalculationState &state);

signals:

public slots:
};

#endif // CALCULATIONMODEL_H
