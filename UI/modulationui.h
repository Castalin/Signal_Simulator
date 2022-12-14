#ifndef MODULATIONUI_H
#define MODULATIONUI_H

#include <QWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QCheckBox>
#include <map>
#include "amplitudemodsignalui.h"
#include "SettersVarANDRangeCheck/settermodsignal.h"
#include "SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.h"
#include "SettersVarANDRangeCheck/SetRangeDurationMod/durationrangesmodsignal.h"
#include "SettersVarANDRangeCheck/SetRangeAmplitudeMod/amplrangesmodsignal.h"
#include "Structes/enumSignals.h"

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
    AmplitudeModSignalUI *m_amplitudeModSignalUI;

    SetterModSignal m_setterModSignal;
    FreqRangesModSignal m_freqRangesModSignal;
    DurationRangesModSignal m_durationModSignal;
    AmplRangesModSignal m_amplRangeModSignal;

    std :: map <SIGNALS_MOD, QString> mapOfSignals;

    SIGNALS_MAIN :: SIGNALS_MAIN m_mainSignalType;

    void checkEverything();
    void setUI(const int &index);

private slots:
        void slot_checkedModul(const int &state);
        void slot_signalModChanged(const int &currentIndex);
        void slot_setDurationMod(const double &durationMod);
        void slot_frequencyChanged(const double &num);

public:
        void setMainSignalType(const int &index);
        void DecimationFrequencyChanged();
        void mainSignalParamChanged();
        void stopMovingSlider();

};


#endif // MODULATIONUI_H
