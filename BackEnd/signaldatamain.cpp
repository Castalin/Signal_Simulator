#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain(QObject *parent)
    : QThread{parent}
{
    m_Message = new QByteArray(1032, 0x00);
    m_mutex = new QMutex;
    m_angleCounter = new AngleCounter;
    m_signalGenerator = new SignalGenerator(m_Message);

    m_workingThreadEnable = false;
    m_sleepValue = 960;

    connect(m_angleCounter, &AngleCounter :: signal_angleValueChanged, this, &SignalDataMain :: signal_angleValueChanged);
    delete m_sendingSocket;
}

void SignalDataMain::run()
{
    m_sendingSocket = new QUdpSocket;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);

    const quint16 messageHeader[] = {0x55AA, 0x0000};
    qint16 numberOfPackage{0};
    void* angleAddress = m_angleCounter->getAngleint16();
    forever
    {
        while (m_workingThreadEnable == true)
        {
            for (int i{0}; i < 8; ++i, ++numberOfPackage)
            {
                // (i == 0) ? memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[0], 2) : memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[1], 2);
                if (i == 0)
                {
                    memcpy(m_Message->data() + HEADER_BYTE_0, &messageHeader[0], 2);
                }
                else
                {
                    memcpy(m_Message->data() + HEADER_BYTE_0, &messageHeader[1], 2);
                }
                memcpy(m_Message->data() + PACKAGE_NUM_BYTE_0, &numberOfPackage, 2);
                memcpy(m_Message->data() + ANGLE_BYTE_0, angleAddress, 2);
                m_sendingSocket->writeDatagram(*m_Message, *m_hostAddress, m_hostPort);

                usleep(1);
            }

            usleep(m_sleepValue);
            m_signalGenerator->setSignal();
        }
        m_mutex->lock();
        m_workingThreadEnable = false;
        m_mutex->unlock();

        msleep(200);
        if (m_workingThreadEnable == false)
        {
            break;
        }
    }
    delete m_sendingSocket;
}

bool SignalDataMain::isWorking()
{
    m_mutex->lock();
    bool condition{m_workingThreadEnable};
    m_mutex->unlock();
    return condition;
}


void SignalDataMain::slot_setAddressSettings(const QString &address, const int &port)
{
    m_hostPort = port;
    *m_hostAddress = QHostAddress(address);
}

void SignalDataMain::slot_angleChanged(const double &value)
{
    m_angleCounter->angleChanged(value);
}

void SignalDataMain::slot_angleSpeedChanged(const double &value)
{
    m_angleCounter->angleSpeedChanged(value);
}


void SignalDataMain::slot_RxEnableValueChanged(const unsigned char &sentData)
{
    if ((sentData & 0x01) == true)
    {
        if (isWorking() == false)
        {
            m_mutex->lock();
            m_workingThreadEnable = true;
            m_mutex->unlock();
            start();
        }
    }
    else
    {
        if (isWorking() == true)
        {
            m_mutex->lock();
            m_workingThreadEnable = false;
            m_mutex->unlock();
        }
    }

}

void SignalDataMain::slot_StrobeSizeValueChanged(const unsigned char &sentData)
{
    m_signalGenerator->setStrobeSize(sentData);
}

void SignalDataMain::slot_startSourceScale(const unsigned char &info)
{
    m_mutex->lock();
    m_sleepValue = (1000 / (static_cast<int>(info & 0b00000011) + 2)) - 40;
    m_mutex->unlock();
}

void SignalDataMain::slot_setSignalValue(const int &value)
{
    m_signalGenerator->setValue(value);
}












