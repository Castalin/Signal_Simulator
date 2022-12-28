#include "noiseui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>

NoiseUI::NoiseUI(NoiseVariables *const noiseVariables, QWidget *parent)
    : QWidget{parent}, m_setterNoise{noiseVariables}
{
    w_checkNoiseChanel_1 = new QCheckBox(QString("Channel A"));
    w_levelDispSpin_1 = new QDoubleSpinBox;
    w_levelDispSpin_1->setMaximum(1000);
    w_levelDispSpin_1->setMinimum(0);
    w_levelDispSpin_1->setEnabled(false);
    w_levelDispSpin_1->setSingleStep(1);
    w_levelDispSpin_1->setEnabled(false);
    w_levelDispSpin_1->setDecimals(1);
    w_levelDispLabel_1 = new QLabel(QString("Disp: 0"));
    w_levelDispLabel_1->setToolTip(QString("Dispersion (Gauss noise)"));
    w_levelDispSlider_1 = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelDispSlider_1->setMaximum(1000);
    w_levelDispSlider_1->setMinimum(0);
    w_levelDispSlider_1->setEnabled(false);
    w_levelDispSlider_1->setSingleStep(1);


    w_checkNoiseChanel_2 = new QCheckBox(QString("Channel B"));
    w_levelDispSpin_2 = new QDoubleSpinBox;
    w_levelDispSpin_2->setMaximum(1000);
    w_levelDispSpin_2->setMinimum(0);
    w_levelDispSpin_2->setEnabled(false);
    w_levelDispSpin_2->setSingleStep(0.2);
    w_levelDispSpin_2->setEnabled(false);
    w_levelDispSpin_2->setDecimals(1);
    w_levelDispLabel_2 = new QLabel(QString("Disp: 0"));
    w_levelDispLabel_2->setToolTip(QString("Dispersion (Gauss noise)"));
    w_levelDispSlider_2 = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelDispSlider_2->setMaximum(1000);
    w_levelDispSlider_2->setMinimum(0);
    w_levelDispSlider_2->setEnabled(false);
    w_levelDispSlider_2->setSingleStep(1);

    w_checkSynchronize = new QCheckBox(QString("Synchronize"));

    QGridLayout *noiseLayout = new QGridLayout;

    noiseLayout->addWidget(w_checkSynchronize, 0, 0, 1, 1, Qt :: AlignLeft);
    noiseLayout->addWidget(w_checkNoiseChanel_1, 1, 0, 1, 1, Qt :: AlignLeft);
    noiseLayout->addWidget(w_levelDispSpin_1, 1, 1, 1, 1, Qt :: AlignRight);
    noiseLayout->addWidget(w_levelDispLabel_1, 1, 2, 1, 1, Qt :: AlignRight);
    noiseLayout->addWidget(w_levelDispSlider_1, 2, 0, 1, 3);

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);
    noiseLayout->addWidget(frame, 3, 0, 1, 3);

    noiseLayout->addWidget(w_checkNoiseChanel_2, 4, 0, 1, 1, Qt :: AlignLeft);
    noiseLayout->addWidget(w_levelDispSpin_2, 4, 1, 1, 1, Qt :: AlignRight);
    noiseLayout->addWidget(w_levelDispLabel_2, 4, 2, 1, 1, Qt :: AlignRight);
    noiseLayout->addWidget(w_levelDispSlider_2, 5, 0, 1, 3);


    noiseLayout->setVerticalSpacing(8);
    noiseLayout->setMargin(2);

    QGroupBox *noiseGroup = new QGroupBox(QString("Noise"));
    QFormLayout *noiseForm = new QFormLayout;

    noiseGroup->setLayout(noiseLayout);
    noiseForm->addWidget(noiseGroup);
    this->setLayout(noiseForm);


    connect(w_checkNoiseChanel_1, &QCheckBox :: stateChanged, this,  &NoiseUI :: slot_stateChanged_1);
    connect(w_levelDispSpin_1, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateLblSpin_1);
    connect(w_levelDispSlider_1, &QSlider :: valueChanged, this, &NoiseUI ::  slot_updateLblSlid_1);

    connect(w_checkNoiseChanel_2, &QCheckBox :: stateChanged, this,  &NoiseUI :: slot_stateChanged_2);
    connect(w_levelDispSpin_2, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateLblSpin_2);
    connect(w_levelDispSlider_2, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateLblSlid_2);

    connect(w_checkSynchronize, &QCheckBox :: stateChanged, this,  &NoiseUI :: slot_synchronize);
}

void NoiseUI::disconnectAll()
{
    disconnect(w_levelDispSlider_1, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateAll);
    disconnect(w_levelDispSlider_2, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateAll);
    disconnect(w_levelDispSpin_1, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateAll);
    disconnect(w_levelDispSpin_2, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateAll);
}

void NoiseUI::connectAll()
{
    connect(w_levelDispSlider_1, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateAll);
    connect(w_levelDispSlider_2, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateAll);
    connect(w_levelDispSpin_1, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateAll);
    connect(w_levelDispSpin_2, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &NoiseUI :: slot_updateAll);
}

void NoiseUI::slot_stateChanged_1(const int &state)
{
    emit signal_noiseState(QPair<int, int>(state, w_checkNoiseChanel_2->checkState()));
    if (Qt :: CheckState :: Checked == state)
    {
        w_levelDispSpin_1->setEnabled(true);
        w_levelDispLabel_1->setEnabled(true);
        w_levelDispSlider_1->setEnabled(true);

    }
    else
    {
        w_levelDispSpin_1->setEnabled(false);
        w_levelDispLabel_1->setEnabled(false);
        w_levelDispSlider_1->setEnabled(false);
    }
    slot_synchronize(w_checkSynchronize->checkState());
}

void NoiseUI::slot_stateChanged_2(const int &state)
{
    emit signal_noiseState(QPair<int, int>(w_checkNoiseChanel_1->checkState(), state));
    if (Qt :: CheckState :: Checked == state)
    {
        w_levelDispSpin_2->setEnabled(true);
        w_levelDispLabel_2->setEnabled(true);
        w_levelDispSlider_2->setEnabled(true);
    }
    else
    {
        w_levelDispSpin_2->setEnabled(false);
        w_levelDispLabel_2->setEnabled(false);
        w_levelDispSlider_2->setEnabled(false);
    }
    slot_synchronize(w_checkSynchronize->checkState());
}

void NoiseUI::slot_updateLblSlid_1(const double &value)
{
    slot_updateLblSpin_1(static_cast<double>(value));
    w_levelDispSpin_1->setValue(value);
}

void NoiseUI::slot_updateLblSpin_1(const double &value)
{
    w_levelDispLabel_1->setText(QString("Disp: ") + QString :: number(value));
    m_setterNoise.setDispChannel_1(value / 10.0);

    disconnect(w_levelDispSlider_1, &QSlider :: valueChanged, this, &NoiseUI ::  slot_updateLblSlid_1);
    w_levelDispSlider_1->setValue(value);
    connect(w_levelDispSlider_1, &QSlider :: valueChanged, this, &NoiseUI ::  slot_updateLblSlid_1);
}

void NoiseUI::slot_updateLblSpin_2(const double &value)
{
    w_levelDispLabel_2->setText(QString("Disp: ") + QString :: number(value));
    m_setterNoise.setDispChannel_2(value / 10.0);

    disconnect(w_levelDispSlider_2, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateLblSlid_2);
    w_levelDispSlider_2->setValue(value);
    connect(w_levelDispSlider_2, &QSlider :: valueChanged, this, &NoiseUI :: slot_updateLblSlid_2);
}

void NoiseUI::slot_updateLblSlid_2(const double &value)
{
    slot_updateLblSpin_2(static_cast<double>(value));
    w_levelDispSpin_2->setValue(value);
}

void NoiseUI::slot_updateAll(const double &value)
{
    disconnectAll();
    slot_updateLblSlid_1(value);
    slot_updateLblSlid_2(value);
    connectAll();

}


void NoiseUI::slot_synchronize(const int &state)
{
    if (state == Qt :: CheckState :: Checked && w_checkNoiseChanel_1->checkState() == Qt :: CheckState :: Checked && w_checkNoiseChanel_2->checkState() == Qt :: CheckState :: Checked)
    {
        connectAll();
    }
    else
    {
        disconnectAll();
    }

}


