#include "sine.h"

Sine::Sine()
{

}

double Sine::getSignal(int &i)
{
    return s_amplitude * qSin(2 * M_PI * i * s_frequency / s_decimation);
}