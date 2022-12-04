#ifndef SETRANGEAMPLHAM_H
#define SETRANGEAMPLHAM_H
#include "AbstractANDInterfaces/i_getamplmodrange.h"

class SetRangeAmplHAM : public I_getAmplModRange
{
public:
    SetRangeAmplHAM();

    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLHAM_H
