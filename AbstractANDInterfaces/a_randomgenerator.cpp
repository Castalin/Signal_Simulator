#include "a_randomgenerator.h"
#include <cstdlib>
#include <ctime>

A_RandomGenerator::A_RandomGenerator()
{
    srand(time(0));
}

void A_RandomGenerator::generateValue()
{
    ++i;
    if (i >= 255)
    {
        m_randVariable =  2 * 3.1415 * (rand() % 360) / 360;
        i = 0;
    }
}
