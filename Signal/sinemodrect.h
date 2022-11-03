#ifndef SINEMODRECT_H
#define SINEMODRECT_H
#include "AbstractANDInterfaces/a_signal.h"
#include "modrect.h"
#include "AbstractANDInterfaces/i_getsignal.h"


class SineModRect : protected A_signal, public I_getSignal
{
public:
    SineModRect(SignalVariables *const signalVariables, ModRect *const modRect);
    virtual double getSignal(const int &i) override;

private:
    ModRect *m_modRect;

};

#endif // SINEMODRECT_H
