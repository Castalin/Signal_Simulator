#include "sinemodsine.h"
#include <QtMath>

SineModSine::SineModSine()
{

}


double SineModSine :: getSignal(int &i)
{
    return (s_amplitude + modSine.getSignal(i)) * qSin(2 * M_PI * i * s_frequency / s_decimation);
}
