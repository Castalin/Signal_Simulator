#include "modulationui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>
#include <QLabel>
#include <cmath>

ModulationUI::ModulationUI(SignalVariables *const signalVariables, ModSignalVariables * const modSignalVariables, QWidget *parent)
    : QWidget{parent}, m_setterModSignal{modSignalVariables}, m_freqRangesModSignal{signalVariables, modSignalVariables}, m_durationModSignal{modSignalVariables}
{
    w_checkModulation = new QCheckBox(QString("Modulation"));
    w_checkModulation->setCheckable(true);

    w_signalsBoxMod = new QComboBox;
    w_signalsBoxMod->addItems(QStringList{"None", "Sine", "Rect"});
    w_signalsBoxMod->setEnabled(false);

    w_frequencySignalBoxMod = new QComboBox;
    w_frequencySignalBoxMod->addItems(QStringList{"kHz", "MHz"});
    w_frequencySignalBoxMod->setEnabled(false);

    w_frequencySignalNumMod = new QDoubleSpinBox;
    w_frequencySignalNumMod->setMinimum(0.0);
    w_frequencySignalNumMod->setDecimals(3);
    w_frequencySignalNumMod->setEnabled(false);

    w_durationSignalBoxMod = new QComboBox;
    w_durationSignalBoxMod->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBoxMod->setEnabled(false);

    w_durationSignalNumMod = new QDoubleSpinBox;
    w_durationSignalNumMod->setMinimum(0.0);
    w_durationSignalNumMod->setDecimals(3);
    w_durationSignalNumMod->setEnabled(false);


    QGridLayout *modulationGrid = new QGridLayout;

    modulationGrid->addWidget(w_checkModulation, 0, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(new QLabel(QString("Signal type")), 1, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Frequency")), 1, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Duration")), 1, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(w_signalsBoxMod, 2, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencySignalNumMod, 2, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencySignalBoxMod, 2, 2, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalNumMod, 2, 3, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalBoxMod, 2, 4, 1, 1, Qt :: AlignCenter);

    m_amplitudeModSignalUI = new AmplitudemodsignalUI(&m_setterModSignal);
    modulationGrid->addWidget(m_amplitudeModSignalUI, 3, 0, 2, 5);

    modulationGrid->setVerticalSpacing(10);
    modulationGrid->setHorizontalSpacing(5);

    QGroupBox *modulationGroup = new QGroupBox;
    modulationGroup->setLayout(modulationGrid);
    QFormLayout *mainForm = new QFormLayout;
    mainForm->addWidget(modulationGroup);

    this->setLayout(mainForm);
    m_freqRangesModSignal.setPtrToFreqSpinNum(w_frequencySignalNumMod);
    m_durationModSignal.setPtrToDurationSpinNum(w_durationSignalNumMod);
    m_mainSignalType = NO_SIGNAL;

    connect(w_checkModulation, &QCheckBox :: stateChanged, this, &ModulationUI :: slot_checkedModul);
    connect(w_signalsBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &ModulationUI :: slot_signalModChanged);

    connect(w_durationSignalNumMod, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &ModulationUI :: slot_setDurationMod);
    connect(w_frequencySignalNumMod, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged),
            this, [this](const double &modFrequency)->void{m_setterModSignal.setModFrequency(w_frequencySignalBoxMod->currentIndex(), modFrequency);});
    connect(w_frequencySignalBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged),
            this, [this](const int &index)->void{m_freqRangesModSignal.checkRangeFrequencyMod(index);});
    connect(w_durationSignalBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged),
            this, [this](const int &index)->void{m_durationModSignal.checkRangeDuration(index);});

    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
    m_durationModSignal.checkRangeDuration(w_durationSignalBoxMod->currentIndex());

}


void ModulationUI :: slot_checkedModul(const int &state)
{
    if (state == Qt :: Checked)
    {
        w_signalsBoxMod->setEnabled(true);
        slot_signalModChanged(w_signalsBoxMod->currentIndex());
        m_amplitudeModSignalUI->enable();
        emit signal_signalType(w_signalsBoxMod->currentIndex());
    }
    else
    {
        w_signalsBoxMod->setEnabled(false);
        w_frequencySignalBoxMod->setEnabled(false);
        w_frequencySignalNumMod->setEnabled(false);
        w_durationSignalBoxMod->setEnabled(false);
        w_durationSignalNumMod->setEnabled(false);
        m_amplitudeModSignalUI->disable();
        emit signal_signalType(SIGNALS :: NO_SIGNAL);
    }
}


void ModulationUI :: slot_signalModChanged(const int &currentIndex)
{
    emit signal_signalType(currentIndex);
    switch (currentIndex)
    {
        case SIGNALS :: NO_SIGNAL:
        {
            w_frequencySignalBoxMod->setEnabled(false);
            w_frequencySignalNumMod->setEnabled(false);
            w_durationSignalBoxMod->setEnabled(false);
            w_durationSignalNumMod->setEnabled(false);
            break;
        }
        case SIGNALS :: SINE:
        {
            w_frequencySignalBoxMod->setEnabled(true);
            w_frequencySignalNumMod->setEnabled(true);
            w_durationSignalBoxMod->setEnabled(false);
            w_durationSignalNumMod->setEnabled(false);
            break;
        }
        case SIGNALS :: RECTANGLE:
        {
            w_frequencySignalBoxMod->setEnabled(true);
            w_frequencySignalNumMod->setEnabled(true);
            w_durationSignalBoxMod->setEnabled(true);
            w_durationSignalNumMod->setEnabled(true);
            break;
        }
    };
    m_freqRangesModSignal.changeSetterForRange(QPair(m_mainSignalType, currentIndex));
    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}


void ModulationUI::slot_setDurationMod(const double &durationMod)
{
    m_setterModSignal.setModDuration(w_durationSignalBoxMod->currentIndex(), durationMod);
    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}

void ModulationUI::stopMovingSlider()
{
    if (w_checkModulation->isChecked() == true)
    {
        m_amplitudeModSignalUI->slot_stopMovingSlider();
    }
}

void ModulationUI::setMainSignalType(const int &index)
{
    m_mainSignalType = static_cast<SIGNALS>(index);
    m_freqRangesModSignal.changeSetterForRange(QPair(index, w_signalsBoxMod->currentIndex()));
    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}

void ModulationUI::DecimationFrequencyChanged()
{
    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
    m_durationModSignal.checkRangeDuration(w_durationSignalBoxMod->currentIndex());
}

void ModulationUI::mainSignalChanged()
{
    m_freqRangesModSignal.checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
    m_durationModSignal.checkRangeDuration(w_durationSignalBoxMod->currentIndex());
}

