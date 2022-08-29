#include "signaldatamain.h"


SignalDataMain::SignalDataMain()
{
    m_Message->append(1032, 0x00);
    m_rxEnable = RxEnable :: DISABLED;
    m_angle = 0;
    m_velocityOfAngle = 0;

}

void SignalDataMain::slot_prepareData()
{

}












