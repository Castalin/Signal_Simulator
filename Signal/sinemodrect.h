#ifndef SINEMODRECT_H
#define SINEMODRECT_H
#include "modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "sine.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class SineModRect :  public I_getSignal, public I_getSignalIm
{
public:
    SineModRect(Sine *const sine, ModRect *const modRect);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    Sine * const m_sine;
    ModRect *const m_modRect;

};

#endif // SINEMODRECT_H
