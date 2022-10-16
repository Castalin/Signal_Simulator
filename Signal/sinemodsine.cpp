#include "sinemodsine.h"
#include <QtMath>

SineModSine::SineModSine()
{

}


double SineModSine :: getSignal(int &i)
{
    return (s_amplitude + s_amplitudeMod * qSin(2 * M_PI * i * s_frequencyMod / s_decimation)) * qSin(2 * M_PI * i * s_frequency / s_decimation);
}
