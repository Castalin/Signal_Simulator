#include "cosmodrect.h"
#include <QtMath>

CosModRect::CosModRect(Cos * const cos, ModRect * const modRect)
    :m_cos{cos}, m_modRect{modRect}
{

}

double CosModRect::getSignal(const int &i)
{
    return m_modRect->getSignal(i) * m_cos->getSignal(i);
}

double CosModRect::getSignalIm(const int &i)
{
    return m_modRect->getSignal(i) * m_cos->getSignalIm(i);
}
