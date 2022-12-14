#ifndef ADC_DELAY_H
#define ADC_DELAY_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>

class ADCDelay : public QWidget
{
    Q_OBJECT
public:
    explicit ADCDelay(QWidget *parent = nullptr);

signals:

private:
    QSpinBox *w_spinDelay_1;
    QSpinBox *w_spinDelay_2;

    quint16 m_delay[2]; // 0 for A chanel, 1 for B chanel
    bool m_firstByteReceived_A;
    bool m_firstByteReceived_B;


private slots:


public slots:
    void slot_proccessingADC_A_DELAY_0(const unsigned char &info);
    void slot_proccessingADC_A_DELAY_1(const unsigned char &info);
    void slot_proccessingADC_B_DELAY_0(const unsigned char &info);
    void slot_proccessingADC_B_DELAY_1(const unsigned char &info);

};

#endif // ADC_DELAY_H
