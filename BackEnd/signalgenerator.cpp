#include "signalgenerator.h"


SignalGenerator::SignalGenerator(QByteArray *ptrToData, QObject *parent)
    : QObject{parent}
{
    m_ptrToData = ptrToData;
    m_strobeSize = 32;
    A_signal :: setDecimation(80e6);
    A_signal :: setAmplitude(0);
    A_signal :: setFrequency(0);
    A_signal :: setDuration(0);
    A_signalMod :: setAmplitudeMod(0);
    A_signalMod :: setFrequencyMod(0);
    A_signalMod :: setDurationMod(0);

    m_mapSignal[QPair<int, int>(0, 0)] = &m_noSignal;
    m_mapSignal[QPair<int, int>(1, 0)] = &m_sine;
    m_mapSignal[QPair<int, int>(2, 0)] = &m_rectangle;
    m_mapSignal[QPair<int, int>(0, 1)] = &m_modSine;
    m_mapSignal[QPair<int, int>(0, 2)] = &m_modRect;
    m_mapSignal[QPair<int, int>(1, 1)] = &m_sineModSine;
    m_mapSignal[QPair<int, int>(1, 2)] = &m_sineModRect;
    m_mapSignal[QPair<int, int>(2, 1)] = &m_rectModSine;
    m_mapSignal[QPair<int, int>(2, 2)] = &m_rectModRect;

    m_ptrToSignal = &m_noSignal;
}



void SignalGenerator::countSignal()
{
    quint16 value;
    for (int i{0}; i < 512; i++)      // 8 - first signal address
    {
        value = 11900 * m_ptrToSignal->getSignal(i);
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

void SignalGenerator::setSignalAmplitude(const int &amplitude)
{

    A_signal :: setAmplitude(amplitude / 100.0);
}

void SignalGenerator::setSignalFrequency(const double &frequency)
{
    A_signal :: setFrequency(frequency);
}

void SignalGenerator::setSignalDuration(const double &duration)
{
    A_signal :: setDuration(duration);
}

void SignalGenerator::setSignalType(const QPair<int, int> &signalType)
{
    m_ptrToSignal = m_mapSignal.at(signalType);
}

void SignalGenerator::setSignalAmplitudeMod(const int &amplitudeMod)
{
    A_signalMod :: setAmplitudeMod(amplitudeMod / 100);
}

void SignalGenerator::setSignalFrequencyMod(const double &frequencyMod)
{
    A_signalMod :: setFrequencyMod(frequencyMod);
}

void SignalGenerator::setSignalDurationMod(const double &durationMod)
{
    A_signalMod :: setDurationMod(durationMod);
}

void SignalGenerator::setStrobeSize(const unsigned char &info)
{
    int strobeSize = 32;
    m_strobeSize = strobeSize * qPow(2, (info & 0b01110000) >> 4);
}

void SignalGenerator::setDecimation(const int &decimation)
{
    A_signal :: setDecimation(decimation);
}


