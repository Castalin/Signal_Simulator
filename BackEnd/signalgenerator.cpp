#include "signalgenerator.h"
#include "QtMath"


SignalGenerator::SignalGenerator(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, QByteArray *ptrToData, QObject *parent)
    : QObject{parent}, m_factoryOfSignal{signalVariables, modSignalVariables}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;

}



void SignalGenerator::countSignal()
{
    quint16 value;
    for (int i{0}; i < 512; i += 2)      // 8 - first signal address
    {
        value = 11900 * m_factoryOfSignal.getSignal(i / 2);
        memcpy(m_ptrToData->data() + 2 * i + 8, &value, 2);
        memcpy(m_ptrToData->data() + 2 * (i + 1) + 8, &value, 2);
    }
}

void SignalGenerator::deleteSignal()
{
    qint64 value{0};
    for (int i{0}; i < m_strobeSize * 4; i += 8)      // 8 - first signal address
    {
        memcpy(m_ptrToData->data() + i + 8, &value, 8);
    }
}

void SignalGenerator::setStrobeSize(const unsigned char &info)
{
    int strobeSize = 32;
    m_strobeSize = strobeSize * qPow(2, (info & 0b01110000) >> 4);
}

void SignalGenerator::setSignalType(const QPair<int, int> &signalType)
{
    m_factoryOfSignal.setSignalType(signalType);
}


