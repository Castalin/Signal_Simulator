#ifndef NOSIGNAL_H
#define NOSIGNAL_H
#include "a_signal.h"

class NoSignal : public A_signal
{
public:
    NoSignal();
    virtual double getSignal(const int &i) override;
};

#endif // NOSIGNAL_H
