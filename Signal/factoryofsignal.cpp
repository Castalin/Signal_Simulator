#include "factoryofsignal.h"

FactoryOfSignal::FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables)
    : m_noSignal{signalVariables}, m_sine{signalVariables}, m_rectangle{signalVariables}, m_modSine{modSignalVariables},
      m_modRect{modSignalVariables}, m_sineModSine{signalVariables, &m_modSine}, m_sineModRect{&m_sine, &m_modRect},
      m_rectModSine{&m_rectangle, &m_modSine}, m_rectModRect{&m_rectangle, &m_modRect}
{

    m_mapSignal[QPair<int, int>(0, 0)] = QPair<I_getSignal*, I_getSignalIm*>(&m_noSignal, &m_noSignal);
    m_mapSignal[QPair<int, int>(1, 0)] = QPair<I_getSignal*, I_getSignalIm*>(&m_sine, &m_sine);
    m_mapSignal[QPair<int, int>(2, 0)] = QPair<I_getSignal*, I_getSignalIm*>(&m_rectangle, &m_rectangle);
    m_mapSignal[QPair<int, int>(0, 1)] = QPair<I_getSignal*, I_getSignalIm*>(&m_modSine, &m_modSine);
    m_mapSignal[QPair<int, int>(0, 2)] = QPair<I_getSignal*, I_getSignalIm*>(&m_modRect, &m_modRect);
    m_mapSignal[QPair<int, int>(1, 1)] = QPair<I_getSignal*, I_getSignalIm*>(&m_sineModSine, &m_sineModSine);
    m_mapSignal[QPair<int, int>(1, 2)] = QPair<I_getSignal*, I_getSignalIm*>(&m_sineModRect, &m_sineModRect);
    m_mapSignal[QPair<int, int>(2, 1)] = QPair<I_getSignal*, I_getSignalIm*>(&m_rectModSine, &m_rectModSine);
    m_mapSignal[QPair<int, int>(2, 2)] = QPair<I_getSignal*, I_getSignalIm*>(&m_rectModRect, &m_rectModRect);

    m_ptrToSignalRe = &m_noSignal;
    m_ptrToSignalIm = &m_noSignal;
    i = 0;
}

void FactoryOfSignal::setSignalType(const QPair<int, int> &signalType)
{
    QPair<I_getSignal*, I_getSignalIm*> pair = m_mapSignal.at(signalType);
    m_ptrToSignalRe = pair.first;
    m_ptrToSignalIm = pair.second;
}

double FactoryOfSignal::getSignalRe()
{
    return m_ptrToSignalRe->getSignal(i);
}

double FactoryOfSignal::getSignalIm()
{
    return m_ptrToSignalIm->getSignalIm(i++);
}

void FactoryOfSignal::resetI()
{
    i = 0;
}

