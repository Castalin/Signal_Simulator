#include "all_data.h"

All_Data::All_Data()
{

}

ModSignalVariables *All_Data::getModSignalVar()
{
    return &m_modSignalVariables;
}

SignalVariables *All_Data::getMainSignalVar()
{
    return &m_signalVariables;
}

NoiseVariables *All_Data::getNoiseVar()
{
    return &m_noiseVariables;
}

void All_Data::setDecimationFrequence(const int &decimation)
{
    m_signalVariables.m_decimation = decimation;
    m_modSignalVariables.m_decimation = decimation;
}
