#include "modulationui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>

ModulationUI::ModulationUI(QWidget *parent)
    : QWidget{parent}
{
    w_checkModulation = new QCheckBox(QString("Modulation"));
    w_checkModulation->setCheckable(true);

    w_signalsBoxModul = new QComboBox;
    w_signalsBoxModul->addItems(QStringList{"None", "Sine", "Rect"});
    w_signalsBoxModul->setEnabled(false);

    w_frequencyBoxModul = new QComboBox;
    w_frequencyBoxModul->addItems(QStringList{"kHz", "MHz"});
    w_frequencyBoxModul->setEnabled(false);

    w_frequencyNumModul = new QDoubleSpinBox;
    w_frequencyNumModul->setMinimum(0.0);
    w_frequencyNumModul->setMaximum(1000.0);
    w_frequencyNumModul->setDecimals(3);
    w_frequencyNumModul->setEnabled(false);

    w_durationSignalBoxModul = new QComboBox;
    w_durationSignalBoxModul->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBoxModul->setEnabled(false);

    w_durationSignalNumModul = new QDoubleSpinBox;
    w_durationSignalNumModul->setMinimum(0.0);
    w_durationSignalNumModul->setMaximum(1000.0);
    w_durationSignalNumModul->setDecimals(3);
    w_durationSignalNumModul->setEnabled(false);


    QGridLayout *modulationGrid = new QGridLayout;

    modulationGrid->addWidget(w_checkModulation, 0, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(new QLabel(QString("Signal type")), 1, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Frequency")), 1, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Duration")), 1, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(w_signalsBoxModul, 2, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyNumModul, 2, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyBoxModul, 2, 2, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalNumModul, 2, 3, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalBoxModul, 2, 4, 1, 1, Qt :: AlignCenter);

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);

    w_levelSignalSliderMod = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSliderMod->setMaximum(100);
    w_levelSignalSliderMod->setMinimum(-100);
    w_levelSignalLabelMod = new QLabel(QString("0"));
    w_startSliderMod = new QPushButton(QString("Start"));
    w_stopSliderMod = new QPushButton(QString("Stop"));
    w_stopSliderMod->setEnabled(false);
    w_timerMod = new QTimer(this);

    modulationGrid->addWidget(frame, 3, 0, 1, 5);
    modulationGrid->addWidget(w_startSliderMod, 4, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_stopSliderMod, 4, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_levelSignalSliderMod, 4, 2, 1, 2);
    modulationGrid->addWidget(w_levelSignalLabelMod, 4, 4, 1, 1, Qt :: AlignCenter);
    modulationGrid->setVerticalSpacing(10);
    modulationGrid->setHorizontalSpacing(5);

    QGroupBox *modulationGroup = new QGroupBox;
    modulationGroup->setLayout(modulationGrid);
    QFormLayout *mainForm = new QFormLayout;
    mainForm->addWidget(modulationGroup);

    this->setLayout(mainForm);

    connect(w_checkModulation, &QCheckBox :: stateChanged, this, &ModulationUI :: slot_checkedModul);
    connect(w_signalsBoxModul, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &ModulationUI :: slot_signalModulChanged);
}


void ModulationUI :: slot_checkedModul(int state)
{
    if (state == Qt :: Checked)
    {
        w_signalsBoxModul->setEnabled(true);
        slot_signalModulChanged(w_signalsBoxModul->currentIndex());
    }
    else
    {
        w_signalsBoxModul->setEnabled(false);
        w_frequencyBoxModul->setEnabled(false);
        w_frequencyNumModul->setEnabled(false);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);

    }
}


void ModulationUI :: slot_signalModulChanged(int currentIndex)
{
    emit signal_signalType(currentIndex);
    switch (currentIndex)
    {
    case 0:
    {
        w_frequencyBoxModul->setEnabled(false);
        w_frequencyNumModul->setEnabled(false);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);
        break;
    }
    case 1:
    {
        w_frequencyBoxModul->setEnabled(true);
        w_frequencyNumModul->setEnabled(true);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);
        break;
    }
    case 2:
    {
        w_frequencyBoxModul->setEnabled(true);
        w_frequencyNumModul->setEnabled(true);
        w_durationSignalBoxModul->setEnabled(true);
        w_durationSignalNumModul->setEnabled(true);
        break;
    }
    };
}
