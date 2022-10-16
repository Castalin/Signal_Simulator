#ifndef SINEMODSINE_H
#define SINEMODSINE_H
#include "a_signalmod.h"

class SineModSine : public A_signalMod
{
public:
    SineModSine();
    virtual double getSignal(int &i) override;
};

#endif // SINEMODSINE_H
