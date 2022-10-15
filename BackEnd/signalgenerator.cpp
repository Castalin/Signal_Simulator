#include "signalgenerator.h"
#include <QtMath>

SignalGenerator::SignalGenerator(QByteArray *ptrToData, QObject *parent)
    : QObject{parent}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;
    m_value = 0;
    m_decimation = 80e6;
    m_frequency = 0;
    m_duration = 0;
    m_ptrSignal = &SignalGenerator :: no_signal;
}

double SignalGenerator::no_signal(int i)
{
    return m_value;
}

double SignalGenerator::sine(int i)
{
    return m_value * qSin(2 * M_PI * i * m_frequency / m_decimation);
}

double SignalGenerator::rect(int i)
{
    if (m_frequency == 0)
    {
        if (i == 0 || i == 511)
        {
            return 0.0;
        }
        else if (i <= m_duration * m_decimation)
        {
            return m_value * 1.0;
        }
        else
        {
            return 0.0;
        }
    }

    else
    {
        if (i % (static_cast<int>(m_decimation / m_frequency) - 1) == 0) // 13
        {
            return 0.0;
        }
        else if (i % (static_cast<int>(m_decimation / m_frequency)- 1) <= static_cast<int>(m_duration * m_decimation))
        {
            return m_value * 1.0;
        }
        else
        {
            return 0.0;
        }
    }

}

void SignalGenerator::countSignal()
{

    for (int i{0}; i < 512; i++)      // 8 - first signal address
    {
        quint16 value = 11900 * (this->*m_ptrSignal)(i);
        memcpy(m_ptrToData->data() + 2 * i + 8, &value, 2);
        memcpy(m_ptrToData->data() + 2 * (i + 1) + 8, &value, 2);
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

void SignalGenerator::setSignalValue(const int &value)
{

    m_value = value / 100.0; // * 11900
}

void SignalGenerator::setSignalFrequency(const double &frequency)
{
    m_frequency = frequency;
}

void SignalGenerator::setSignalDuration(const double &duration)
{
    m_duration = duration;
}

void SignalGenerator::setSignalType(const int &signalType)
{
    switch(signalType)
    {
    case 0 : {m_ptrSignal = &SignalGenerator :: no_signal; break;}
    case 1 : {m_ptrSignal = &SignalGenerator :: sine; break;}
    case 2 : {m_ptrSignal = &SignalGenerator :: rect; break;}
    }
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


