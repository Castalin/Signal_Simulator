#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"

class Rectangle : protected A_signal, public I_getSignal
{
public:
    Rectangle(SignalVariables *const signalVariables);
    virtual double getSignal(const int &i) override;
};

#endif // RECTANGLE_H
