#include "sinemodrect.h"
#include <QtMath>

SineModRect::SineModRect()
{

}

double SineModRect::getSignal(const int &i)
{
    return (s_amplitude + modRect.getSignal(i)) * qSin(2 * M_PI * s_frequency / s_decimation * i);
}
