#ifndef MODULATIONUI_H
#define MODULATIONUI_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include "amplitudemodsignalui.h"
#include "SettersVarANDRangeCheck/settermodsignal.h"
#include "SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.h"
#include "SettersVarANDRangeCheck/SetRangeDurationMod/durationrangesmodsignal.h"

class ModulationUI : public QWidget
{
    Q_OBJECT
public:
    explicit ModulationUI(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, QWidget *parent = nullptr);

signals:
    void signal_signalType(const int &signalType);


private:

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxMod;
    QComboBox *w_frequencySignalBoxMod;
    QDoubleSpinBox *w_frequencySignalNumMod;
    QComboBox *w_durationSignalBoxMod;
    QDoubleSpinBox *w_durationSignalNumMod;
    AmplitudemodsignalUI *m_amplitudeModSignalUI;

    SetterModSignal m_setterModSignal;
    FreqRangesModSignal m_freqRangesModSignal;
    DurationRangesModSignal m_durationModSignal;

    enum SIGNALS
    {
        NO_SIGNAL           = 0,
        SINE                = 1,
        RECTANGLE           = 2,
    };

    SIGNALS m_mainSignalType;

private slots:
        void slot_checkedModul(const int &state);
        void slot_signalModChanged(const int &currentIndex);
        void slot_setDurationMod(const double &durationMod);

public:
        void setMainSignalType(const int &index);
        void DecimationFrequencyChanged();
        void mainSignalChanged();
        void stopMovingSlider();

};


#endif // MODULATIONUI_H
