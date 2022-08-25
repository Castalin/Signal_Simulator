#ifndef CONTROLDATAMAIN_H
#define CONTROLDATAMAIN_H

#include <QObject>
#include <QUdpSocket>
#include <settingsreceiver.h>

class ControlDataMain : public QObject
{
    Q_OBJECT
public:
    explicit ControlDataMain(QObject *parent = nullptr);


private:
    QUdpSocket *m_sendingSocket;
    SettingsReceiver *m_receiveSocket;
    QByteArray *m_condition;
    QHostAddress *m_hostAddress;
    int *m_hostPort;

    enum struct GreenBoardAddressBytes
    {
        CONTROL                             =   0x00,
        ADC_A_DELAY_0                       =   0x01,
        ADC_A_DELAY_1                       =   0x02,
        ADC_B_DELAY_0                       =   0x03,
        ADC_B_DELAY_1                       =   0x04,
        ADC_CONTROLWORD_0                   =   0x05,
        ADC_CONTROLWORD_1                   =   0x06,
        CONTROL2                            =   0x07,
        LED                                 =   0x08,
        SPI_BYTE_0                          =   0x09,
        SPI_BYTE_1                          =   0x0A,
        SPI_BYTE_2                          =   0x0B
    };


    GreenBoardAddressBytes m_address;

signals:
    void signal_controlSettingsOne(const unsigned char &info);
    void signal_controlSettingsTwo(const unsigned char &info);
    void signal_ADC_A_DELAY_0(const unsigned char &info);
    void signal_ADC_A_DELAY_1(const unsigned char &info);
    void signal_ADC_B_DELAY_0(const unsigned char &info);
    void signal_ADC_B_DELAY_1(const unsigned char &info);
    void signal_LED(const unsigned char &info);
    /*
    void signal_controlWord_0(const unsigned char &info);
    void signal_controlWord_1(const unsigned char &info);
    void signal_SPI_BYTE_0(const unsigned char &info);
    void signal_SPI_BYTE_1(const unsigned char &info);
    void signal_SPI_BYTE_2(const unsigned char &info);
    */
    // maybe other signals will be added, now we don't need it





public slots:
    void slot_setControlSettings(const QString &address, const int &port);
    void slot_processingAddress(const QByteArray receivedMessage);
    void slot_sendCondition();
    void slot_startControlThread(const QString &address, const int &port);
    void slot_stopControlThread();


};

#endif // CONTROLDATAMAIN_H
