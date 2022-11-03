#ifndef A_SIGNAL_H
#define A_SIGNAL_H
#include "Structes/SignalVariables.h"

class A_signal
{
public:
    A_signal(SignalVariables * const signalVariables);
    virtual ~A_signal();

protected:
     SignalVariables *const m_signalVariables;
};

#endif // A_SIGNAL_H
