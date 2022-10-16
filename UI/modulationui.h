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
    void signal_signalValue(const double &value);
    void signal_signalType(const int &signalType);
    void signal_signalFrequency(const double &frequency);
    void signal_signalDuration(const double &duration);

private:

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxModul;
    QComboBox *w_frequencyBoxModul;
    QDoubleSpinBox *w_frequencyNumModul;
    QComboBox *w_durationSignalBoxModul;
    QDoubleSpinBox *w_durationSignalNumModul;

    QSlider *w_levelSignalSliderMod;
    QLabel *w_levelSignalLabelMod;
    QPushButton *w_startSliderMod;
    QPushButton *w_stopSliderMod;
    QTimer *w_timerMod;

    double m_duration;
    double m_frequency;

private slots:
        void slot_checkedModul(int state);
        void slot_signalModulChanged(int currentIndex);

};


#endif // MODULATIONUI_H
