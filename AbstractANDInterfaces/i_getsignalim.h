#ifndef I_GETSIGNALIM_H
#define I_GETSIGNALIM_H


class I_getSignalIm
{
public:
    I_getSignalIm();
    virtual ~I_getSignalIm();
    virtual double getSignalIm(const int &i) const = 0;
};

#endif // I_GETSIGNALIM_H
