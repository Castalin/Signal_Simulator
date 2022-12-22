#include "noiseui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>

NoiseUI::NoiseUI(NoiseVariables *const noiseVariables, QWidget *parent)
    : QWidget{parent}, m_setterNoise{noiseVariables}
{
    w_checkNoise = new QCheckBox(QString("Noise"));
    w_levelDispSlider = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelDispSlider->setMaximum(1000);
    w_levelDispSlider->setMinimum(0);
    w_levelDispLabel = new QLabel(QString("Disp: 0"));
    w_levelDispLabel->setToolTip(QString("Dispersion (Gauss noise)"));
    w_levelDispSlider->setEnabled(false);
    w_levelDispSlider->setSingleStep(1);
    w_levelDispLabel->setEnabled(false);

    QGridLayout *noiseLayout = new QGridLayout;

    noiseLayout->addWidget(w_checkNoise, 0, 0, 1, 1, Qt :: AlignLeft);
    noiseLayout->addWidget(w_levelDispSlider, 0, 1, 1, 3, Qt :: AlignCenter);
    noiseLayout->addWidget(w_levelDispLabel, 0, 4, 1, 1, Qt :: AlignRight);

    QGroupBox *noiseGroup = new QGroupBox(QString("Noise"));
    QFormLayout *noiseForm = new QFormLayout;

    noiseGroup->setLayout(noiseLayout);
    noiseForm->addWidget(noiseGroup);
    this->setLayout(noiseForm);


    connect(w_checkNoise, &QCheckBox :: stateChanged, this,  &NoiseUI :: slot_stateChanged);
    connect(w_levelDispSlider, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateLabel);
    connect(w_levelDispSlider, &QSlider :: valueChanged, this, [this](const int &num)->void{m_setterNoise.setDispersion(num / 10.0);});
}

void NoiseUI::slot_stateChanged(const int &state)
{
    emit signal_noiseState(state);
    if (Qt :: CheckState :: Checked == state)
    {
        w_levelDispSlider->setEnabled(true);
        w_levelDispLabel->setEnabled(true);
    }
    else
    {
        w_levelDispSlider->setEnabled(false);
        w_levelDispLabel->setEnabled(false);
    }    
}

void NoiseUI::slot_updateLabel(const int &value)
{
    w_levelDispLabel->setText(w_levelDispLabel->text().remove(6,  w_levelDispLabel->text().size()) + QString :: number(value / 10.0));

}


