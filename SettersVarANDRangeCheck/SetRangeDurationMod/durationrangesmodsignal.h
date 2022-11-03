#ifndef DURATIONRANGESMODSIGNAL_H
#define DURATIONRANGESMODSIGNAL_H
#include <QDoubleSpinBox>
#include "setrangedurationrectMod.h"

class DurationRangesModSignal : private A_signalMod
{
public:
    DurationRangesModSignal(ModSignalVariables *const modSignalVariables);
    void setPtrToDurationSpinNum(QDoubleSpinBox *const durationSpinNum);
    void checkRangeDuration(const int &index);

private:
    QDoubleSpinBox *m_ptrToDurationSpinNum;
    SetRangeDurationRectMod m_setRangeDurationRectMod;
    double getPowerOfDuration(const int &index);


    enum DURATION
    {
        ms                  = 0,
        us                  = 1,
        ns                  = 2,
    };
};

#endif // DURATIONRANGESMODSIGNAL_H
