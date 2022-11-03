#include "durationrangesmainsignal.h"

DurationRangesMainSignal::DurationRangesMainSignal(SignalVariables * const signalVariables)
    : A_signal{signalVariables}, m_setRangeDurationRect{signalVariables}
{

}


void DurationRangesMainSignal::setPtrToDurationSpinNum(QDoubleSpinBox * const durationSpinNum)
{
    m_ptrToDurationSpinNum = durationSpinNum;
}

void DurationRangesMainSignal::checkRangeDuration(const int &index)
{
    double powerOfTime = getPowerOfDuration(index);
    if (m_ptrToDurationSpinNum->value() > m_signalVariables->m_duration * powerOfTime)
    {
        m_ptrToDurationSpinNum->setValue(m_signalVariables->m_duration * powerOfTime);
        m_ptrToDurationSpinNum->setMaximum(powerOfTime * m_setRangeDurationRect.setRangeDuration());
    }
    else
    {
        m_ptrToDurationSpinNum->setMaximum(powerOfTime * m_setRangeDurationRect.setRangeDuration());
        m_ptrToDurationSpinNum->setValue(m_signalVariables->m_duration  * powerOfTime);
    }
}

double DurationRangesMainSignal::getPowerOfDuration(const int &index)
{
    switch (index)
    {
    case DURATION :: ms:
    {
        m_ptrToDurationSpinNum->setSingleStep(0.001);
        return 1e3;
    }
    case DURATION :: us:
    {
        m_ptrToDurationSpinNum->setSingleStep(0.1);
        return 1e6;
    }
    case DURATION :: ns:
    {
        m_ptrToDurationSpinNum->setSingleStep(10.0);
        return 1e9;
    }
    default : {return 1e3;}
    }

}
