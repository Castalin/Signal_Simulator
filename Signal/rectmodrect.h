#ifndef RECTMODRECT_H
#define RECTMODRECT_H
#include "a_signalmod.h"
#include "rectangle.h"
#include "modrect.h"

class RectModRect : public A_signalMod
{
public:
    RectModRect();
    virtual double getSignal(const int &i) override;

private:
    Rectangle rect;
    ModRect modRect;
};

#endif // RECTMODRECT_H
