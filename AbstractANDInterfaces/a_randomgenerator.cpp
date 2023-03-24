#include "a_randomgenerator.h"
#include <cstdlib>
#include <ctime>

A_RandomGenerator::A_RandomGenerator(const int &refreshNum)
{
    srand(time(0));
    i = 0;
    m_randVariable = 0.0;
    m_refreshNum = refreshNum;
}

double A_RandomGenerator::generateValue()
{
    if (i == m_refreshNum)
    {
        i = 0;
        m_randVariable = 2 * 3.1415 * (rand() % 360) / 360;
    }
    ++i;
    return m_randVariable;
}



