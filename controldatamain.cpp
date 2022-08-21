#include "controldatamain.h"
#include <QNetworkDatagram>
#include <QtNetwork>

ControlDataMain::ControlDataMain(QObject *parent)
    : QObject{parent}
{
    m_sendingSocket = new QUdpSocket;
    m_receiveSocket = new SettingsReceiver;
    m_condition = new QByteArray(48, static_cast<qint8>(0x00));
    m_hostAddress = new QHostAddress;
    m_hostPort = new int;


    connect(m_receiveSocket, &SettingsReceiver :: signal_messageReceived, this, &ControlDataMain :: slot_processingAddress);
}


void ControlDataMain::slot_processingAddress(const QByteArray &receivedMessage)
{

    m_address = static_cast<GreenBoardAddressBytes>(receivedMessage[0]);

    switch (m_address) {

        case GreenBoardAddressBytes::CONTROL:
        {
            emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_0:
        {
            emit signal_ADC_A_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_1:
        {
            emit signal_ADC_A_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_0:
        {
            emit signal_ADC_B_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_1:
        {
            emit signal_ADC_B_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_0:
        {
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_1:
        {
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::CONTROL2:
        {
            emit signal_controlSettingsTwo(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::LED:
        {
            emit signal_LED(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_0:
        {
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }
        case GreenBoardAddressBytes::SPI_BYTE_1:
        {
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_2:
        {
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }
    }
    slot_sendCondition();
}


void ControlDataMain::slot_startControlThread(const QString &address, const int &port)
{
    m_receiveSocket->slot_startThread(address, port);
}

void ControlDataMain::slot_stopControlThread()
{
    m_receiveSocket->slot_stopThread();
}

void ControlDataMain::slot_setControlSettings(const QString &address, const int &port)
{
    *m_hostAddress = QHostAddress(address);
    *m_hostPort = port;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, *m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
}

void ControlDataMain::slot_sendCondition()
{
    m_sendingSocket->writeDatagram(*m_condition, *m_hostAddress, *m_hostPort);
}
