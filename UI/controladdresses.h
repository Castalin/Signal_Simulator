#ifndef CONTROLADDRESSES_H
#define CONTROLADDRESSES_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QUdpSocket>

class ControlAddresses : public QWidget
{
    Q_OBJECT
public:
    explicit ControlAddresses(QWidget *parent = nullptr);

signals:
    void signal_setControlSettings(const QString &address, const int &sendPort);
    void signal_startControlThread(const QString &address, const int &receiverPort);
    void signal_stopControlThread();

    //void signal_setSignalSettings(const QHostAddress &address, const int &sendPort);

private:
    QLineEdit *w_signalAddress;
    QSpinBox *w_signalSendPort;
    QSpinBox *w_signalReceivePort;

    QLineEdit *w_controlAddress;
    QSpinBox *w_controlSendPort;
    QSpinBox *w_controlReceivePort;

    QPushButton *w_setSettings;
    QPushButton *w_startReceiving;
    QPushButton *w_stopReceiving;


    QHostAddress getControlAddress();
    int getControlSendPort();
    int getControlReceivePort();
    QHostAddress getSignalAddress();
    int getSignalSendPort();
    int getSignalReceivePort();

private slots:
    void slot_setControlSettings();
    void slot_startControlThread();
    void slot_stopControlThread();


};

#endif // CONTROLADDRESSES_H
