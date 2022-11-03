#ifndef A_SIGNALMOD_H
#define A_SIGNALMOD_H
#include "Structes/ModSignalVariables.h"

class A_signalMod
{
public:
    A_signalMod(ModSignalVariables *const modSignalVariables);
    virtual ~A_signalMod();

protected:
    ModSignalVariables *m_modSignalVariables;
};

#endif // A_SIGNALMOD_H
