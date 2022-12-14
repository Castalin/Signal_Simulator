#include "rectmodrip.h"

RectModRIP::RectModRIP(Rectangle *const rect, ModRIP *const modRIP)
    : m_rect{rect}, m_modRIP{modRIP}
{

}

double RectModRIP::getSignal(const int &i) const
{
    return m_rect->getSignal(i) * m_modRIP->getSignal(i);
}

double RectModRIP::getSignalIm(const int &i) const
{
    return m_rect->getSignal(i) * m_modRIP->getSignalIm(i);
}
