#include "factoryofsignal.h"

FactoryOfSignal::FactoryOfSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables)
    : m_noSignal{signalVariables}, m_sine{signalVariables}, m_rectangle{signalVariables}, m_modSine{modSignalVariables},
      m_modRect{modSignalVariables}, m_sineModSine{signalVariables, &m_modSine}, m_sineModRect{&m_sine, &m_modRect},
      m_rectModSine{&m_rectangle, &m_modSine}, m_rectModRect{&m_rectangle, &m_modRect}
{

    m_mapSignal[QPair<int, int>(0, 0)] = &m_noSignal;
    m_mapSignal[QPair<int, int>(1, 0)] = &m_sine;
    m_mapSignal[QPair<int, int>(2, 0)] = &m_rectangle;
    m_mapSignal[QPair<int, int>(0, 1)] = &m_modSine;
    m_mapSignal[QPair<int, int>(0, 2)] = &m_modRect;
    m_mapSignal[QPair<int, int>(1, 1)] = &m_sineModSine;
    m_mapSignal[QPair<int, int>(1, 2)] = &m_sineModRect;
    m_mapSignal[QPair<int, int>(2, 1)] = &m_rectModSine;
    m_mapSignal[QPair<int, int>(2, 2)] = &m_rectModRect;

    m_ptrToSignal = &m_noSignal;
    i = 0;
}

void FactoryOfSignal::setSignalType(const QPair<int, int> &signalType)
{
    m_ptrToSignal = m_mapSignal.at(signalType);
}

double FactoryOfSignal::getSignal()
{
    if (i == 2048)
    {
        i = 0;
    }
    return m_ptrToSignal->getSignal(i++);

}

