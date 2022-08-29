#include "a_controller.h"

a_Controller::a_Controller(int validLength, QObject *parent)
    : QObject{parent}
{
    if (validLength > 0)
    {
        m_receiveSocket = new SettingsReceiver(validLength);
    }
    m_sendingSocket = new QUdpSocket;
    m_hostAddress = new QHostAddress;
    m_hostPort = 0;
    m_Message = new QByteArray;
}

void a_Controller::slot_setAddressSettings(const QString &address, const int &port)
{
    *m_hostAddress = QHostAddress(address);
    m_hostPort = port;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
}

void a_Controller::slot_startThread(const QString &address, const int &port)
{
    m_receiveSocket->slot_startThread(address, port);
}

void a_Controller::slot_stopThread()
{
    m_receiveSocket->slot_stopThread();
}

void a_Controller::slot_sendMessage()
{
    m_sendingSocket->writeDatagram(*m_Message, *m_hostAddress, m_hostPort);
}

