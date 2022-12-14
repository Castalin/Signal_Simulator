#ifndef SETRANGEAMPLRIP_H
#define SETRANGEAMPLRIP_H
#include "AbstractANDInterfaces/i_getamplmodrange.h"

class SetRangeAmplRIP : public I_getAmplModRange
{
public:
    SetRangeAmplRIP();
    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLRIP_H
