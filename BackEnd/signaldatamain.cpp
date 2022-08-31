#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain(QObject *parent)
    : QObject{parent}
{
    m_Message = new QByteArray;
    m_Message->append(1032, 0x00);
    m_angle[0] = 0;
    m_angle[1] = 0;
    m_velocityOfAngle[0] = 0;
    m_velocityOfAngle[1] = 0;

}

void SignalDataMain::slot_angleChanged(const double &value)
{
    double var = value / 360 * 32768.0;
    m_angle[0] = static_cast<quint16>(var) & 0x00FF;
    m_angle[1] = static_cast<quint16>(var) >> 8;
    m_Message->replace(ANGLE_BYTE_1, 1, QByteArray(1, m_angle[1]));
    m_Message->replace(ANGLE_BYTE_0, 1, QByteArray(1, m_angle[0]));
}


void SignalDataMain::slot_prepareData(const int &num)
{
    m_Message->replace(PACKAGE_NUM_BYTE_0, 1, QByteArray(1, static_cast<quint8>(num)));

    if (num == 1)
    {
        m_Message->replace(HEADER_BYTE_1, 1, QByteArray(1, 0x55));
        m_Message->replace(HEADER_BYTE_0, 1, QByteArray(1, 0xAA));
    }
    else
    {
        m_Message->replace(HEADER_BYTE_1, 1, QByteArray(1, 0x00));
        m_Message->replace(HEADER_BYTE_0, 1, QByteArray(1, 0x00));
    }
}












