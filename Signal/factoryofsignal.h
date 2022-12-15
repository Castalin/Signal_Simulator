#ifndef FACTORYOFSIGNAL_H
#define FACTORYOFSIGNAL_H
#include "QPair"
#include "signals_defenition.h"
#include <map>

class FactoryOfSignal
{
public:
    FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables);

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
    RectModRIP m_RectModRip;
    int i = 0;

    Noise m_noise;

    I_getSignal *m_ptrToSignalRe;
    I_getSignalIm *m_ptrToSignalIm;

    std :: map<QPair<int, int>, QPair<I_getSignal*, I_getSignalIm*>> m_mapSignal;

    (double)(*)ptrToFunc;


public:
    void setSignalType(const QPair<int, int> &signalType);
    double getSignalRe();
    double getSignalIm();
    void resetI();



};

#endif // FACTORYOFSIGNAL_H
