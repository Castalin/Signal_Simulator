#include "preparerdatagraphs.h"
#include <QtMath>

PreparerDataGraphs::PreparerDataGraphs(SignalGenerator * const signalGenerator, QVector<QByteArray *> * const arraySignal, QObject *parent) //, QObject *parent
    : QObject{parent}, m_packetSize{256}, c_header{8}, m_signalGenerator{signalGenerator}, m_sendedMessage{arraySignal}
{
    m_workingThread = false;
    m_plotGraphs = false;

    m_mutex = new QMutex;
    m_timer = new QTimer;

    m_signalRe = QVector<double>(m_sendedMessage->size() * m_packetSize, 0.0);                       // m_sendedMessage->size() = num of packeth that holds full signal
    m_signalIm = QVector<double>(m_sendedMessage->size() * m_packetSize, 0.0);                       // 256 is num of samples in a packet
    m_signalAbs = QVector<double>(m_sendedMessage->size() * m_packetSize, 0.0);
    connect(m_timer, &QTimer :: timeout, this, &PreparerDataGraphs :: slot_timerShot);
}


PreparerDataGraphs::~PreparerDataGraphs()
{
    delete m_mutex;
    delete m_timer;
}

void PreparerDataGraphs::copyFromMessage()
{
    m_mutex->lock();
    qint16 value;

    for (int i{0}; i < m_sendedMessage->size(); i++)
    {
        for (int j{0}; j < m_packetSize; j++)
        {
            memcpy(&value, *m_sendedMessage[i].data() + c_header + 4 * j, sizeof(qint16));
            m_signalRe[i * m_packetSize + j] = static_cast<double>(value) / 11900.0;
            memcpy(&value, *m_sendedMessage[i].data() + c_header + 4 * i + 2, sizeof(qint16));
            m_signalIm[i * m_packetSize + j] = static_cast<double>(value) / 11900.0;
        }
    }

    m_mutex->unlock();
}

void PreparerDataGraphs::getFromSignalGenerator()
{
    m_signalGenerator->countSignal(m_signalRe, m_signalIm);
}

void PreparerDataGraphs::makeAbs()
{
    double re, im;
    for (int i{0}; i < m_sendedMessage->size(); i++)
    {
        for (int j{0}; j < m_packetSize; j++)
        {
            re = m_signalRe[i * m_packetSize + j] * m_signalRe[i * m_packetSize + j];
            im = m_signalIm[i * m_packetSize + j] * m_signalIm[i * m_packetSize + j];
            m_signalAbs[i * m_packetSize + j] =  qSqrt(re + im);
        }
    }
}

void PreparerDataGraphs::setPlottingEnable(const int &cond)
{
    cond == Qt :: Checked ? m_timer->start(std :: chrono :: milliseconds (40)) : m_timer->stop();
    m_plotGraphs  = !m_plotGraphs;
}

void PreparerDataGraphs::setThreadCondition(const bool &cond)
{
    m_workingThread = cond;
}

void PreparerDataGraphs::slot_timerShot()
{
    m_workingThread == true ? copyFromMessage() : getFromSignalGenerator();

    makeAbs();

    emit signalReAndIm(m_signalRe, m_signalIm);
    emit signalAbs(m_signalAbs);
}
