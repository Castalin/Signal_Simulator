#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "a_signal.h"

class Rectangle : public A_signal
{
public:
    Rectangle();
    virtual double getSignal(const int &i) override;
};

#endif // RECTANGLE_H
