#include "settingssender.h"

SettingsSender::SettingsSender()
{
    m_hostPort = 0;
    m_sendingSocket = new QUdpSocket;
    m_hostAddress = new QHostAddress;

}

void SettingsSender::setAddressSettings(const QString &address, const int &port)
{
    *m_hostAddress = QHostAddress(address);
    m_hostPort = port;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
}

void SettingsSender::sendMessage(const QByteArray *data)
{
    m_sendingSocket->writeDatagram(*data, *m_hostAddress, m_hostPort);
}

