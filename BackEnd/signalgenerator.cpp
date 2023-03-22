#include "signalgenerator.h"


SignalGenerator::SignalGenerator(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables *const noiseVariables,
                                  QObject *parent)
    : QObject{parent}, m_factoryOfSignal{signalVariables, modSignalVariables, noiseVariables}, c_header{8}
{
    m_strobeSize = 32;

}


void SignalGenerator::countSignal(const int &numberOfPackage, QByteArray * const byteArrayPtr)
{
    (numberOfPackage == 0) ? countChannelA(byteArrayPtr) : countChannelB(byteArrayPtr);
    if (numberOfPackage == 7)
    {
        m_factoryOfSignal.resetI();
        qint16 value{0};
        memcpy(byteArrayPtr->data() + c_header + 1020, &value, sizeof(qint16));
        memcpy(byteArrayPtr->data() + c_header + 1022, &value, sizeof(qint16));
    }

}

void SignalGenerator::slot_setStrobeSize(const unsigned char &info)
{
    int strobeSize = 32;
    int increaseIn = (info & 0b01110000) >> 4;
    m_strobeSize = strobeSize * (1 << increaseIn);
}

void SignalGenerator::slot_setSignalType(const QPair<int, int> &signalType)
{
    m_factoryOfSignal.setSignalType(signalType);
}

void SignalGenerator::slot_setNoiseState(const QPair<int, int> &state)
{
    m_factoryOfSignal.setNoiseState(state);
}

void SignalGenerator::countChannelA(QByteArray * const byteArrayPtr)
{
    qint16 value;
    for (int i{0}; i < m_strobeSize - 1; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalReChannel_1))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalImChannel_1))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
    value = 0;
    memcpy(byteArrayPtr->data() + c_header + 4 * m_strobeSize - 4, &value, sizeof(qint16));
    memcpy(byteArrayPtr->data() + c_header + 4 * m_strobeSize - 2, &value, sizeof(qint16));

    m_factoryOfSignal.resetI();

    for (int i{m_strobeSize}; i < 256; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalReChannel_2))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalImChannel_2))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
}

void SignalGenerator::countChannelB(QByteArray * const byteArrayPtr)
{
    qint16 value;
    for (int i{0}; i < 256; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalReChannel_2))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal.*(m_factoryOfSignal.ptrToSignalImChannel_2))();
        memcpy(byteArrayPtr->data() + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
}


