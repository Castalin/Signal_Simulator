#include "adc_delay.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>


ADCDelay::ADCDelay(QWidget *parent)
    : QWidget{parent}
{
    w_spinDelay_1 = new QSpinBox;
    w_spinDelay_1->setMinimum(0);
    w_spinDelay_2 = new QSpinBox;
    w_spinDelay_2->setMinimum(0);
    w_spinDelay_2->setEnabled(false);


    w_checkSynchronize = new QCheckBox(QString("Synchronize"));
    w_checkSynchronize->setCheckState(Qt :: Checked);
    w_label_2 = new QLabel(QString("ADC"));
    w_label_2->setEnabled(false);

    QFormLayout *ADC_DelayForm = new QFormLayout;
    QGroupBox *ADC_DelayBox = new QGroupBox(QString("ADC Delay Settings"));
    QGridLayout *ADC_DelayLayout = new QGridLayout;

    ADC_DelayForm->addWidget(ADC_DelayBox);
    ADC_DelayBox->setLayout(ADC_DelayLayout);

    ADC_DelayLayout->addWidget(new QLabel(QString("ADC")), 0, 0, 1, 1);
    ADC_DelayLayout->addWidget(w_spinDelay_1, 0, 1, 1, 1);
    ADC_DelayLayout->addWidget(w_label_2, 1, 0, 1, 1);
    ADC_DelayLayout->addWidget(w_spinDelay_2, 1, 1, 1, 1);
    ADC_DelayLayout->addWidget(w_checkSynchronize, 1, 2, 1, 1, Qt :: AlignRight);

    this->setLayout(ADC_DelayForm);

    connect(w_checkSynchronize, &QCheckBox :: stateChanged, this, &ADCDelay :: slot_SynchronizeChanged);

    m_delay[0] = 0x0000;
    m_delay[0] = 0x0000;
    m_firstByteReceived_A = false;
    m_firstByteReceived_B = false;

}



void ADCDelay :: slot_SynchronizeChanged(int state)
{
    if (state == Qt :: Checked)
    {
        w_spinDelay_2->setEnabled(false);
        w_label_2->setEnabled(false);
    }
    else
    {
        w_spinDelay_2->setEnabled(true);
        w_label_2->setEnabled(true);
    }
}

void ADCDelay::slot_proccessingADC_A_DELAY_0(const unsigned char &info)
{
    m_firstByteReceived_A = true;
    m_delay[0] = static_cast<quint16>(info);
}

void ADCDelay::slot_proccessingADC_A_DELAY_1(const unsigned char &info)
{
    if (m_firstByteReceived_A == true)
    {
        m_delay[0] += (static_cast<quint16>(info) << 8);
        m_firstByteReceived_A = false;
        w_spinDelay_1->setValue(m_delay[0]);
    }

}

void ADCDelay::slot_proccessingADC_B_DELAY_0(const unsigned char &info)
{
    m_firstByteReceived_B = true;
    m_delay[1] = static_cast<quint16>(info);
}

void ADCDelay::slot_proccessingADC_B_DELAY_1(const unsigned char &info)
{
    if (m_firstByteReceived_B == true)
    {
        m_delay[1] += (static_cast<quint16>(info) << 8);
        m_firstByteReceived_B = false;
        w_spinDelay_2->setValue(m_delay[1]);
    }
}


