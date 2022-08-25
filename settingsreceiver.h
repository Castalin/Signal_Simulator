#ifndef SETTINGSRECEIVER_H
#define SETTINGSRECEIVER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QUdpSocket>

class SettingsReceiver : public QThread
{
    Q_OBJECT
public:
    explicit SettingsReceiver(QObject *parent = nullptr);

private:
    QMutex *m_mutex;
    QUdpSocket *m_socket;

    bool m_workingThreadEnabled;
    QString m_address;
    int m_port;
    void run() override;
    bool isWorking();

public slots:
    void slot_startThread(const QString &address, const int &port);
    void slot_stopThread();





signals:
    void signal_messageReceived(const QByteArray message);

};

#endif // SETTINGSRECEIVER_H
