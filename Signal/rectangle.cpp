#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle(SignalVariables * const signalVariables)
    : A_signal(signalVariables)
{

}

double Rectangle::getSignal(const int &i)
{
    if (m_signalVariables->m_frequency == 0)
    {
        if (i == 0 || i == 2047)
        {
            return 0.0;
        }
        else if (i <= m_signalVariables->m_duration * m_signalVariables->m_decimation)
        {
            return m_signalVariables->m_amplitude;
        }
        else
        {
            return 0.0;
        }
    }

    else
    {
        if (i % (static_cast<int>(m_signalVariables->m_decimation / m_signalVariables->m_frequency) - 1) == 0) // 13
        {
            return 0.0;
        }
        else if (i % (static_cast<int>(m_signalVariables->m_decimation / m_signalVariables->m_frequency) - 1) <= static_cast<int>(m_signalVariables->m_duration * m_signalVariables->m_decimation))
        {
            return m_signalVariables->m_amplitude;
        }
        else
        {
            return 0.0;
        }
    }
}

double Rectangle::getSignalIm(const int &i)
{
    return getSignal(i);
}

