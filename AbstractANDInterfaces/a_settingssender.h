#ifndef A_SETTINGSSENDER_H
#define A_SETTINGSSENDER_H

#include <QUdpSocket>

class SettingsSender
{
public:
    SettingsSender();
    virtual ~SettingsSender();

protected:
    QUdpSocket *m_sendingSocket;
    QHostAddress *m_hostAddress;
    int m_hostPort;

public:
    virtual void setAddressSettings(const QString &address, const int &port);
    virtual void sendMessage(const QByteArray *data);

};

#endif // A_SETTINGSSENDER_H
