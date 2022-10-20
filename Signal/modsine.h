#ifndef MODSINE_H
#define MODSINE_H
#include "a_signalmod.h"

class ModSine : public A_signalMod
{
public:
    ModSine();
    virtual double getSignal(int &i) override;
};

#endif // MODSINE_H
