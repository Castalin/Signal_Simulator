#ifndef SETTERMODSIGNAL_H
#define SETTERMODSIGNAL_H
#include "AbstractANDInterfaces/a_signalmod.h"

class SetterModSignal : private A_signalMod
{
public:
    SetterModSignal(ModSignalVariables *const modSignalVariables);
    void setModAmplitude(const int &modAmplitude);
    void setModFrequency(const int &index, const double &modFrequency);
    void setModDuration(const int &index, const double &modDuration);


private:
    enum FREQUENCY
    {
        kHz                 = 0,
        MHz                 = 1,
    };

    enum DURATION
    {
        ms                  = 0,
        us                  = 1,
        ns                  = 2,
    };
};

#endif // SETTERMODSIGNAL_H
