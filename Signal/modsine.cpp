#include "modsine.h"
#include <QtMath>


ModSine::ModSine()
{

}

double ModSine::getSignal(int &i)
{
    return s_amplitudeMod * qSin(2 * M_PI * i * s_frequencyMod / s_decimation);
}
