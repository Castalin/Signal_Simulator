#ifndef SINEMODRECT_H
#define SINEMODRECT_H
#include "modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "sine.h"


class SineModRect :  public I_getSignal
{
public:
    SineModRect(Sine *const sine, ModRect *const modRect);
    virtual double getSignal(const int &i) override;

private:
    Sine *m_sine;
    ModRect *m_modRect;

};

#endif // SINEMODRECT_H
