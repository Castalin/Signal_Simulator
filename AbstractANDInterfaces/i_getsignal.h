#ifndef I_GETSIGNAL_H
#define I_GETSIGNAL_H


class I_getSignal
{
public:
    I_getSignal();
    virtual ~I_getSignal();
    virtual double getSignal(const int &i) = 0;
};

#endif // I_GETSIGNAL_H
