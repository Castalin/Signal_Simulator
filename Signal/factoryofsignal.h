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
    Sine m_sine;
    Rectangle m_rectangle;
    ModSine m_modSine;
    ModRect m_modRect;
    SineModSine m_sineModSine;
    SineModRect m_sineModRect;
    RectModSine m_rectModSine;
    RectModRect m_rectModRect;
    int i = 0;

    I_getSignal *m_ptrToSignalRe;
    I_getSignalIm *m_ptrToSignalIm;

    std :: map<QPair<int, int>, QPair<I_getSignal*, I_getSignalIm*>> m_mapSignal;

public:
    void setSignalType(const QPair<int, int> &signalType);
    double getSignalRe();
    double getSignalIm();
    void resetI();

};

#endif // FACTORYOFSIGNAL_H
