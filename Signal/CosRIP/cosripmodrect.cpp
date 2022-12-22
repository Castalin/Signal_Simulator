#include "cosripmodrect.h"

CosRIPModRect::CosRIPModRect(CosRIP * const cosRIP, ModRect *const modRect)
    :m_cosRIP{cosRIP}, m_modRect{modRect}
{

}

double CosRIPModRect::getSignal(const int &i)
{
    return m_modRect->getSignal(i) * m_cosRIP->getSignal(i);
}

double CosRIPModRect::getSignalIm(const int &i)
{
    return m_modRect->getSignal(i) * m_cosRIP->getSignalIm(i);
}
