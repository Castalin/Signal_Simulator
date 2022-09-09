#include "signalgenerator.h"

SignalGenerator::SignalGenerator(QByteArray *ptrToData, QObject *parent)
    : QObject{parent}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;
    m_value = 0x00;
}

void SignalGenerator::prepareData()
{

    for (int i{8}; i < m_strobeSize * 4 + 8; i += 2)      // 8 - first signal address
    {
        memcpy(m_ptrToData->data() + i, &m_value, 2);
    }
}

void SignalGenerator::setValue(const int &value)
{
    if (value == 100)
    {
        m_value = value / 100.0 * 32767;
    }
    else
    {
        m_value = value / 100.0 * 32768;
    }
}

void SignalGenerator::setStrobeSize(const unsigned char &info)
{
    int strobeSize = 32;
    for (int i{0}; i < ((info & 0b01110000) >> 4); ++i)
    {
        strobeSize <<= 1;
    }
    m_strobeSize = strobeSize;

    quint64 zero = 0x00;
    for (int i{strobeSize * 4 + 8}; i < 1032; i += 8)
    {
        memcpy(m_ptrToData->data() + i, &zero, 8);
    }
}
