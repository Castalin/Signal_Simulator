#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain(QObject *parent)
    : QObject{parent}
{
    m_Message = new QByteArray(1032, 0x00);
    m_DataSender = new DataSender(m_Message);

    connect(m_DataSender, &DataSender :: signal_angleValueChanged, this, &SignalDataMain :: signal_angleValueChanged);
}

void SignalDataMain::slot_setAddressSettings(const QString &address, const int &port)
{
    m_DataSender->setAddressSettings(address, port);
}

void SignalDataMain::slot_angleChanged(const double &value)
{
    m_DataSender->angleChanged(value);
}

void SignalDataMain::slot_angleSpeedChanged(const double &value)
{
    m_DataSender->angleSpeedChanged(value);
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
    }

}

void SignalDataMain::slot_startSourceScale(const unsigned char &info)
{
    m_DataSender->sleepValueChanged(static_cast<int>(info & 0b00000011));
}












