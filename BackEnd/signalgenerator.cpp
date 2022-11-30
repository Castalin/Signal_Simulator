#include "signalgenerator.h"
#include "QtMath"


SignalGenerator::SignalGenerator(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, QByteArray *ptrToData, QObject *parent)
    : QObject{parent}, m_factoryOfSignal{signalVariables, modSignalVariables}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;

}



void SignalGenerator::countSignal(const int &numberOfPackage)
{
    (numberOfPackage == 0) ? countChannelA() : countChannelB();
    if (numberOfPackage == 7)
    {
        m_factoryOfSignal.resetI();
        qint16 value{0};
        memcpy(m_ptrToData->data() + 8 + 1020, &value, 2);
        memcpy(m_ptrToData->data() + 8 + 1022, &value, 2);
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

void SignalGenerator::countChannelA()
{
    qint16 value;
    for (int i{0}; i < m_strobeSize - 1; ++i)      // 8 - first signal address
    {
        value = 11900 * m_factoryOfSignal.getSignalRe();
        memcpy(m_ptrToData->data() + 8 + 4 * i, &value, 2);
        value = 11900 * m_factoryOfSignal.getSignalIm();
        memcpy(m_ptrToData->data() + 8 + 4 * i + 2, &value, 2);
    }
    value = 0;
    memcpy(m_ptrToData->data() + 8 + 4 * m_strobeSize - 4, &value, 2);
    memcpy(m_ptrToData->data() + 8 + 4 * m_strobeSize - 2, &value, 2);

    m_factoryOfSignal.resetI();

    for (int i{m_strobeSize}; i < 256; ++i)      // 8 - first signal address
    {
        value = 11900 * m_factoryOfSignal.getSignalRe();
        memcpy(m_ptrToData->data() + 8 + 4 * i, &value, 2);
        value = 11900 * m_factoryOfSignal.getSignalIm();
        memcpy(m_ptrToData->data() + 8 + 4 * i + 2, &value, 2);
    }
}

void SignalGenerator::countChannelB()
{
    qint16 value;
    for (int i{0}; i < 256; ++i)      // 8 - first signal address
    {
        value = 11900 * m_factoryOfSignal.getSignalRe();
        memcpy(m_ptrToData->data() + 8 + 4 * i, &value, 2);
        value = 11900 * m_factoryOfSignal.getSignalIm();
        memcpy(m_ptrToData->data() + 8 + 4 * i + 2, &value, 2);
    }
}


