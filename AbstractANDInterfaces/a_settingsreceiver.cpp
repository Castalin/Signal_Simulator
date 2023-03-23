#include "AbstractANDInterfaces//a_settingsreceiver.h"
#include <QNetworkDatagram>


a_SettingsReceiver::a_SettingsReceiver(int validLength, QObject *parent)
    : QThread{parent}
{
    m_validLength = validLength;
    m_mutex = new QMutex;
}


bool a_SettingsReceiver::isWorking()
{
    bool workingThreadEnable;
    m_mutex->lock();
    workingThreadEnable = m_workingThreadEnabled;
    m_mutex->unlock();
    return workingThreadEnable;
}

void a_SettingsReceiver::slot_startThread(const QString &address, const int &port)
{
    if (!isWorking())
    {
        m_address = address;
        m_port = port;
        m_workingThreadEnabled = true;
        start();
    }
}

void a_SettingsReceiver::slot_stopThread()
{
    if (isWorking())
    {
        m_mutex->lock();
        m_workingThreadEnabled = false;
        m_mutex->unlock();
    }
}


void a_SettingsReceiver::run()
{
    QByteArray receivedMessage;

    m_socket = new QUdpSocket;
    m_socket->abort();
    m_socket->bind(QHostAddress(m_address), m_port);
    m_socket->open(QUdpSocket :: ReadOnly);

    while(m_workingThreadEnabled == true)
    {
        receivedMessage.clear();
        if (m_socket->state() == QUdpSocket :: BoundState)
        {
            receivedMessage = m_socket->receiveDatagram().data();
            if (receivedMessage.size() == m_validLength)
            {
                emit signal_messageReceived(receivedMessage);
            }
        }
        usleep(5);
    }

    delete m_socket;
    m_mutex->lock();
    m_workingThreadEnabled = false;
    m_mutex->unlock();
}

a_SettingsReceiver::~a_SettingsReceiver()
{
    m_mutex->lock();
    m_workingThreadEnabled = false;
    m_mutex->unlock();

    delete m_mutex;
    wait();
}
