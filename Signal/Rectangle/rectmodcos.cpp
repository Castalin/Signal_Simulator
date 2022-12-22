#include "rectmodcos.h"

RectModCos::RectModCos(Rectangle * const rect, ModCos * const modCos)
    : m_rect{rect}, m_modCos{modCos}
{

}

double RectModCos::getSignal(const int &i)
{
    return m_rect->getSignal(i) * m_modCos->getSignal(i);
}

double RectModCos::getSignalIm(const int &i)
{
    return m_rect->getSignal(i) * m_modCos->getSignalIm(i);
}
