#ifndef SETRANGEAMPLRECT_H
#define SETRANGEAMPLRECT_H
#include "AbstractANDInterfaces/i_getamplmodrange.h"

class SetRangeAmplRect : public I_getAmplModRange
{
public:
    SetRangeAmplRect();

    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLRECT_H
