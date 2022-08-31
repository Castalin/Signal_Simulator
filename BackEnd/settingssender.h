#ifndef SETTINGSSENDER_H
#define SETTINGSSENDER_H

#include <QObject>
#include <QUdpSocket>

class SettingsSender
{
public:
    SettingsSender();


private:
    QUdpSocket *m_sendingSocket;
    QHostAddress *m_hostAddress;
    int m_hostPort;

public:
    void setAddressSettings(const QString &address, const int &port);
    virtual void sendMessage(const QByteArray *data);

};

#endif // SETTINGSSENDER_H
