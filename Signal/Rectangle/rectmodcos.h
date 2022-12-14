#ifndef RECTMODCOS_H
#define RECTMODCOS_H
#include "Signal/NoSignal/modcos.h"
#include "rectangle.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class RectModCos : public I_getSignal, public I_getSignalIm
{
public:
    RectModCos(Rectangle *const rect, ModCos *const modCos);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private :
    Rectangle *const m_rect;
    ModCos *const m_modCos;
};

#endif // RECTMODCOS_H
