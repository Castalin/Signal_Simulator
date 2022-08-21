#include "controlsettingsOne.h"
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QSpacerItem>

ControlSettingsOne::ControlSettingsOne(QWidget *parent)
    : QWidget{parent}
{
    w_ADCRxBox = new QComboBox;
    w_ADCRxBox->addItems(QStringList{"Enabled", "Disabled"});

    w_clockSourceBox = new QComboBox;
    w_clockSourceBox->addItems(QStringList{"Internal", "External"});

    w_sampleFrequanceBox = new QComboBox;
    w_sampleFrequanceBox->addItems(QStringList{"80 MHz", "40 MHz", "20 MHz", "20 MHz", "5 MHz", "2500 kHz", "1125 kHz", "562.5 kHz"});

    w_trigFrequanceBox = new QComboBox;
    w_trigFrequanceBox->addItems(QStringList{"1 kHz", "2 kHz", "4 kHz", "8 kHz"});

    w_trigSrcBox = new QComboBox;
    w_trigSrcBox->addItems(QStringList{"Internal", "External"});

    w_testLED = new QCheckBox("Test LED");
    w_testLED->setCheckState(Qt :: Checked);

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
    ctrSettingsLayout->addWidget(w_sampleFrequanceBox, 1, 2, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(new QLabel(QString("Trig Freq")), 2, 0, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(new QLabel(QString("Trig Src")), 2, 1, 1, 1, Qt :: AlignHCenter | Qt::AlignBottom);
    ctrSettingsLayout->addWidget(w_testLED, 3, 2, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_trigFrequanceBox, 3, 0, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addWidget(w_trigSrcBox, 3, 1, 1, 1, Qt :: AlignCenter);
    ctrSettingsLayout->addItem(new QSpacerItem(0, 0, QSizePolicy :: Expanding), 4, 1, 1, 2);

    ctrSettingsLayout->setVerticalSpacing(10);
    ctrSettingsLayout->setHorizontalSpacing(12);

    this->setLayout(ctrSettingsForm);

}
