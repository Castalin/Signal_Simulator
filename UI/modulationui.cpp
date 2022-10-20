#include "modulationui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>

ModulationUI::ModulationUI(QWidget *parent)
    : QWidget{parent}
{
    w_checkModulation = new QCheckBox(QString("Modulation"));
    w_checkModulation->setCheckable(true);

    w_signalsBoxMod = new QComboBox;
    w_signalsBoxMod->addItems(QStringList{"None", "Sine", "Rect"});
    w_signalsBoxMod->setEnabled(false);

    w_frequencyBoxMod = new QComboBox;
    w_frequencyBoxMod->addItems(QStringList{"kHz", "MHz"});
    w_frequencyBoxMod->setEnabled(false);

    w_frequencyNumMod = new QDoubleSpinBox;
    w_frequencyNumMod->setMinimum(0.0);
    w_frequencyNumMod->setMaximum(4000.0);
    w_frequencyNumMod->setDecimals(3);
    w_frequencyNumMod->setEnabled(false);

    w_durationSignalBoxMod = new QComboBox;
    w_durationSignalBoxMod->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBoxMod->setEnabled(false);

    w_durationSignalNumMod = new QDoubleSpinBox;
    w_durationSignalNumMod->setMinimum(0.0);
    w_durationSignalNumMod->setMaximum(1000.0);
    w_durationSignalNumMod->setDecimals(3);
    w_durationSignalNumMod->setEnabled(false);


    QGridLayout *modulationGrid = new QGridLayout;

    modulationGrid->addWidget(w_checkModulation, 0, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(new QLabel(QString("Signal type")), 1, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Frequency")), 1, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Duration")), 1, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(w_signalsBoxMod, 2, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyNumMod, 2, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyBoxMod, 2, 2, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalNumMod, 2, 3, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalBoxMod, 2, 4, 1, 1, Qt :: AlignCenter);

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);

    w_levelSignalSliderMod = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSliderMod->setMaximum(100);
    w_levelSignalSliderMod->setMinimum(-100);
    w_levelSignalSliderMod->setEnabled(false);
    w_levelSignalLabelMod = new QLabel(QString("0"));
    w_startSliderMod = new QPushButton(QString("Start"));
    w_startSliderMod->setEnabled(false);
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
    connect(w_signalsBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &ModulationUI :: slot_signalModulChanged);

    connect(w_startSliderMod, &QPushButton :: clicked, this, &ModulationUI :: slot_startMovingSlider);
    connect(w_stopSliderMod, &QPushButton :: clicked, this, &ModulationUI :: slot_stopMovingSlider);
    connect(w_timerMod, &QTimer :: timeout, this, &ModulationUI :: slot_timeOut);
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, this, &ModulationUI :: signal_signalAmplitudeMod);
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, w_levelSignalLabelMod, QOverload<int> :: of (&QLabel :: setNum));
    connect(w_durationSignalNumMod, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &::ModulationUI::slot_setDurationMod);
    connect(w_frequencyNumMod, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &::ModulationUI::slot_setFrequencyMod);
    connect(w_frequencyBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &::ModulationUI::slot_checkRangeFrequencyMod);
    connect(w_durationSignalBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &::ModulationUI::slot_checkRangeDurationMod);

}


void ModulationUI :: slot_checkedModul(const int &state)
{
    if (state == Qt :: Checked)
    {
        w_signalsBoxMod->setEnabled(true);
        slot_signalModulChanged(w_signalsBoxMod->currentIndex());
        w_startSliderMod->setEnabled(true);
        w_levelSignalSliderMod->setEnabled(true);
    }
    else
    {
        w_signalsBoxMod->setEnabled(false);
        w_frequencyBoxMod->setEnabled(false);
        w_frequencyNumMod->setEnabled(false);
        w_durationSignalBoxMod->setEnabled(false);
        w_durationSignalNumMod->setEnabled(false);
        slot_stopMovingSlider();
        w_startSliderMod->setEnabled(false);
        w_levelSignalSliderMod->setEnabled(false);
        w_stopSliderMod->setEnabled(false);
    }
}


void ModulationUI :: slot_signalModulChanged(const int &currentIndex)
{
    emit signal_signalType(currentIndex);
    switch (static_cast<SIGNALS>(currentIndex))
    {
    case NO_SIGNAL:
    {
        w_frequencyBoxMod->setEnabled(false);
        w_frequencyNumMod->setEnabled(false);
        w_durationSignalBoxMod->setEnabled(false);
        w_durationSignalNumMod->setEnabled(false);
        break;
    }
    case SINE:
    {
        w_frequencyBoxMod->setEnabled(true);
        w_frequencyNumMod->setEnabled(true);
        w_durationSignalBoxMod->setEnabled(false);
        w_durationSignalNumMod->setEnabled(false);
        break;
    }
    case RECTANGLE:
    {
        w_frequencyBoxMod->setEnabled(true);
        w_frequencyNumMod->setEnabled(true);
        w_durationSignalBoxMod->setEnabled(true);
        w_durationSignalNumMod->setEnabled(true);
        break;
    }
    };
    slot_checkRangeFrequencyMod(w_frequencyBoxMod->currentIndex());
}


void ModulationUI::slot_startMovingSlider()
{
    w_levelSignalSliderMod->setEnabled(false);
    w_timerMod->start(std :: chrono :: milliseconds(100));
    w_startSliderMod->setEnabled(false);
    w_stopSliderMod->setEnabled(true);
}

void ModulationUI::slot_timeOut()
{
    if (w_levelSignalSliderMod->value() != w_levelSignalSliderMod->maximum())
    {
        w_levelSignalSliderMod->setValue(w_levelSignalSliderMod->value() + 1);
    }
    else
    {
        w_levelSignalSliderMod->setValue(w_levelSignalSliderMod->minimum());
    }
}

void ModulationUI::slot_setFrequencyMod(const double &frequencyMod)
{
    if (w_frequencyBoxMod->currentIndex() == FREQUENCY :: kHz)
    {
        m_frequency = frequencyMod * 1e3;
    }
    else
    {
        m_frequency = frequencyMod * 1e6;
    }
    emit signal_signalFrequencyMod(m_frequency);
}

void ModulationUI::slot_setDurationMod(const double &durationMod)
{
    switch (w_durationSignalBoxMod->currentIndex())
    {
        case DURATION :: ms: {m_duration = durationMod / 1e3; break;}
        case DURATION :: us: {m_duration = durationMod / 1e6; break;}
        case DURATION :: ns: {m_duration = durationMod / 1e9; break;}
    }
    emit signal_signalDurationMod(m_duration);
}

void ModulationUI::slot_checkRangeFrequencyMod(const int &index)
{
    if (w_durationSignalBoxMod->isEnabled() == 0 || m_duration == 0)
    {
        if (index == FREQUENCY :: kHz)
        {
            //w_frequencyNum->setMaximum(static_cast<double>(m_sampleFrequency / 2e3));
            w_frequencyNumMod->setValue(m_frequency / 1e3);
        }
        else
        {
            //w_frequencyNum->setMaximum(static_cast<double>(m_sampleFrequency / 2e6));
            w_frequencyNumMod->setValue(m_frequency / 1e6);

        }
    }
    else
    {
        if (index == FREQUENCY :: kHz)
        {
            //w_frequencyNum->setMaximum(m_sampleFrequency / (m_duration * m_sampleFrequency + 2) / 1e3);
            w_frequencyNumMod->setValue(m_frequency / 1e3);
        }
        else
        {
            //->setMaximum(m_sampleFrequency / (m_duration * m_sampleFrequency + 2) / 1e6);
            w_frequencyNumMod->setValue(m_frequency / 1e6);
        }
    }
}

void ModulationUI::slot_checkRangeDurationMod(const int &index)
{
    switch (index)
    {
        case DURATION :: ms:
        {
            w_durationSignalNumMod->setMaximum(1e3 * 511 / static_cast<double>(m_decimation));
            w_durationSignalNumMod->setValue(m_duration * 1e3);
            return;
        }
        case DURATION :: us:
        {
            w_durationSignalNumMod->setMaximum(1e6 * 511 / static_cast<double>(m_decimation));
            w_durationSignalNumMod->setValue(m_duration * 1e6);
            return;
        }
        case DURATION :: ns:
        {
            w_durationSignalNumMod->setMaximum(1e9 * 511 / static_cast<double>(m_decimation));
            w_durationSignalNumMod->setValue(m_duration * 1e9);
            return;
        }
    }
}

void ModulationUI::slot_stopMovingSlider()
{
    w_timerMod->stop();
    w_startSliderMod->setEnabled(true);
    w_levelSignalSliderMod->setEnabled(true);
    w_stopSliderMod->setEnabled(false);
}



void ModulationUI::setDecimationFrequence(const int &decimation)
{
    m_decimation = decimation;
    slot_checkRangeFrequencyMod(w_frequencyBoxMod->currentIndex());
    slot_checkRangeDurationMod(w_durationSignalBoxMod->currentIndex());
}

void ModulationUI::setFrequencyMainSignal(const double &frequency)
{
    m_frequencyMainsignal = frequency;
    slot_checkRangeFrequencyMod(w_frequencyBoxMod->currentIndex());
    slot_checkRangeDurationMod(w_durationSignalBoxMod->currentIndex());
}

void ModulationUI::setMainSignalType(const int &index)
{
    mainSignalType = static_cast<SIGNALS>(index);
    slot_checkRangeFrequencyMod(w_frequencyBoxMod->currentIndex());
    slot_checkRangeDurationMod(w_durationSignalBoxMod->currentIndex());
}

