#ifndef SIGNALSUI_H
#define SIGNALSUI_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include "modulationui.h"
#include "amplitidemainsignalui.h"
#include "SettersVarANDRangeCheck/settermainsignal.h"
#include "SettersVarANDRangeCheck/SetRangeFrequencyMain/freqrangesmainsignal.h"
#include "SettersVarANDRangeCheck/SetRangeDurationMain/durationrangesmainsignal.h"

class SignalsUI : public QWidget
{
    Q_OBJECT
public:
    explicit SignalsUI(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, QWidget *parent = nullptr);
signals:
    void signal_signalType(const QPair<int, int> &signalType);

private:
    QComboBox *w_signalsBox;
    QComboBox *w_frequencySignalBox;
    QDoubleSpinBox *w_frequencySignalNum;
    QComboBox *w_durationSignalBox;
    QDoubleSpinBox *w_durationSignalNum;
    AmplitideMainSignalUI *m_amplitudeMainSignalUI;

    SetterMainSignal m_setterMainSignal;
    FreqRangesMainSignal m_freqRangesMainSignal;
    DurationRangesMainSignal m_durationRangesMainSignal;
    ModulationUI *m_modulationUI;

    QPair<int, int> m_signalType;


    enum SIGNALS
    {
        NO_SIGNAL           = 0,
        SINE                = 1,
        RECTANGLE           = 2,
    };


private slots:
    void slot_signalChanged(const int &currentIndex);
    void slot_setDuration(const double &duration);
    void slot_setFrequency(const double &frequency);

public slots:
    void slot_stopMovingSliderOut();
    void slot_decimationFrequenceChanged();




};

#endif // SIGNALSUI_H
