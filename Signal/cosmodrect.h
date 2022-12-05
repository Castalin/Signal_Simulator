#ifndef COSMODRECT_H
#define COSMODRECT_H
#include "modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "cos.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class CosModRect :  public I_getSignal, public I_getSignalIm
{
public:
    CosModRect(Cos *const cos, ModRect *const modRect);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    Cos * const m_cos;
    ModRect *const m_modRect;

};

#endif // COSMODRECT_H
