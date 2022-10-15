#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QByteArray *ptrToData, QObject *parent = nullptr);

private:
    int m_strobeSize;
    QByteArray *m_ptrToData;
    double m_value;
    int m_decimation;
    double m_frequency;
    double m_duration;

    double (SignalGenerator :: *m_ptrSignal)(int);

    double no_signal(int i);
    double sine(int i);
    double rect(int i);



public:
    void countSignal();

    void deleteSignal();
    void setStrobeSize(const unsigned char &info);
    void setDecimation(const int &value);

    void setSignalValue(const int &value);
    void setSignalFrequency(const double &frequency);
    void setSignalDuration(const double &duration);
    void setSignalType(const int &signalType);



signals:

};

#endif // SIGNALGENERATOR_H
