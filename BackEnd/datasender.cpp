#include "BackEnd/datasender.h"

DataSender::DataSender(QByteArray *ptrToData,QObject *parent)
    : QThread{parent}, m_ptrToData{ptrToData}
{
    m_mutex = new QMutex;
    m_workingThreadEnable = false;
    m_sleepValue = m_sleepArray[0];
    m_numberOfPackage = 1;

    delete m_sendingSocket;
}

void DataSender::run()
{
    m_sendingSocket = new QUdpSocket;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
    int numPackAge{1};

    while (m_workingThreadEnable == true)
    {
        while (numPackAge != 9)
        {
            if (m_numberOfPackage == numPackAge)
            {

                sendMessage(m_ptrToData);
                ++m_sentMessages;
                emit signal_MessageSended(numPackAge);
                ++numPackAge;

            }
            usleep(1);
        }

        usleep(m_sleepValue);
        numPackAge = 1;
    }
    m_mutex->lock();
    m_workingThreadEnable = false;
    m_mutex->unlock();
    delete m_sendingSocket;
    emit signal_MessageSended(8);
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
        m_numberOfPackage = 1;
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

void DataSender::sleepValueChanged(int i)
{
    if (i < 4 && i >= 0)
    {
        m_mutex->lock();
        m_sleepValue = m_sleepArray[i];
        m_mutex->unlock();
    }
}

void DataSender::setAddressSettings(const QString &address, const int &port)
{
    m_hostPort = port;
    *m_hostAddress = QHostAddress(address);
}

void DataSender::messagePrepared(const int &numberOfPackage)
{
    m_numberOfPackage = numberOfPackage;
}

