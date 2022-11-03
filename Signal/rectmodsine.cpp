#include "rectmodsine.h"

RectModSine::RectModSine(Rectangle * const rect, ModSine * const modSine)
    : m_rect{rect}, m_modSine{modSine}
{

}

double RectModSine::getSignal(const int &i)
{
    return m_rect->getSignal(i) * m_modSine->getSignal(i);
}
