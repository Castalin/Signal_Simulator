#ifndef A_CONTROLLER_H
#define A_CONTROLLER_H

#include "settingsreceiver.h"
#include <QObject>
#include <QUdpSocket>

class a_Controller : public QObject
{
    Q_OBJECT
public:
    explicit a_Controller(int validLength = 0, QObject *parent = nullptr);

signals:

private:
    QUdpSocket *m_sendingSocket;
    QHostAddress *m_hostAddress;
    int m_hostPort;

protected:
    QByteArray *m_Message;
    SettingsReceiver *m_receiveSocket;

public slots:
    void slot_setAddressSettings(const QString &address, const int &port);
    void slot_startThread(const QString &address, const int &port);
    void slot_stopThread();
    void slot_sendMessage();

};

#endif // A_CONTROLLER_H
