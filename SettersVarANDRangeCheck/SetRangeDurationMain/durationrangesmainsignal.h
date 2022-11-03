#ifndef DURATIONRANGESMAINSIGNAL_H
#define DURATIONRANGESMAINSIGNAL_H

#include "AbstractANDInterfaces/a_signal.h"
#include "setrangedurationrect.h"
#include <QDoubleSpinBox>

class DurationRangesMainSignal :  private A_signal
{
public:
    DurationRangesMainSignal(SignalVariables *const signalVariables);
    void setPtrToDurationSpinNum(QDoubleSpinBox *const durationSpinNum);
    void checkRangeDuration(const int &index);

private:
    QDoubleSpinBox *m_ptrToDurationSpinNum;
    SetRangeDurationRect m_setRangeDurationRect;
    double getPowerOfDuration(const int &index);


    enum DURATION
    {
        ms                  = 0,
        us                  = 1,
        ns                  = 2,
    };
};

#endif // DURATIONRANGESMAINSIGNAL_H
