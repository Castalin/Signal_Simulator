#ifndef RECTMODRECT_H
#define RECTMODRECT_H
#include "rectangle.h"
#include "modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class RectModRect : public I_getSignal, public I_getSignalIm
{
public:
    RectModRect(Rectangle *const rectangle, ModRect *const modRect);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    Rectangle *m_rect;
    ModRect *m_modRect;
};

#endif // RECTMODRECT_H
