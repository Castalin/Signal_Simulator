#include "rectmodrect.h"

RectModRect::RectModRect(Rectangle * const rectangle, ModRect * const modRect)
    : m_rect{rectangle}, m_modRect{modRect}
{

}

double RectModRect::getSignal(const int &i)
{
    return m_rect->getSignal(i) * m_modRect->getSignal(i);
}
