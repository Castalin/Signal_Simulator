#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain()
{
    m_Message->append(1032, 0x00);
    m_angle[0] = 0;
    m_angle[1] = 0;
    m_velocityOfAngle[0] = 0;
    m_velocityOfAngle[1] = 0;

}

void SignalDataMain::slot_angleChanged(const int &value)
{
    m_angle[0] = static_cast<quint8>(value);
    m_Message->replace(ANGLE_BYTE_0, m_angle[0]);
}

void SignalDataMain::slot_velocityOfAngleChanged(const double &value)
{
    if (value > 0)
    {
        m_velocityOfAngle[0] = static_cast<qint16>(360 / value * 10e6) & 0x00FF;
        m_Message->replace(ANGLE_VELOC_BYTE_0, m_velocityOfAngle[1]);
        m_velocityOfAngle[1] = static_cast<qint16>(360 / value * 10e6) >> 8;
        m_Message->replace(ANGLE_VELOC_BYTE_1, m_velocityOfAngle[0]);
    }
    else
    {
        m_velocityOfAngle[0] = static_cast<qint16>(360 / -value * 10e6) & 0x00FF;
        m_Message->replace(ANGLE_VELOC_BYTE_0, m_velocityOfAngle[1]);
        m_velocityOfAngle[1] = static_cast<qint16>(360 / -value * 10e6) >> 8;
        m_Message->replace(ANGLE_VELOC_BYTE_1, m_velocityOfAngle[0]);
    }

}

void SignalDataMain::slot_prepareData(const int &num)
{
    m_Message->replace(PACKAGE_NUM_BYTE_0, static_cast<quint8>(num));

    if (num == 0)
    {
        m_Message->replace(HEADER_BYTE_0, 0x55);
        m_Message->replace(HEADER_BYTE_1, 0xAA);
    }
    else
    {
        m_Message->replace(HEADER_BYTE_0, quint8(0x00));
        m_Message->replace(HEADER_BYTE_1, quint8(0x00));
    }
    slot_sendMessage();
}












