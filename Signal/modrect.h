#ifndef MODRECT_H
#define MODRECT_H
#include "a_signalmod.h"

class ModRect : public A_signalMod
{
public:
    ModRect();
    virtual double getSignal(int &i) override;
};

#endif // MODRECT_H
