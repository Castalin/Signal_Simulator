#ifndef SINE_H
#define SINE_H
#include "a_signal.h"
#include <QtMath>

class Sine : public A_signal
{
public:
    Sine();
    virtual double getSignal(const int &i) override;
};

#endif // SINE_H
