#include "signalgenerator.h"
#include <QtMath>

SignalGenerator::SignalGenerator(QByteArray *ptrToData, QObject *parent)
    : QObject{parent}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;
    m_value = 0x00;
    m_decimation = 80e6;
}

void SignalGenerator::setSignal()
{

    for (int i{8}; i < 1024 + 8; i += 2)      // 8 - first signal address
    {
        memcpy(m_ptrToData->data() + i, &m_value, 2);
    }
}

void SignalGenerator::deleteSignal()
{
    qint64 value{0};
    for (int i{8}; i < m_strobeSize * 4 + 8; i += 8)      // 8 - first signal address
    {
        memcpy(m_ptrToData->data() + i, &value, 8);
    }
}

void SignalGenerator::setValue(const int &value)
{

        m_value = value / 100.0 * 11900;
}

void SignalGenerator::setStrobeSize(const unsigned char &info)
{
    int strobeSize = 32;
    m_strobeSize = strobeSize * qPow(2, (info & 0b01110000) >> 4);
}

void SignalGenerator::setDecimation(const int &value)
{
    m_decimation = value;
}
