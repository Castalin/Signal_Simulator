#include "durationrangesmodsignal.h"

DurationRangesModSignal::DurationRangesModSignal(ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}, m_setRangeDurationRectMod{modSignalVariables}
{

}

void DurationRangesModSignal::setPtrToDurationSpinNum(QDoubleSpinBox * const durationSpinNum)
{
    m_ptrToDurationSpinNum = durationSpinNum;
}

void DurationRangesModSignal::checkRangeDuration(const int &index)
{
    double powerOfTime = getPowerOfDuration(index);
    if (m_ptrToDurationSpinNum->value() > m_modSignalVariables->m_durationMod * powerOfTime)
    {
        m_ptrToDurationSpinNum->setValue(m_modSignalVariables->m_durationMod * powerOfTime);
        m_ptrToDurationSpinNum->setMaximum(powerOfTime * m_setRangeDurationRectMod.setRangeDuration());
    }
    else
    {
        m_ptrToDurationSpinNum->setMaximum(powerOfTime * m_setRangeDurationRectMod.setRangeDuration());
        m_ptrToDurationSpinNum->setValue(m_modSignalVariables->m_durationMod  * powerOfTime);
    }
}

double DurationRangesModSignal::getPowerOfDuration(const int &index)
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
