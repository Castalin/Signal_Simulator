#include "BackEnd/controldatamain.h"

ControlDataMain::ControlDataMain()
    : a_Controller(2)
{
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

    connect(m_receiveSocket, &SettingsReceiver :: signal_messageReceived, this, &ControlDataMain :: slot_processingAddress);

}


void ControlDataMain::slot_processingAddress(const QByteArray receivedMessage)
{

    if (static_cast<quint8>(receivedMessage.at(0)) > 12)
    {
        return;
    }

    m_address = static_cast<GreenBoardAddressBytes>(receivedMessage.at(0));

    switch (m_address) {

        case GreenBoardAddressBytes::CONTROL:
        {
            m_Message->replace(17 + 2 * static_cast<int>(GreenBoardAddressBytes::CONTROL), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_controlSettingsOne(receivedMessage.at(1));
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_0:
        {
            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_0)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_A_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_A_DELAY_1:
        {
            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_A_DELAY_1)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_A_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_0:
        {
            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_0)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_B_DELAY_0(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_B_DELAY_1:
        {

            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_B_DELAY_1)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_ADC_B_DELAY_1(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_0:
        {
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_0)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::ADC_CONTROLWORD_1:
        {
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::ADC_CONTROLWORD_1)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::CONTROL2:
        {
            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::CONTROL2)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_controlSettingsTwo(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::LED:
        {
            m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::LED)), 1, QByteArray(1, receivedMessage.at(1)));
            emit signal_LED(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_0:
        {
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_0)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_1:
        {
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_1)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }

        case GreenBoardAddressBytes::SPI_BYTE_2:
        {
            //m_Message->replace((17 + 2 * static_cast<quint16>(GreenBoardAddressBytes::SPI_BYTE_2)), 1, QByteArray(1, receivedMessage.at(1)));
            //emit signal_controlSettingsOne(receivedMessage[1]);
            break;
        }
    }
    slot_sendMessage();
}
