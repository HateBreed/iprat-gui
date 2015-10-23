#ifndef CALCULATIONSTATE_H
#define CALCULATIONSTATE_H

#include <QObject>
#include <QVector>

// Step 1
#define ATTACK_ACTUALIZATION 0
#define PRIVACY_DAMAGE 1
#define DATA_CAPABILITIES 2
#define ASSET_ACCESS 3
#define ASSET_ROLE 4
#define DATA_ACCESS 5
#define DATA_QUANTITY 6
#define DATA_SIGNIFICANCE 7
#define DATA_STORAGE_TIME 8
#define DATA_IDENTIFIABILITY 9

// Step 2
#define DATA_VALUE 10
#define USER_DAMAGE 11
#define DAMAGE_LEVEL 12
#define ASSET_MISUSE_POTENTIAL 13
#define ATTACK_GAIN 14
#define ASSET_VALUE 15

// Step 3
#define IMPACT 16
#define LIKELIHOOD 17
#define PRIVACY_RISK 18


#define HISTORY 10
#define LIMIT 6+1
#define VALUES 18
#define VALUES_TOTAL VALUES+1
#define ASSESSABLE 10

class CalculationState : public QObject
{
    Q_OBJECT
public:
    explicit CalculationState(QObject *parent = 0);
    CalculationState(QVector<quint8> &initialValues);

    quint8 getValue(const quint8 &position) const;
    bool setValue(const quint8 &position, const quint8 &value);


    quint8 getLastChangePosition() const;

    void nextRound();
    quint32 getRound() const;

    quint8 getChangeCount() const;


private:


    QVector<quint8> state; // all 18
    quint8 lastChangePosition;
    quint32 roundNumber;
    quint8 changeCount;
    QVector<QVector<quint8> > history; //[HISTORY][VALUES];
    quint8 historyPosition;
    QVector<quint8> lastChangePositionInHistory; //[HISTORY];

    void initialize();

    void increaseChangeCount();
    void setLastChangePosition(const quint8 &value);

signals:

public slots:
};

#endif // CALCULATIONSTATE_H
