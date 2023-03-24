#include "signalgeneratorsender.h"
#include <QByteArray>

SignalGeneratorSender::SignalGeneratorSender(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables, const int numOfPackets, const int sizeOfPacket,
                                             QVector<QByteArray*> * const array)
    : a_SignalGenerator{numOfPackets, sizeOfPacket}, c_header{8}, m_byteArrayPtr{array}
{
    m_factoryOfSignal = new FactoryOfSignal{signalVariables, modSignalVariables, noiseVariables, 4094};    // now 4094 because we control end of A channel
    m_strobeSize = 32;                                                                                     // but can't cotnrol end of channel B, we may use if num == 7
    numberOfPackage = 0;                                                                                   // and use another loop...
}


void SignalGeneratorSender::countSignal()
{
    (numberOfPackage == 0) ? countChannelA() : countChannelB();   // channelA may contain a packet of samples or less than one packet, that's why we use it 1 time
    if (numberOfPackage == m_numOfPackets - 1)
    {
        m_factoryOfSignal->resetI();
        qint16 value{0};
        char *ptrToData = (*m_byteArrayPtr)[numberOfPackage]->data();
        memcpy(ptrToData + c_header + 1020, &value, sizeof(qint16));
        memcpy(ptrToData + c_header + 1022, &value, sizeof(qint16));
        numberOfPackage = -1;
    }
    numberOfPackage++;
}

void SignalGeneratorSender::slot_setSignalType(const QPair<int, int> &signalType)
{
    m_factoryOfSignal->slot_setSignalType(signalType);
}

void SignalGeneratorSender::slot_setNoiseState(const QPair<int, int> &state)
{
    m_factoryOfSignal->slot_setNoiseState(state);
}

void SignalGeneratorSender::countChannelA()
{
    char *ptrToData = (*m_byteArrayPtr)[numberOfPackage]->data();
    qint16 value;
    for (int i{0}; i < m_strobeSize - 1; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalReChannel_1))();
        memcpy(ptrToData + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalImChannel_1))();
        memcpy(ptrToData + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
    value = 0;
    memcpy(ptrToData + c_header + 4 * m_strobeSize - 4, &value, sizeof(qint16));
    memcpy(ptrToData + c_header + 4 * m_strobeSize - 2, &value, sizeof(qint16));

    m_factoryOfSignal->resetI();

    for (int i{m_strobeSize}; i < m_sizeOfPacket; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalReChannel_2))();
        memcpy(ptrToData + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalImChannel_2))();
        memcpy(ptrToData + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
}

void SignalGeneratorSender::countChannelB()
{
    char *ptrToData = (*m_byteArrayPtr)[numberOfPackage]->data();
    qint16 value;
    for (int i{0}; i < m_sizeOfPacket; ++i)      // 8 - first signal address
    {
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalReChannel_2))();
        memcpy(ptrToData + c_header + 4 * i, &value, sizeof(qint16));
        value = 11900 * (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalImChannel_2))();
        memcpy(ptrToData + c_header + 4 * i + 2, &value, sizeof(qint16));
    }
}



