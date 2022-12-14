#ifndef COSMODRECT_H
#define COSMODRECT_H
#include "Signal/NoSignal/modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "cos.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class CosModRect :  public I_getSignal, public I_getSignalIm
{
public:
    CosModRect(Cos *const cos, ModRect *const modRect);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    Cos * const m_cos;
    ModRect *const m_modRect;

};

#endif // COSMODRECT_H
