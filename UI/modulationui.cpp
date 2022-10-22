#include "modulationui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>

ModulationUI::ModulationUI(QWidget *parent)
    : QWidget{parent}
{
    m_duration = 0.0;
    m_frequency = 0.0;
    m_frequencyMainSignal = 0.0;
    m_durationMainSignal = 0.0;
    m_decimation = 80e6;
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
    connect(w_frequencySignalNumMod, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &::ModulationUI::slot_setFrequencyMod);
    connect(w_frequencySignalBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &::ModulationUI::slot_checkRangeFrequencyMod);
    connect(w_durationSignalBoxMod, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &::ModulationUI::slot_checkRangeDurationMod);

    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
    slot_checkRangeDurationMod(w_durationSignalBoxMod->currentIndex());
}


void ModulationUI :: slot_checkedModul(const int &state)
{
    if (state == Qt :: Checked)
    {
        w_signalsBoxMod->setEnabled(true);
        slot_signalModulChanged(w_signalsBoxMod->currentIndex());
        w_startSliderMod->setEnabled(true);
        w_levelSignalSliderMod->setEnabled(true);
        emit signal_signalType(w_signalsBoxMod->currentIndex());
    }
    else
    {
        w_signalsBoxMod->setEnabled(false);
        w_frequencySignalBoxMod->setEnabled(false);
        w_frequencySignalNumMod->setEnabled(false);
        w_durationSignalBoxMod->setEnabled(false);
        w_durationSignalNumMod->setEnabled(false);
        slot_stopMovingSlider();
        w_startSliderMod->setEnabled(false);
        w_levelSignalSliderMod->setEnabled(false);
        w_stopSliderMod->setEnabled(false);
        emit signal_signalType(SIGNALS :: NO_SIGNAL);

    }
}


void ModulationUI :: slot_signalModulChanged(const int &currentIndex)
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
    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
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
    if (w_frequencySignalBoxMod->currentIndex() == FREQUENCY :: kHz)
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
    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}

void ModulationUI::slot_checkRangeFrequencyMod(const int &index)
{
    switch(m_mainSignalType)
    {
        case SIGNALS :: NO_SIGNAL:
        {
            switch(w_signalsBoxMod->currentIndex())
            {
            case SIGNALS :: NO_SIGNAL : {return;};
            case SIGNALS :: SINE :
                {
                    if (index == FREQUENCY :: kHz)
                    {
                        w_frequencySignalNumMod->setMaximum(static_cast<double>(m_decimation / 2e3));
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                        w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                        w_frequencySignalNumMod->setMaximum(static_cast<double>(m_decimation / 2e6));
                        w_frequencySignalNumMod->setSingleStep(0.5);
                        return;
                    }
                }
            case SIGNALS :: RECTANGLE :
                {
                    if (index == FREQUENCY :: kHz)
                    {
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e3);
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                        w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e6);
                        w_frequencySignalNumMod->setSingleStep(0.5);
                        return;
                    }
                }
            default : return;
            }
        }
        case SIGNALS :: SINE:
        {
            switch(w_signalsBoxMod->currentIndex())
            {
                case SIGNALS :: NO_SIGNAL : {return;};
                case SIGNALS :: SINE :
                {
                    if (index == FREQUENCY :: kHz)
                    {
                        w_frequencySignalNumMod->setMaximum(static_cast<double>(((m_decimation / 2) - m_frequencyMainSignal) / 1e3));
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                        w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                        w_frequencySignalNumMod->setMaximum(static_cast<double>(((m_decimation / 2) - m_frequencyMainSignal) / 1e6));
                        w_frequencySignalNumMod->setSingleStep(0.5);
                        return;
                    }
                }
                case SIGNALS :: RECTANGLE :
                {
                    if (index == FREQUENCY :: kHz)
                    {
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e3);
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                        w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e6);
                        w_frequencySignalNumMod->setSingleStep(0.5);
                        return;
                    }
                }
                default : return;
            }
        }
        case SIGNALS :: RECTANGLE:
        {
            switch(w_signalsBoxMod->currentIndex())
            {
                case SIGNALS :: NO_SIGNAL : {return;};
                case SIGNALS :: SINE :
                {
                    if (m_durationMainSignal == 0.0)
                    {
                        return;
                    }
                    if (index == FREQUENCY :: kHz)
                    {     
                        w_frequencySignalNumMod->setMaximum(static_cast<double>(((m_decimation / 2) - 2 / m_durationMainSignal) / 1e3));
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                       w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                       w_frequencySignalNumMod->setMaximum(static_cast<double>(((m_decimation / 2) - 2 / m_durationMainSignal) / 1e6));
                       w_frequencySignalNumMod->setSingleStep(0.5);
                       return;
                    }
                }
                case SIGNALS :: RECTANGLE :
                {
                    if (index == FREQUENCY :: kHz)
                    {
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e3);
                        w_frequencySignalNumMod->setValue(m_frequency / 1e3);
                        w_frequencySignalNumMod->setSingleStep(5.0);
                        return;
                    }
                    else
                    {
                        w_frequencySignalNumMod->setValue(m_frequency / 1e6);
                        w_frequencySignalNumMod->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e6);
                        w_frequencySignalNumMod->setSingleStep(0.5);
                        return;
                    }
                }
            }
            default : return;
        }
    }
}

void ModulationUI::slot_checkRangeDurationMod(const int &index)
{
    switch (index)
    {
        case DURATION :: ms:
        {
            w_durationSignalNumMod->setValue(m_duration * 1e3);
            w_durationSignalNumMod->setMaximum(1e3 * 255 / static_cast<double>(m_decimation));
            w_durationSignalNumMod->setSingleStep(0.001);
            return;
        }
        case DURATION :: us:
        {
            if (w_durationSignalNumMod->value() > m_duration * 1e6)
            {
                w_durationSignalNumMod->setValue(m_duration * 1e6);
                w_durationSignalNumMod->setMaximum(1e6 * 255 / static_cast<double>(m_decimation));

            }
            else
            {
                w_durationSignalNumMod->setMaximum(1e6 * 255 / static_cast<double>(m_decimation));
                w_durationSignalNumMod->setValue(m_duration * 1e6);
            }
            w_durationSignalNumMod->setSingleStep(0.1);
            return;
        }
        case DURATION :: ns:
        {
            w_durationSignalNumMod->setMaximum(1e9 * 255 / static_cast<double>(m_decimation));
            w_durationSignalNumMod->setValue(m_duration * 1e9);
            w_durationSignalNumMod->setSingleStep(10.0);
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
    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
    slot_checkRangeDurationMod(w_durationSignalBoxMod->currentIndex());
}

void ModulationUI::setFrequencyMainSignal(const double &frequency)
{
    m_frequencyMainSignal = frequency;
    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}

void ModulationUI::setDurationMainSignal(const double &duration)
{
    m_durationMainSignal = duration;
}

void ModulationUI::setMainSignalType(const int &index)
{
    m_mainSignalType = static_cast<SIGNALS>(index);
    slot_checkRangeFrequencyMod(w_frequencySignalBoxMod->currentIndex());
}

