#include "preparerdatagraphs.h"
#include <QtMath>

PreparerDataGraphs::PreparerDataGraphs(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables,
                                       NoiseVariables *const noiseVariables, QObject *parent)
    : QObject{parent}, a_SignalGenerator{8, 256}
{
    m_plotGraphs = false;
    m_timer = new QTimer;
    m_factoryOfSignal = new FactoryOfSignal(signalVariables, modSignalVariables, noiseVariables, 4092); // 4096 times - 2 because end of channel A end with 2 for both Re and Im
                                                                                                        // and minus 2 for the same reason with channel B
    m_signalRe = QVector<double>(m_numOfPackets * m_sizeOfPacket, 0.0);                       // m_sendedMessage->size() = num of packeth that holds full signal
    m_signalIm = QVector<double>(m_numOfPackets* m_sizeOfPacket, 0.0);                       // 256 is num of samples in a packet
    m_signalAbs = QVector<double>(m_numOfPackets * m_sizeOfPacket, 0.0);
    connect(m_timer, &QTimer :: timeout, this, &PreparerDataGraphs :: slot_timerShot);
}


PreparerDataGraphs::~PreparerDataGraphs()
{
    delete m_timer;
}

void PreparerDataGraphs::makeAbs()
{
    double re, im;
    for (int i{0}; i < m_numOfPackets; i++)
    {
        for (int j{0}; j < m_sizeOfPacket; j++)
        {
            re = m_signalRe[i * m_sizeOfPacket + j] * m_signalRe[i * m_sizeOfPacket + j];
            im = m_signalIm[i * m_sizeOfPacket + j] * m_signalIm[i * m_sizeOfPacket + j];
            m_signalAbs[i * m_sizeOfPacket + j] =  qSqrt(re + im);
        }
    }
}

void PreparerDataGraphs::countChannelA()
{
    double value;
    for (int i{0}; i < m_strobeSize - 1; ++i)      // 8 - first signal address
    {
        value = (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalReChannel_1))();
        m_signalRe[i] = value;
        value =(m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalImChannel_1))();
        m_signalIm[i] = value;
    }
    m_signalRe[m_strobeSize - 1] = 0.0;
    m_signalIm[m_strobeSize - 1] = 0.0;
    m_factoryOfSignal->resetI();
}

void PreparerDataGraphs::countChannelB()
{
    double value;
    for (int i{m_strobeSize}; i < m_numOfPackets * m_sizeOfPacket - 1; i++)
    {
        value = (m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalReChannel_2))();
        m_signalRe[i] = value;
        value =(m_factoryOfSignal->*(m_factoryOfSignal->ptrToSignalImChannel_2))();
        m_signalIm[i] = value;
    }
    m_signalRe[m_numOfPackets * m_sizeOfPacket - 1] = 0.0;
    m_signalIm[m_numOfPackets * m_sizeOfPacket - 1] = 0.0;
    m_factoryOfSignal->resetI();
}

void PreparerDataGraphs::setPlottingEnable(const int &cond)
{
    cond == Qt :: Checked ? m_timer->start(std :: chrono :: milliseconds (40)) : m_timer->stop();
    m_plotGraphs  = !m_plotGraphs;
}

void PreparerDataGraphs::slot_setSignalType(const QPair<int, int> &signalType)
{
    m_factoryOfSignal->slot_setSignalType(signalType);

}

void PreparerDataGraphs::slot_setNoiseState(const QPair<int, int> &state)
{
    m_factoryOfSignal->slot_setNoiseState(state);
}

void PreparerDataGraphs::slot_timerShot()
{
    countChannelA();
    countChannelB();
    makeAbs();
    emit signalReAndIm(m_signalRe, m_signalIm);
    emit signalAbs(m_signalAbs);
}
