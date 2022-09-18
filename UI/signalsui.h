#ifndef SIGNALSUI_H
#define SIGNALSUI_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>
#include <QLabel>

class SignalsUI : public QWidget
{
    Q_OBJECT
public:
    explicit SignalsUI(QWidget *parent = nullptr);

signals:
    void signal_setValue(const int &num);

private:
    QComboBox *w_signalsBox;
    QComboBox *w_frequencyBox;
    QDoubleSpinBox *w_frequencyNum;
    QComboBox *w_durationSignalBox;
    QDoubleSpinBox *w_durationSignalNum;

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxModul;
    QComboBox *w_frequencyBoxModul;
    QDoubleSpinBox *w_frequencyNumModul;
    QComboBox *w_durationSignalBoxModul;
    QDoubleSpinBox *w_durationSignalNumModul;

    QSlider *w_levelSignalSlider;
    QLabel *w_levelSignalLabel;
    QPushButton *w_startSlider;
    QPushButton *w_stopSlider;
    QTimer *w_timer;

    double m_duration;
    double m_frequency;
    int m_sampleFrequency;

    enum FREQUENCE
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



private slots:
    void slot_checkedModul(int state);
    void slot_signalChanged(int currentIndex);
    void slot_signalModulChanged(int currentIndex);
    void slot_startMovingSlider();
    void slot_timeOut();
    void slot_checkRangeFrequency(const int &index);
    void slot_checkRangeDuration(const int &index);
    void slot_setDuration(const double &value);
    void slot_setFrequency(const double &value);

public slots:
    void slot_stopMovingSlider();
    void slot_setDecimationFrequence(const int &value);




};

#endif // SIGNALSUI_H
