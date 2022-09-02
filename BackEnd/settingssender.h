#ifndef SETTINGSSENDER_H
#define SETTINGSSENDER_H

#include <QUdpSocket>

class SettingsSender
{
public:
    SettingsSender();

protected:
    QUdpSocket *m_sendingSocket;
    QHostAddress *m_hostAddress;
    int m_hostPort;

public:
    virtual void setAddressSettings(const QString &address, const int &port);
    virtual void sendMessage(const QByteArray *data);

};

#endif // SETTINGSSENDER_H
