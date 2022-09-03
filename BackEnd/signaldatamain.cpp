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
    m_Message->replace(HEADER_BYTE_1, 1, QByteArray(1, 0x55));
    m_Message->replace(HEADER_BYTE_0, 1, QByteArray(1, 0xAA));
    m_Message->replace(PACKAGE_NUM_BYTE_0, 1, QByteArray(1, static_cast<qint8>(1)));

    m_DataSender = new DataSender(m_Message);
    connect(m_DataSender, &DataSender :: signal_MessageSended, this, &SignalDataMain :: slot_prepareData);

}

void SignalDataMain::slot_setAddressSettings(const QString &address, const int &port)
{
    m_DataSender->setAddressSettings(address, port);
}

void SignalDataMain::slot_angleChanged(const double &value)
{
    double var = value / 360 * 32768.0;
    m_angle[0] = static_cast<quint16>(var) & 0x00FF;
    m_angle[1] = static_cast<quint16>(var) >> 8;
    memcpy(m_Message->data() + ANGLE_BYTE_1, &m_angle[1], 1);
    memcpy(m_Message->data() + ANGLE_BYTE_0, &m_angle[0], 1);
}


void SignalDataMain::slot_prepareData(const int &num)
{

    if (num == 8)
    {
        memcpy(m_Message->data() + HEADER_BYTE_0, &c_constants[0], 1);
        memcpy(m_Message->data() + HEADER_BYTE_1, &c_constants[1], 1);
        memcpy(m_Message->data() + PACKAGE_NUM_BYTE_0, &c_constants[3], 1);
        num_Changed++;
        m_DataSender->messagePrepared(c_constants[3]);
    }
    else
    {
        int numm{num + 1};
        memcpy(m_Message->data() + PACKAGE_NUM_BYTE_0, &(numm), 1);
        memcpy(m_Message->data() + HEADER_BYTE_1, &c_constants[2], 1);
        memcpy(m_Message->data() + HEADER_BYTE_0, &c_constants[2], 1);
        num_Changed++;
        m_DataSender->messagePrepared(numm);
    }
}

void SignalDataMain::slot_RxEnableValueChanged(const unsigned char &sentData)
{
    if ((sentData & 0x01) == true)
    {
        m_DataSender->startThread();
    }
    else
    {
        m_DataSender->stopThread();
        num_Changed--;
    }
}

void SignalDataMain::slot_startSourceScale(const unsigned char &info)
{
    m_DataSender->sleepValueChanged(static_cast<int>(info & 0b00000011));
}












