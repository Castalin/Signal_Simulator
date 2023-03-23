#include "BackEnd/signaldatamain.h"


SignalDataMain::SignalDataMain(SignalGenerator * const signalGenerator, QObject *parent)
    : QThread{parent}
{
    m_Message = QVector<QByteArray*>(8, new QByteArray(1032, 0x00));
    m_mutex = new QMutex;
    m_angleCounter = new AngleCounter;
    m_signalGenerator = signalGenerator;

    m_workingThreadEnable = false;
    m_sleepValue = 960;

    connect(m_angleCounter, &AngleCounter :: signal_angleValueChanged, this, &SignalDataMain :: signal_angleValueChanged);
    delete m_sendingSocket;
}

SignalDataMain::~SignalDataMain()
{
    delete m_mutex;
    delete m_angleCounter;
    for (int i{0}; i < m_Message.size(); ++i)
    {
        delete m_Message[i];
    }
}

QVector<QByteArray *> *SignalDataMain::getMessagePtr()
{
   return &m_Message;
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
            m_mutex->lock();
            for (int i{0}; i < 8; ++i, ++numberOfPackage)
            {
                // (i == 0) ? memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[0], 2) : memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[1], 2);
                if (i == 0)
                {
                    memcpy(m_Message[i]->data() + HEADER_BYTE_0, &messageHeader[0], 2);
                }
                else
                {
                    memcpy(m_Message[i]->data() + HEADER_BYTE_0, &messageHeader[1], 2);
                }
                memcpy(m_Message[i]->data() + PACKAGE_NUM_BYTE_0, &numberOfPackage, 2);
                memcpy(m_Message[i]->data() + ANGLE_BYTE_0, angleAddress, 2);
                m_signalGenerator->countSignal(i, m_Message[i]);
                m_sendingSocket->writeDatagram(*m_Message[i], *m_hostAddress, m_hostPort);

                usleep(1);
            }
            m_mutex->unlock();
            usleep(m_sleepValue);
        }
        m_mutex->lock();
        m_workingThreadEnable = false;
        m_mutex->unlock();

        msleep(20);
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


void SignalDataMain::slot_RxEnableValueChanged(const bool &sentData)
{
    if (sentData == true)
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

void SignalDataMain::slot_startSourceScale(const unsigned char &info)
{
    m_mutex->lock();
    m_sleepValue = (1000 / (static_cast<int>(info & 0b00000011) + 2)) - 40;
    m_mutex->unlock();
}









