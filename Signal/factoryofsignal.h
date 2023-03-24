#ifndef FACTORYOFSIGNAL_H
#define FACTORYOFSIGNAL_H
#include "QPair"
#include "signals_defenition.h"
#include <map>
#include <QObject>

class FactoryOfSignal : public QObject
{
    Q_OBJECT
public:
    FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables,
                    NoiseVariables *const noiseVariables, const int &refreshNum,  QObject *parent = nullptr);

private:
    NoSignal m_noSignal;
    Cos m_cos;
    Rectangle m_rectangle;
    ModCos m_modCos;
    ModRect m_modRect;
    CosModCos m_cosModCos;
    CosModRect m_cosModRect;
    RectModCos m_rectModCos;
    RectModRect m_rectModRect;
    Cos_HFM m_cosHFM;
    Cos_HPM m_cosHPM;
    ModRIP m_modRIP;
    CosModRIP m_cosModRIP;
    RectModRIP m_rectModRip;
    CosRIP m_cosRIP;
    CosRIPModCos m_cosRIPModCos;
    CosRIPModCosRIP m_cosRIPModCosRIP;
    CosRIPModHFM m_cosRIPModCosHFM;
    CosRIPModHPM m_cosRIPModCosHPM;
    CosRIPModRect m_cosRIPModRect;
    int i = 0;

    NoiseChannel_1 m_noiseChannel_1;
    NoiseChannel_2 m_noiseChannel_2;
    I_getSignal *m_ptrToSignalRe;
    I_getSignalIm *m_ptrToSignalIm;

    std :: map<QPair<int, int>, QPair<I_getSignal*, I_getSignalIm*>> m_mapSignal;

    double getSignalNoiseReChannel_1();
    double getSignalNoiseImChannel_1();

    double getSignalNoiseReChannel_2();
    double getSignalNoiseImChannel_2();

public:
    double getSignalRe();
    double getSignalIm();
    void resetI();

    double (FactoryOfSignal :: *ptrToSignalReChannel_2)();
    double (FactoryOfSignal :: *ptrToSignalImChannel_2)();

    double (FactoryOfSignal :: *ptrToSignalReChannel_1)();
    double (FactoryOfSignal :: *ptrToSignalImChannel_1)();

public slots:
    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);
};

#endif // FACTORYOFSIGNAL_H
