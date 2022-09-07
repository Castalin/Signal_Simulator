#include "BackEnd/datasender.h"

DataSender::DataSender(QByteArray *ptrToData,QObject *parent)
    : QThread{parent}
{
    m_mutex = new QMutex;
    m_angleCounter = new AngleCounter;

    m_ptrToData = ptrToData;
    m_workingThreadEnable = false;
    m_sleepValue = 960;

    connect(m_angleCounter, &AngleCounter :: signal_angleValueChanged, this, &DataSender :: signal_angleValueChanged);

   delete m_sendingSocket;
}

void DataSender::run()
{
    m_sendingSocket = new QUdpSocket;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);

    const quint16 messageHeader[] = {0x55AA, 0x0000};
    qint16 numberOfPackage{0};
    void* angleAddress = m_angleCounter->getAngleint16();

    while (m_workingThreadEnable == true)
    {
        for (int i{0}; i < 8; ++i, ++numberOfPackage)
        {
            // (i == 0) ? memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[0], 2) : memcpy(&m_ptrToData + PACKAGE_NUM_BYTE_0, &messageHeader[1], 2);
            if (i == 0)
            {
                memcpy(m_ptrToData->data() + HEADER_BYTE_0, &messageHeader[0], 2);
            }
            else
            {
                memcpy(m_ptrToData->data() + HEADER_BYTE_0, &messageHeader[1], 2);
            }
            memcpy(m_ptrToData->data() + PACKAGE_NUM_BYTE_0, &numberOfPackage, 2);
            memcpy(m_ptrToData->data() + ANGLE_BYTE_0, angleAddress, 2);
            m_sendingSocket->writeDatagram(*m_ptrToData, *m_hostAddress, m_hostPort);

            usleep(1);
        }

        usleep(m_sleepValue);
    }
    m_mutex->lock();
    m_workingThreadEnable = false;
    m_mutex->unlock();
    delete m_sendingSocket;
}

bool DataSender::isWorking()
{
    m_mutex->lock();
    bool condition{m_workingThreadEnable};
    m_mutex->unlock();
    return condition;
}



void DataSender::startThread()
{
    if (isWorking() == false)
    {
        m_mutex->lock();
        m_workingThreadEnable = true;
        m_mutex->unlock();
        start();
    }
}

void DataSender::stopThread()
{
    if (isWorking() == true)
    {
        m_mutex->lock();
        m_workingThreadEnable = false;
        m_mutex->unlock();
    }
}

void DataSender::sleepValueChanged(const int &i)
{
        m_mutex->lock();
        m_sleepValue = (1000 / (i + 2)) - 40;
        m_mutex->unlock();
}

void DataSender::setAddressSettings(const QString &address, const int &port)
{
    m_hostPort = port;
    *m_hostAddress = QHostAddress(address);
}

void DataSender::angleChanged(const double &value)
{
    m_angleCounter->angleChanged(value);
}

void DataSender::angleSpeedChanged(const double &value)
{
    m_angleCounter->angleSpeedChanged(value);
}

