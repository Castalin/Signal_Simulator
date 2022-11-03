#ifndef ALL_DATA_H
#define ALL_DATA_H
#include "ModSignalVariables.h"
#include "SignalVariables.h"

class All_Data
{
public:
    All_Data();

    ModSignalVariables* getModSignalVar();
    SignalVariables* getMainSignalVar();
    void setDecimationFrequence(const int &decimation);

private:
    ModSignalVariables m_modSignalVariables;
    SignalVariables m_signalVariables;
};

#endif // ALL_DATA_H
