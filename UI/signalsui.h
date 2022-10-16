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
    void signal_signalValue(const double &value);
    void signal_signalType(const QPair<int, int> &signalType);
    void signal_signalFrequency(const double &frequency);
    void signal_signalDuration(const double &duration);

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


    double m_duration;
    double m_frequency;
    int m_sampleFrequency;
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



private slots:
    void slot_signalChanged(int currentIndex);
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
