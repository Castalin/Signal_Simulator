#include "a_randomgenerator.h"
#include <cstdlib>
#include <ctime>

A_RandomGenerator::A_RandomGenerator()
{
    srand(time(0));
    i = 0;
    m_randVariable = 0.0;
}

double A_RandomGenerator::generateValue()
{
    if (i == 4094)
    {
        i = 0;
        m_randVariable = 2 * 3.1415 * (rand() % 360) / 360;
    }
    ++i;
    return m_randVariable;
}



