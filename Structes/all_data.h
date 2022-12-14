#ifndef ALL_DATA_H
#define ALL_DATA_H
#include "ModSignalVariables.h"
#include "SignalVariables.h"
#include "NoiseVariables.h"

class All_Data
{
public:
    All_Data();

    ModSignalVariables* getModSignalVar();
    SignalVariables* getMainSignalVar();
    NoiseVariables* getNoiseVar();
    void setDecimationFrequence(const int &decimation);

private:
    ModSignalVariables m_modSignalVariables;
    SignalVariables m_signalVariables;
    NoiseVariables m_noiseVariables;
};

#endif // ALL_DATA_H
