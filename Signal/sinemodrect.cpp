#include "sinemodrect.h"
#include <QtMath>

SineModRect::SineModRect(Sine * const sine, ModRect * const modRect)
    :m_sine{sine}, m_modRect{modRect}
{

}

double SineModRect::getSignal(const int &i) const
{
    return m_modRect->getSignal(i) * m_sine->getSignal(i);
}

double SineModRect::getSignalIm(const int &i) const
{
    return m_modRect->getSignal(i) * m_sine->getSignalIm(i);
}
