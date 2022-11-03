#include "modrect.h"

ModRect::ModRect(ModSignalVariables * const modSignalVariable)
    : A_signalMod(modSignalVariable)
{

}

double ModRect::getSignal(const int &i)
{
    if (m_modSignalVariables->m_frequencyMod == 0)
    {
        if (i == 0 || i == 2047)
        {
            return 0.0;
        }
        else if (i <= m_modSignalVariables->m_durationMod * m_modSignalVariables->m_decimation)
        {
            return m_modSignalVariables->m_amplitudeMod;
        }
        else
        {
            return 0.0;
        }
    }

    else
    {
        if (i % (static_cast<int>(m_modSignalVariables->m_decimation / m_modSignalVariables->m_frequencyMod) - 1) == 0) // 13
        {
            return 0.0;
        }
        else if (i % (static_cast<int>(m_modSignalVariables->m_decimation / m_modSignalVariables->m_frequencyMod) - 1) <= static_cast<int>(m_modSignalVariables->m_durationMod * m_modSignalVariables->m_decimation))
        {
            return m_modSignalVariables->m_amplitudeMod;
        }
        else
        {
            return 0.0;
        }
    }
}
