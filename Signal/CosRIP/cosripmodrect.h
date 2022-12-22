#ifndef COSRIPMODRECT_H
#define COSRIPMODRECT_H
#include "Signal/NoSignal/modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "cosrip.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class CosRIPModRect : public I_getSignal, public I_getSignalIm
{
public:
    CosRIPModRect(CosRIP *const cosRIP, ModRect *const modRect);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    CosRIP * const m_cosRIP;
    ModRect *const m_modRect;
};

#endif // COSRIPMODRECT_H
