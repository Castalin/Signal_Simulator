#ifndef A_SETTINGSRECEIVER_H
#define A_SETTINGSRECEIVER_H

#include <QObject>
#include <QThread>
#include <QMutex>
#include <QUdpSocket>

class a_SettingsReceiver : public QThread
{
    Q_OBJECT
public:
    explicit a_SettingsReceiver(int validLength, QObject *parent = nullptr);
    ~a_SettingsReceiver();

private:
    QMutex *m_mutex;
    QUdpSocket *m_socket;

    bool m_workingThreadEnabled;
    QString m_address;
    int m_port;
    void run() override;
    bool isWorking();
    int m_validLength;

public slots:
    void slot_startThread(const QString &address, const int &port);
    void slot_stopThread();


signals:
    void signal_messageReceived(const QByteArray message);

};

#endif // A_SETTINGSRECEIVER_H
