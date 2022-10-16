#ifndef NOSIGNAL_H
#define NOSIGNAL_H
#include "a_signal.h"

class NoSignal : public A_signal
{
public:
    NoSignal();
    virtual double getSignal(int &i) override;
};

#endif // NOSIGNAL_H
