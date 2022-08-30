#ifndef SIGNALSUI_H
#define SIGNALSUI_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>

class SignalsUI : public QWidget
{
    Q_OBJECT
public:
    explicit SignalsUI(QWidget *parent = nullptr);

signals:
    void signal_sendData(const int &num);

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

    QPushButton *w_setSignalSettings;
    QTimer *m_externalTimer;
    QTimer *m_internalTimer;
    int m_counter;



private slots:
    void slot_checkedModul(int state);
    void slot_signalChanged(int currentIndex);
    void slot_signalModulChanged(int currentIndex);

public slots:
    void slot_signalSendData();
    void slot_RxEnableValueChanged(const unsigned char &rxEnable);




};

#endif // SIGNALSUI_H
