#ifndef RECTMODSINE_H
#define RECTMODSINE_H
#include "a_signalmod.h"
#include "rectangle.h"
#include "modsine.h"

class RectModSine : public A_signalMod
{
public:
    RectModSine();
    virtual double getSignal(const int &i) override;

private :
    Rectangle rect;
    ModSine modSine;
};

#endif // RECTMODSINE_H
