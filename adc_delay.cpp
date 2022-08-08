#include "adc_delay.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>


ADC_Delay::ADC_Delay(QWidget *parent)
    : QWidget{parent}
{
    w_spinDelay_1 = new QSpinBox;
    w_spinDelay_1->setMinimum(0);
    w_spinDelay_2 = new QSpinBox;
    w_spinDelay_2->setMinimum(0);
    w_spinDelay_2->setEnabled(false);

    w_setDelay_1 = new QPushButton(QString("Set"));
    w_setDelay_2 = new QPushButton(QString("Set"));
    w_setDelay_2->setEnabled(false);

    w_checkSynchronize = new QCheckBox(QString("Synchronize"));
    w_checkSynchronize->setCheckState(Qt :: Checked);
    w_label_2 = new QLabel(QString("ADC"));
    w_label_2->setEnabled(false);

    QFormLayout *ADC_DelayForm = new QFormLayout;
    QGroupBox *ADC_DelayBox = new QGroupBox(QString("ADC Delay Settings"));
    QGridLayout *ADC_DelayLayout = new QGridLayout;

    ADC_DelayForm->addWidget(ADC_DelayBox);
    ADC_DelayBox->setLayout(ADC_DelayLayout);

    ADC_DelayLayout->addWidget(new QLabel(QString("ADC")), 0, 0, 1, 1, Qt :: AlignLeft);
    ADC_DelayLayout->addWidget(w_spinDelay_1, 0, 1, 1, 1);
    ADC_DelayLayout->addWidget(w_setDelay_1, 0, 2, 1, 1);
    ADC_DelayLayout->addWidget(w_label_2, 1, 0, 1, 1, Qt :: AlignLeft);
    ADC_DelayLayout->addWidget(w_spinDelay_2, 1, 1, 1, 1);
    ADC_DelayLayout->addWidget(w_setDelay_2, 1, 2, 1, 1);
    ADC_DelayLayout->addWidget(w_checkSynchronize, 2, 0, 1, 3, Qt :: AlignRight);

    this->setLayout(ADC_DelayForm);

    connect(w_checkSynchronize, &QCheckBox :: stateChanged, this, &ADC_Delay :: slot_SynchronizeChanged);


}



void ADC_Delay :: slot_SynchronizeChanged(int state)
{
    if (state == Qt :: Checked)
    {
        w_spinDelay_2->setEnabled(false);
        w_setDelay_2->setEnabled(false);
        w_label_2->setEnabled(false);
    }
    else
    {
        w_spinDelay_2->setEnabled(true);
        w_setDelay_2->setEnabled(true);
        w_label_2->setEnabled(true);
    }
}
