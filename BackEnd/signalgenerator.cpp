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
    int firstDataAddress = 8;

    for (int i{0}; i < m_strobeSize * 4; i += 2)
    {
        memcpy(m_ptrToData->data() + i + firstDataAddress, &m_value, 2);
    }
}

void SignalGenerator::setValue(const int &value)
{
    m_value = value / 100.0 * 32768;
}

void SignalGenerator::setStrobeSize(const unsigned char &info)
{

}
