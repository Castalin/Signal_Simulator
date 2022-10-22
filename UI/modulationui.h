#ifndef MODULATIONUI_H
#define MODULATIONUI_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>
#include <QTimer>

class ModulationUI : public QWidget
{
    Q_OBJECT
public:
    explicit ModulationUI(QWidget *parent = nullptr);

signals:
    void signal_signalAmplitudeMod(const int &amplitude);
    void signal_signalType(const int &signalType);
    void signal_signalFrequencyMod(const double &frequency);
    void signal_signalDurationMod(const double &duration);

private:

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxMod;
    QComboBox *w_frequencySignalBoxMod;
    QDoubleSpinBox *w_frequencySignalNumMod;
    QComboBox *w_durationSignalBoxMod;
    QDoubleSpinBox *w_durationSignalNumMod;

    QSlider *w_levelSignalSliderMod;
    QLabel *w_levelSignalLabelMod;
    QPushButton *w_startSliderMod;
    QPushButton *w_stopSliderMod;
    QTimer *w_timerMod;

    double m_duration;
    double m_frequency;
    int m_decimation;

    enum FREQUENCY
    {
        kHz                 = 0,
        MHz                 = 1,
    };

    enum DURATION
    {
        ms                  = 0,
        us                  = 1,
        ns                  = 2,
    };

    enum SIGNALS
    {
        NO_SIGNAL           = 0,
        SINE                = 1,
        RECTANGLE           = 2,
    };

    SIGNALS m_mainSignalType;
    double m_frequencyMainSignal;
    double m_durationMainSignal;

private slots:
        void slot_checkedModul(const int &state);
        void slot_signalModulChanged(const int &currentIndex);
        void slot_startMovingSlider();
        void slot_timeOut();
        void slot_setFrequencyMod(const double &frequencyMod);
        void slot_setDurationMod(const double &durationMod);
        void slot_checkRangeFrequencyMod(const int &index);
        void slot_checkRangeDurationMod(const int &index);


public slots:
        void slot_stopMovingSlider();


public:
        void setDecimationFrequence(const int &decimation);
        void setFrequencyMainSignal(const double &frequency);
        void setDurationMainSignal(const double &duration);
        void setMainSignalType(const int &index);

};


#endif // MODULATIONUI_H
