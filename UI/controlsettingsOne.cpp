#include "UI/controlsettingsOne.h"
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSpacerItem>

ControlSettingsOne::ControlSettingsOne(QWidget *parent)
    : QWidget{parent}
{
    w_ADCRxBox = new QComboBox;
    w_ADCRxBox->addItems(QStringList{"Disabled","Enabled"});

    w_clockSourceBox = new QComboBox;
    w_clockSourceBox->addItems(QStringList{"Internal", "External"});

    w_sampleFrequencyBox = new QComboBox;
    w_sampleFrequencyBox->addItems(QStringList{"80 MHz", "40 MHz", "20 MHz", "20 MHz", "5 MHz", "2500 kHz", "1125 kHz", "562.5 kHz"});

    w_trigFrequencyBox = new QComboBox;
    w_trigFrequencyBox->addItems(QStringList{"1 kHz", "2 kHz"});

    w_trigSrcBox = new QComboBox;
    w_trigSrcBox->addItems(QStringList{"Internal", "External"});

    w_testLED = new QCheckBox("Test LED");
    w_testLED->setCheckState(Qt :: Checked);
    m_LED = true;

    QFormLayout *ctrSettingsForm = new QFormLayout;
    QGroupBox *ctrSettingsGroup = new QGroupBox(QString("Control Settings"));
    QGridLayout *ctrSettingsLayout = new QGridLayout;

    ctrSettingsForm->addWidget(ctrSettingsGroup);
    ctrSettingsGroup->setLayout(ctrSettingsLayout);

    ctrSettingsLayout->addWidget(new QLabel(QString("ADC Rx")), 0, 0, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(new QLabel(QString("Clock Source")), 0, 1, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(new QLabel(QString("Sample Freq")), 0, 2, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(w_ADCRxBox, 1, 0, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_clockSourceBox, 1, 1, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_sampleFrequencyBox, 1, 2, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(new QLabel(QString("Trig Freq")), 2, 0, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(new QLabel(QString("Trig Src")), 2, 1, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(w_testLED, 3, 2, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_trigFrequencyBox, 3, 0, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_trigSrcBox, 3, 1, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addItem(new QSpacerItem(0, 0, QSizePolicy :: Expanding), 4, 1, 1, 2);

    ctrSettingsLayout->setVerticalSpacing(10);
    ctrSettingsLayout->setHorizontalSpacing(12);

    this->setLayout(ctrSettingsForm);

    // ui ends here

    m_rxEnable = RxEnable :: DISABLED;
    w_ADCRxBox->setCurrentIndex(static_cast<quint8>(m_rxEnable));
    m_clockSignalSource = ClockSignalSource :: INTERNAL;
    w_clockSourceBox->setCurrentIndex(static_cast<quint8>(m_clockSignalSource));
    m_decimation = SignalDecimation :: DecimationBy1;
    w_sampleFrequencyBox->setCurrentIndex(static_cast<quint8>(m_decimation));
    m_frequencyScale = IntenernalStartSourceScale :: Frequency_1kHz;
    w_trigFrequencyBox->setCurrentIndex(static_cast<quint8>(m_frequencyScale));
    m_startSignalSource = StartSignalSource :: INTERNAL;
    w_trigSrcBox->setCurrentIndex(static_cast<quint8>(m_startSignalSource));

}

void ControlSettingsOne::slot_processingIncomingDataControl(const unsigned char &info)
{
    if ((info & 0b00000001) != static_cast<quint8>(m_rxEnable))
    {
        m_rxEnable = static_cast<RxEnable>(info & 0b00000001);
        w_ADCRxBox->setCurrentIndex(static_cast<quint8>(m_rxEnable));

    }

    if (((info & 0b00000010) >> 1) != static_cast<quint8>(m_clockSignalSource))
    {
        m_clockSignalSource = static_cast<ClockSignalSource>(((info & 0b00000010) >> 1));
        w_clockSourceBox->setCurrentIndex(static_cast<quint8>(m_clockSignalSource));
    }

    if (((info & 0b00111000) >> 3) != static_cast<quint8>(m_decimation))
    {
        m_decimation = static_cast<SignalDecimation>((info & 0b00111000) >> 3);
        w_sampleFrequencyBox->setCurrentIndex(static_cast<quint8>(m_decimation));
    }

    if (((info & 0b01000000) << 2) != static_cast<quint8>(m_frequencyScale))
    {
        m_frequencyScale = static_cast<IntenernalStartSourceScale>((info & 0b01000000) << 2);
        w_trigFrequencyBox->setCurrentIndex(static_cast<quint8>(m_frequencyScale));
    }

    if (((info & 0b10000000) << 1) != static_cast<quint8>(m_startSignalSource))
    {
        m_startSignalSource = static_cast<StartSignalSource>((info & 0b10000000) << 1);
        w_trigSrcBox->setCurrentIndex(static_cast<quint8>(m_startSignalSource));
    }
     // the second bit is used for test ADC
}


void ControlSettingsOne::slot_processingIncomingDataLED(const unsigned char &info)
{
    if ((info & 0b00000001) == true)
    {
        w_testLED->setCheckState(Qt :: Checked);
        m_LED = true;
    }
    else
    {
        w_testLED->setCheckState(Qt :: CheckState :: Unchecked);
        m_LED = false;
    }
}
