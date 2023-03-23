#include "BackEnd/processincomingdata.h"

ProcessIncomingData::ProcessIncomingData(QObject *parent)
    : QObject{parent}
{
    m_Message = new QByteArray;
    m_ReceiveSocket = new a_SettingsReceiver(2);    // 2 - number of valid packages
    m_SendingSocket = new a_SettingsSender;

    for (int i{0}; i < 8; ++i)
    {
        m_Message->append(0xAA);
        m_Message->append(0x55);
    }

    for (int i{0}; i < 16; ++i)
    {
        m_Message->append(0x00 + i);
        m_Message->append(static_cast<quint8>(0));
    }

    connect(m_ReceiveSocket, &a_SettingsReceiver :: signal_messageReceived, this, &ProcessIncomingData :: slot_processingAddress);

}

ProcessIncomingData::~ProcessIncomingData()
{
    delete m_Message;
    delete m_ReceiveSocket;
    delete m_SendingSocket;
}


void ProcessIncomingData::slot_processingAddress(const QByteArray receivedMessage)
{

    if (static_cast<quint8>(receivedMessage.at(0)) > 12)
    {
        return;
    }

    m_address = static_cast<GreenBoardAddressBytes>(receivedMessage.at(0));

    switch (m_address) {

        case GreenBoardAddressBytes::CONTROL:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::CONTROL), receivedMessage.data() + 1, 1);
            //m_Message->replace(17 + 2 * static_cast<int>(GreenBoardAddressBytes::CONTROL), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_controlSettingsOne(receivedMessage.at(1));
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_0:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_A_DELAY_0), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_0)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_A_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_1:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_A_DELAY_1), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_1)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_A_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_0:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_B_DELAY_0), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_0)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_B_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_1:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_B_DELAY_1), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_1)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_B_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_0:
        {
            //memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_CONTROLWORD_0), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_0)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_1:
        {
            //memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::ADC_CONTROLWORD_1), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_1)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::CONTROL2:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::CONTROL2), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::CONTROL2)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_controlSettingsTwo(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::LED:
        {
            memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::LED), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::LED)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_LED(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_0:
        {
            //memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::SPI_BYTE_0), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_0)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_1:
        {
            //memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::SPI_BYTE_1), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_1)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_2:
        {
            //memcpy(m_Message->data() + 17 + 2 * static_cast<int>(GreenBoardAddressBytes::SPI_BYTE_2), receivedMessage.data() + 1, 1);
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_2)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }
    }
    m_SendingSocket->sendMessage(m_Message);
}

void ProcessIncomingData::slot_setAddressSettings(const QString &address, const int &port)
{
    m_SendingSocket->setAddressSettings(address, port);
}

void ProcessIncomingData::slot_startThread(const QString &address, const int &port)
{
    m_ReceiveSocket->slot_startThread(address, port);
}

void ProcessIncomingData::slot_stopThread()
{
    m_ReceiveSocket->slot_stopThread();
}

