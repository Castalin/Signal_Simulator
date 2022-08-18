#include "controlsettingsTwo.h"
#include <QStringList>
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>

ControlSettingsTwo::ControlSettingsTwo(QWidget *parent)
    : QWidget{parent}
{
    w_trigFrequanceBox = new QComboBox;
    w_trigFrequanceBox->addItems(QStringList{"1 kHz", "2 kHz", "3 kHz", "4 kHz"});

    w_trigOutBox = new QComboBox;
    w_trigOutBox->addItems(QStringList{"Enabled", "Disabled"});

    w_strobSizeBox = new QComboBox;
    w_strobSizeBox->addItems(QStringList{"A: 32  B: 2016", "A: 64  B: 1984", "A: 128 B: 1920", "A: 256 B: 1792"});


    QFormLayout *ctrSettingsForm = new QFormLayout;
    QGroupBox *ctrSettingsGroup = new QGroupBox(QString("Control Settings 2"));
    QGridLayout *ctrSettingsGrid = new QGridLayout;

    ctrSettingsForm->addWidget(ctrSettingsGroup);
    ctrSettingsGroup->setLayout(ctrSettingsGrid);

    ctrSettingsGrid->addWidget(new QLabel(QString("Trig Freq")),0, 0, 1, 1, Qt :: AlignBottom | Qt ::AlignCenter);
    ctrSettingsGrid->addWidget(new QLabel(QString("Trig Out")), 0, 1, 1, 1, Qt :: AlignCenter | Qt :: AlignBottom);
    ctrSettingsGrid->addWidget(new QLabel(QString("Strob Size")), 0, 2, 1, 1, Qt :: AlignBottom | Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_trigFrequanceBox, 1, 0, 1, 1, Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_trigOutBox, 1, 1, 1, 1, Qt :: AlignCenter);
    ctrSettingsGrid->addWidget(w_strobSizeBox, 1, 2, 1, 1, Qt :: AlignCenter);

    ctrSettingsGrid->setVerticalSpacing(12);
    ctrSettingsGrid->setHorizontalSpacing(14);


    this->setLayout(ctrSettingsForm);

}
