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
    QComboBox *w_frequanceBox;
    QSpinBox *w_frequanceNum;
    QComboBox *w_durationSignalBox;
    QSpinBox *w_durationSignalNum;

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxModul;
    QComboBox *w_frequanceBoxModul;
    QSpinBox *w_frequanceNumModul;
    QComboBox *w_durationSignalBoxModul;
    QSpinBox *w_durationSignalNumModul;

    QSlider *w_levelSignalSlider;
    QLabel *w_levelSignalLabel;
    QPushButton *w_startSlider;
    QPushButton *w_stopSlider;
    QTimer *w_timer;




private slots:
    void slot_checkedModul(int state);
    void slot_signalChanged(int currentIndex);
    void slot_signalModulChanged(int currentIndex);

    void slot_startMovingSlider();
    void slot_stopMovingSlider();
    void slot_timeOut();





};

#endif // SIGNALSUI_H
