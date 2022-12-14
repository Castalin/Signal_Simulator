#include "modrip.h"
#include <QtMath>
#include <cstdlib>
#include <ctime>


ModRIP::ModRIP(ModSignalVariables * const modSignalVariables, QObject *parent)
    : QObject{parent}, A_signalMod{modSignalVariables}
{
    m_timer = new QTimer;
    srand(time(0));
    connect(m_timer, &QTimer :: timeout, this, &ModRIP :: slot_timeOut);
}

double ModRIP::getSignal(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qCos(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + m_phase);
}

double ModRIP::getSignalIm(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + m_phase);
}

void ModRIP::startTimer()
{
    m_timer->start(std :: chrono :: milliseconds(750));
}

void ModRIP::stopTimer()
{
    m_timer->stop();
}

void ModRIP::slot_timeOut()
{
    m_phase = 2 * M_PI * (rand() % 360) / 360;
}
