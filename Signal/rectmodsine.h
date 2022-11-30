#ifndef RECTMODSINE_H
#define RECTMODSINE_H
#include "rectangle.h"
#include "modsine.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class RectModSine : public I_getSignal, public I_getSignalIm
{
public:
    RectModSine(Rectangle *const rect, ModSine *const modSine);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private :
    Rectangle *m_rect;
    ModSine *m_modSine;
};

#endif // RECTMODSINE_H
