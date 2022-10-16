#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include "Signal/signals_defenition.h"

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QByteArray *ptrToData, QObject *parent = nullptr);

private:
    int m_strobeSize;
    QByteArray *m_ptrToData;

    Sine m_sine;
    NoSignal m_noSignal;
    Rectangle m_rectangle;
    SineModSine m_sineModSine;

    A_signal *m_ptrToSignal;

public:
    void countSignal();

    void deleteSignal();
    void setStrobeSize(const unsigned char &info);
    void setDecimation(const int &decimation);

    void setSignalAmplitude(const int &amplitude);
    void setSignalFrequency(const double &frequency);
    void setSignalDuration(const double &duration);
    void setSignalType(const int &signalType);



signals:

};

#endif // SIGNALGENERATOR_H
