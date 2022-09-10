#include "anglecounter.h"

AngleCounter::AngleCounter(QObject *parent)
    : QObject{parent}
{
    m_timer = new QTimer(this);
    m_angleValue = 0.0;
    m_angleSpeedValue = 0.0;
    m_angle16 = 0x00;

    connect(m_timer, &QTimer :: timeout, this, &AngleCounter :: timerOut);
    m_timer->start(std :: chrono :: milliseconds(5));
}

void AngleCounter::timerOut()
{
    if (m_angleSpeedValue == 0.0)
    {
        return;
    }
    else
    {
        m_angleValue += m_timer->interval()*m_angleSpeedValue / 1000;
        if (m_angleValue < 0.0)
        {
            m_angleValue += 360.0;
        }
        else if (m_angleValue > 360.0)
        {
            m_angleValue -= 360.0;
        }
        emit signal_angleValueChanged(m_angleValue);
        m_angle16 = m_angleValue / 360 * 32768.0;
    }
}

void AngleCounter::angleChanged(const double &value)
{
    m_angleValue = value;
    m_angle16 = m_angleValue / 360 * 32768.0;
}

void AngleCounter::angleSpeedChanged(const double &value)
{
    m_angleSpeedValue = value;
}

void *AngleCounter::getAngleint16()
{
    return &m_angle16;
}
