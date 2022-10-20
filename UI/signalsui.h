#ifndef SIGNALSUI_H
#define SIGNALSUI_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>
#include "modulationui.h"

class SignalsUI : public QWidget
{
    Q_OBJECT
public:
    explicit SignalsUI(QWidget *parent = nullptr);

signals:
    void signal_signalAmplitude(const double &value);
    void signal_signalType(const QPair<int, int> &signalType);
    void signal_signalFrequency(const double &frequency);
    void signal_signalDuration(const double &duration);
    void signal_signalAmplitudeMod(const double &value);
    void signal_signalFrequencyMod(const double &frequency);
    void signal_signalDurationMod(const double &duration);

private:
    QComboBox *w_signalsBox;
    QComboBox *w_frequencyBox;
    QDoubleSpinBox *w_frequencyNum;
    QComboBox *w_durationSignalBox;
    QDoubleSpinBox *w_durationSignalNum;

    QSlider *w_levelSignalSlider;
    QLabel *w_levelSignalLabel;
    QPushButton *w_startSlider;
    QPushButton *w_stopSlider;
    QTimer *w_timer;

    ModulationUI *m_modulationUI;

    double m_duration;
    double m_frequency;
    int m_decimation;
    QPair<int, int> m_signalType;

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


private slots:
    void slot_signalChanged(const int &currentIndex);
    void slot_startMovingSlider();
    void slot_timeOut();
    void slot_checkRangeFrequency(const int &index);
    void slot_checkRangeDuration(const int &index);
    void slot_setDuration(const double &value);
    void slot_setFrequency(const double &value);
    void slot_stopMovingSlider();

public slots:
    void slot_stopMovingSliderOut();
    void slot_setDecimationFrequence(const int &decimation);




};

#endif // SIGNALSUI_H
