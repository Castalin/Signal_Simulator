#include "BackEnd/SignalSender/signaldatasender.h"


SignalDataSender::SignalDataSender(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                                   QObject *parent)
    : QThread{parent}, m_numOfPackets{8}
{
    m_mutex = new QMutex;
    m_angleCounter = new AngleCounter;
    m_Message = QVector<QByteArray*>(m_numOfPackets, new QByteArray(1032, 0x00));                      // 1032 bytes minus header(8) = 1024 bytes = 256 re and 256 imag samples qint16
    m_signalGeneratorSender = new SignalGeneratorSender(signalVariables, modSignalVariables, noiseVariables, m_numOfPackets, 256, &m_Message);         // here the same 8 packets

    m_workingThreadEnable = false;
    m_sleepValue = 960;

    connect(m_angleCounter, &AngleCounter :: signal_angleValueChanged, this, &SignalDataSender :: signal_angleValueChanged);
    delete m_sendingSocket;
}

SignalDataSender::~SignalDataSender()
{
    delete m_mutex;
    delete m_angleCounter;
    for (int i{0}; i < m_Message.size(); ++i)
    {
        delete m_Message[i];
    }
}

void SignalDataSender::run()
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
            for (int i{0}; i < m_numOfPackets; ++i, ++numberOfPackage)
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
                m_signalGeneratorSender->countSignal();
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

bool SignalDataSender::isWorking()
{
    m_mutex->lock();
    bool condition{m_workingThreadEnable};
    m_mutex->unlock();
    return condition;
}


void SignalDataSender::slot_setAddressSettings(const QString &address, const int &port)
{
    m_hostPort = port;
    *m_hostAddress = QHostAddress(address);
}

void SignalDataSender::slot_angleChanged(const double &value)
{
    m_angleCounter->angleChanged(value);
}

void SignalDataSender::slot_angleSpeedChanged(const double &value)
{
    m_angleCounter->angleSpeedChanged(value);
}


void SignalDataSender::slot_RxEnableValueChanged(const bool &sentData)
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

void SignalDataSender::slot_startSourceScale(const int &startSourceScale)
{
    m_mutex->lock();
    m_sleepValue = startSourceScale;
    m_mutex->unlock();
}

void SignalDataSender::slot_setStrobeSize(const int &strobeSize)
{
    m_mutex->lock();
    m_signalGeneratorSender->setStrobeSize(strobeSize);
    m_mutex->unlock();
}

void SignalDataSender::slot_setSignalType(const QPair<int, int> &signalType)
{
    m_signalGeneratorSender->slot_setSignalType(signalType);
}

void SignalDataSender::slot_setNoiseState(const QPair<int, int> &state)
{
    m_signalGeneratorSender->slot_setNoiseState(state);
}









