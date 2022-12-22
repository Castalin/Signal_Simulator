#ifndef RECTMODRECT_H
#define RECTMODRECT_H
#include "Signal/NoSignal/modrect.h"
#include "rectangle.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class RectModRect : public I_getSignal, public I_getSignalIm
{
public:
    RectModRect(Rectangle *const rectangle, ModRect *const modRect);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    Rectangle *const m_rect;
    ModRect  *const m_modRect;
};

#endif // RECTMODRECT_H
