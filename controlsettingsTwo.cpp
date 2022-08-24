#include "controlsettingsTwo.h"
#include <QStringList>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>

ControlSettingsTwo::ControlSettingsTwo(QWidget *parent)
    : QWidget{parent}
{
    w_trigFrequencyBox = new QComboBox;
    w_trigFrequencyBox->addItems(QStringList{"1 kHz", "2 kHz", "3 kHz", "4 kHz"});

    w_trigOutBox = new QComboBox;
    w_trigOutBox->addItems(QStringList{"Enabled", "Disabled"});

    w_strobeSizeBox = new QComboBox;
    w_strobeSizeBox->addItems(QStringList{"A: 32  B: 2016", "A: 64  B: 1984", "A: 128 B: 1920", "A: 256 B: 1792"});


    QFormLayout *ctrSettingsForm = new QFormLayout;
    QGroupBox *ctrSettingsGroup = new QGroupBox(QString("Control Settings 2"));
    QGridLayout *ctrSettingsGrid = new QGridLayout;

    ctrSettingsForm->addWidget(ctrSettingsGroup);
    ctrSettingsGroup->setLayout(ctrSettingsGrid);

    ctrSettingsGrid->addWidget(new QLabel(QString("Trig Freq")),0, 0, 1, 1, Qt :: AlignBottom | Qt ::AlignCenter);
    ctrSettingsGrid->addWidget(new QLabel(QString("Trig Out")), 0, 1, 1, 1, Qt :: AlignCenter | Qt :: AlignBottom);
    ctrSettingsGrid->addWidget(new QLabel(QString("Strob Size")), 0, 2, 1, 1, Qt :: AlignBottom | Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_trigFrequencyBox, 1, 0, 1, 1, Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_trigOutBox, 1, 1, 1, 1, Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_strobeSizeBox, 1, 2, 1, 1, Qt :: AlignCenter);

    ctrSettingsGrid->setVerticalSpacing(12);
    ctrSettingsGrid->setHorizontalSpacing(14);


    this->setLayout(ctrSettingsForm);
    // ui ends here
    m_frequencyScale = IntenernalStartSourceScale :: Frequency_1kHz;
    w_trigFrequencyBox->setCurrentIndex(static_cast<quint8>(m_frequencyScale));
    m_triggerOut = TriggerOut :: Enable;
    w_trigOutBox->setCurrentIndex(static_cast<quint8>(m_triggerOut));
    m_strobeSize = StrobeSize :: Strobe_A32_B2016;
    w_strobeSizeBox->setCurrentIndex(static_cast<quint8>(m_strobeSize));
}

void ControlSettingsTwo::slot_proccessingIncomingDataControl(const unsigned char &info)
{
    if ((info & 0b00000011) != static_cast<quint8>(m_frequencyScale))
    {
        m_frequencyScale = static_cast<IntenernalStartSourceScale>(info & 0b00000011);
        w_trigFrequencyBox->setCurrentIndex(static_cast<quint8>(m_frequencyScale));

    }

    if (((info & 0b00001000) >> 3) != static_cast<quint8>(m_triggerOut))
    {
        m_triggerOut = static_cast<TriggerOut>(((info & 0b00001000) >> 3));
        w_trigOutBox->setCurrentIndex(static_cast<quint8>(m_triggerOut));
    }

    if (((info & 0b01110000) >> 4) != static_cast<quint8>(m_strobeSize))
    {
        m_strobeSize = static_cast<StrobeSize>((info & 0b01110000) >> 4);
        w_strobeSizeBox->setCurrentIndex(static_cast<quint8>(m_strobeSize));
    }

}
