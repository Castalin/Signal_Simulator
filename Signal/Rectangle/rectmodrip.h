#ifndef RECTMODRIP_H
#define RECTMODRIP_H

#include "Signal/NoSignal/modrip.h"
#include "rectangle.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class RectModRIP : public I_getSignal, public I_getSignalIm
{
public:
    RectModRIP(Rectangle *const rect, ModRIP *const modRIP);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private :
    Rectangle *const m_rect;
    ModRIP *const m_modRIP;
};

#endif // RECTMODRIP_H
