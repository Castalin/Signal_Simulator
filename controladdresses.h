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

private:
    QLineEdit *w_signalAddress;
    QSpinBox *w_signalDataPort;
    QSpinBox *w_signalAnswerPort;

    QLineEdit *w_controlAddress;
    QSpinBox *w_controlDataPort;
    QSpinBox *w_controlAnswerPort;

    QPushButton *w_setSettings;
    QPushButton *w_startReceiving;
    QPushButton *w_stopReceiving;

    QUdpSocket *m_sendingSocket;

private slots:
    void slot_setSendingSettings();
};

#endif // CONTROLADDRESSES_H
