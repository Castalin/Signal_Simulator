#ifndef I_GETAMPLMODRANGE_H
#define I_GETAMPLMODRANGE_H


class I_getAmplModRange
{
public:
    I_getAmplModRange();
    virtual int getAmplModMax() const = 0;
    virtual int getAmplModMin() const = 0;
};

#endif // I_GETAMPLMODRANGE_H
