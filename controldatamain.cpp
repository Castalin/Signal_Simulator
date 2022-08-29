#include "controldatamain.h"
#include <QNetworkDatagram>
#include <QtNetwork>

ControlDataMain::ControlDataMain(QObject *parent)
    : QObject{parent}
{
    m_sendingSocket = new QUdpSocket;
    m_receiveSocket = new SettingsReceiver;
    m_condition = new QByteArray;
    m_hostAddress = new QHostAddress;

    for (int i{0}; i < 8; ++i)
    {
        m_condition->append(0xAA);
        m_condition->append(0x55);
    }

    for (int i{0}; i < 16; ++i)
    {
        m_condition->append(0x00 + i);
        m_condition->append(static_cast<quint8>(0));
    }

    connect(m_receiveSocket, &SettingsReceiver :: signal_messageReceived, this, &ControlDataMain :: slot_processingAddress);

}


void ControlDataMain::slot_processingAddress(const QByteArray receivedMessage)
{

    m_address = static_cast<GreenBoardAddressBytes>(receivedMessage.at(0));

    switch (m_address) {

        case GreenBoardAddressBytes::CONTROL:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::CONTROL)), receivedMessage.at(1));
            emit signal_controlSettingsOne(receivedMessage.at(1));
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_0:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_0)), receivedMessage.at(1));
            emit signal_ADC_A_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_1:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_1)), receivedMessage.at(1));
            emit signal_ADC_A_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_0:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_0)), receivedMessage.at(1));
            emit signal_ADC_B_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_1:
        {

            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_1)), receivedMessage.at(1));
            emit signal_ADC_B_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_0:
        {
            //m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_0)), receivedMessage.at(1));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_1:
        {
            //m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_1)), receivedMessage.at(1));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::CONTROL2:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::CONTROL2)), receivedMessage.at(1));
            emit signal_controlSettingsTwo(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::LED:
        {
            m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::LED)), receivedMessage.at(1));
            emit signal_LED(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_0:
        {
            //m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_0)), receivedMessage.at(1));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_1:
        {
            //m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_1)), receivedMessage.at(1));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_2:
        {
            //m_condition->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_2)), receivedMessage.at(1));
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
    m_hostPort = port;
    m_sendingSocket->abort();
    m_sendingSocket->bind(*m_hostAddress, m_hostPort);
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
}

void ControlDataMain::slot_sendCondition()
{
    m_sendingSocket->writeDatagram(*m_condition, *m_hostAddress, m_hostPort);
}
