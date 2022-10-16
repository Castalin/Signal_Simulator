#include "a_signal.h"

A_signal::A_signal()
{

}

int A_signal :: s_decimation;
double A_signal :: s_amplitude;
double A_signal :: s_frequency;
double A_signal :: s_duration;

void A_signal :: setDecimation(const int &decimation)
{
    s_decimation = decimation;
}

void A_signal::setDuration(const double &duration)
{
     s_duration = duration;
}

void A_signal::setFrequency(const double &frequency)
{
    s_frequency = frequency;
}

void A_signal::setAmplitude(const double &amplitude)
{
    s_amplitude = amplitude;
}


