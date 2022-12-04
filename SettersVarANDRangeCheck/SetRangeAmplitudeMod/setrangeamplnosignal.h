#ifndef SETRANGEAMPLNOSIGNAL_H
#define SETRANGEAMPLNOSIGNAL_H
#include "AbstractANDInterfaces/i_getamplmodrange.h"

class SetRangeAmplNoSignal : public I_getAmplModRange
{
public:
    SetRangeAmplNoSignal();

    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLNOSIGNAL_H
