#ifndef A_SIGNAL_H
#define A_SIGNAL_H


class A_signal
{
public:
    A_signal();
    virtual double getSignal(int &i) = 0;
    static void setDecimation(const int &decimation);

    static void setDuration(const double &duration);
    static void setFrequency(const double &frequency);
    static void setAmplitude(const double &amplitude);



protected:
    static int s_decimation;
    static double s_amplitude;
    static double s_frequency;
    static double s_duration;

};

#endif // A_SIGNAL_H
