#ifndef SINEMODSINE_H
#define SINEMODSINE_H
#include "a_signalmod.h"
#include "modsine.h"

class SineModSine : public A_signalMod
{
public:
    SineModSine();
    virtual double getSignal(const int &i) override;
private:
    ModSine modSine;
};

#endif // SINEMODSINE_H
