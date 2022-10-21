#ifndef SINEMODRECT_H
#define SINEMODRECT_H
#include "a_signalmod.h"
#include "modrect.h"


class SineModRect : public A_signalMod
{
public:
    SineModRect();
    virtual double getSignal(const int &i) override;

private:
    ModRect modRect;

};

#endif // SINEMODRECT_H
