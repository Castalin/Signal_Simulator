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

    NoSignal m_noSignal;
    Sine m_sine;
    Rectangle m_rectangle;
    ModSine m_modSine;
    ModRect m_modRect;
    SineModSine m_sineModSine;
    SineModRect m_sineModRect;
    RectModSine m_rectModSine;
    RectModRect m_rectModRect;


    A_signal *m_ptrToSignal;
    std :: map<QPair<int, int>, A_signal*> m_mapSignal;

public:
    void countSignal();

    void deleteSignal();
    void setStrobeSize(const unsigned char &info);
    void setDecimation(const int &decimation);

    void setSignalAmplitude(const int &amplitude);
    void setSignalFrequency(const double &frequency);
    void setSignalDuration(const double &duration);
    void setSignalType(const QPair<int, int> &signalType);

    void setSignalAmplitudeMod(const int &amplitudeMod);
    void setSignalFrequencyMod(const double &frequencyMod);
    void setSignalDurationMod(const double &durationMod);



signals:

};

#endif // SIGNALGENERATOR_H
