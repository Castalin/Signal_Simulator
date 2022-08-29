#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain()
{
    m_Message->append(1032, 0x00);
    m_rxEnable = RxEnable :: DISABLED;
    m_angle = 0;
    m_velocityOfAngle = 0;

}

void SignalDataMain::slot_angleChanged(const double &value)
{
    m_angle = static_cast<quint16>(value);
}

void SignalDataMain::slot_velocityOfAngleChanged(const double &value)
{
    m_velocityOfAngle = static_cast<quint16>(360 / value * 10e6);
}

void SignalDataMain::slot_prepareData()
{

}












