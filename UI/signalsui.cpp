#include "UI/signalsui.h"
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QTimer>


SignalsUI::SignalsUI(QWidget *parent)
    : QWidget{parent}
{
    m_duration = 0.0;
    m_frequency = 0.0;
    m_decimation = 80e6;
    w_signalsBox = new QComboBox;
    w_signalsBox->addItems(QStringList{"None", "Sine", "Rect"});

    w_frequencySignalBox = new QComboBox;
    w_frequencySignalBox->addItems(QStringList{"kHz", "MHz"});
    w_frequencySignalBox->setEnabled(false);

    w_frequencySignalNum = new QDoubleSpinBox;
    w_frequencySignalNum->setMinimum(0.0);
    w_frequencySignalNum->setMaximum(1000.0);
    w_frequencySignalNum->setDecimals(3);
    w_frequencySignalNum->setEnabled(false);

    w_durationSignalBox = new QComboBox;
    w_durationSignalBox->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBox->setEnabled(false);

    w_durationSignalNum = new QDoubleSpinBox;
    w_durationSignalNum->setMinimum(0.0);
    w_durationSignalNum->setMaximum(1000.0);
    w_durationSignalNum->setDecimals(3);
    w_durationSignalNum->setEnabled(false);


    w_levelSignalSlider = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSlider->setMaximum(100);
    w_levelSignalSlider->setMinimum(-100);
    w_levelSignalLabel = new QLabel(QString("0"));
    w_startSlider = new QPushButton(QString("Start"));
    w_stopSlider = new QPushButton(QString("Stop"));
    w_stopSlider->setEnabled(false);
    w_timer = new QTimer(this);

    QGridLayout *signalLayout = new QGridLayout();
    signalLayout->setVerticalSpacing(10);

    signalLayout->addWidget(new QLabel(QString("Signal type")), 0, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(new QLabel(QString("Frequency")), 0, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(new QLabel(QString("Duration")), 0, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(w_signalsBox, 1, 0, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequencySignalNum, 1, 1, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequencySignalBox, 1, 2, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalNum, 1, 3, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalBox, 1, 4, 1, 1, Qt :: AlignCenter);

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);
    signalLayout->addWidget(frame, 2, 0, 1, 5);
    signalLayout->addWidget(w_startSlider, 3, 0, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_stopSlider, 3, 1, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_levelSignalSlider, 3, 2, 1, 2);
    signalLayout->addWidget(w_levelSignalLabel, 3, 4, 1, 1, Qt :: AlignCenter);

    m_modulationUI= new ModulationUI;
    signalLayout->addWidget(m_modulationUI, 4, 0, 3, 5);


    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *signalGroup = new QGroupBox(QString("Signal settings"));


    signalGroup->setLayout(signalLayout);
    mainForm->addWidget(signalGroup);

    this->setLayout(mainForm);


    slot_checkRangeFrequency(w_frequencySignalBox->currentIndex());
    slot_checkRangeDuration(w_durationSignalBox->currentIndex());


    connect(w_signalsBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalChanged);

    // all about slider block
    connect(w_startSlider, &QPushButton :: clicked, this, &SignalsUI :: slot_startMovingSlider);
    connect(w_stopSlider, &QPushButton :: clicked, this, &SignalsUI :: slot_stopMovingSlider);
    connect(w_timer, &QTimer :: timeout, this, &SignalsUI :: slot_timeOut);
    connect(w_levelSignalSlider, &QSlider :: valueChanged, this, &SignalsUI :: signal_signalAmplitude);
    connect(w_levelSignalSlider, &QSlider :: valueChanged, w_levelSignalLabel, QOverload<int> :: of (&QLabel :: setNum));

    // about duration and frequency switchers
    connect(w_frequencySignalBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_checkRangeFrequency);
    connect(w_durationSignalBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_checkRangeDuration);
    connect(w_durationSignalNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &SignalsUI :: slot_setDuration);
    connect(w_frequencySignalNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &SignalsUI :: slot_setFrequency);

    // connects modulation info with signalData controller
    connect(m_modulationUI, &ModulationUI :: signal_signalType, this, [this](const int &ModType)->void{m_signalType.second = ModType; emit signal_signalType(m_signalType);});
    connect(m_modulationUI, &ModulationUI :: signal_signalAmplitudeMod, this, [this](const double &ampMod)->void{emit signal_signalAmplitudeMod(ampMod);});
    connect(m_modulationUI, &ModulationUI :: signal_signalDurationMod, this, [this](const double &durationMod)->void{emit signal_signalDurationMod(durationMod);});
    connect(m_modulationUI, &ModulationUI :: signal_signalFrequencyMod, this, [this](const double &frequencyMod)->void{emit signal_signalFrequencyMod(frequencyMod);});

}

void SignalsUI :: slot_signalChanged(const int &currentIndex)
{
    m_signalType.first = currentIndex;
    emit signal_signalType(m_signalType);
    m_modulationUI->setMainSignalType(currentIndex);

    switch (currentIndex)
    {
    case SIGNALS :: NO_SIGNAL:
    {
        w_frequencySignalBox->setEnabled(false);
        w_frequencySignalNum->setEnabled(false);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);
        break;
    }
    case SIGNALS :: SINE:
    {
        w_frequencySignalBox->setEnabled(true);
        w_frequencySignalNum->setEnabled(true);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);
        break;
    }
    case SIGNALS :: RECTANGLE:
    {
        w_frequencySignalBox->setEnabled(true);
        w_frequencySignalNum->setEnabled(true);
        w_durationSignalBox->setEnabled(true);
        w_durationSignalNum->setEnabled(true);
        break;
    }
    };
    slot_checkRangeFrequency(w_frequencySignalBox->currentIndex());
}

void SignalsUI::slot_startMovingSlider()
{
    w_levelSignalSlider->setEnabled(false);
    w_timer->start(std :: chrono :: milliseconds(100));
    w_startSlider->setEnabled(false);
    w_stopSlider->setEnabled(true);
}

void SignalsUI::slot_stopMovingSlider()
{
    w_timer->stop();
    w_startSlider->setEnabled(true);
    w_levelSignalSlider->setEnabled(true);
    w_stopSlider->setEnabled(false);


}

void SignalsUI::slot_stopMovingSliderOut()
{
    slot_stopMovingSlider();
    m_modulationUI->slot_stopMovingSlider();
}

void SignalsUI::slot_setDecimationFrequence(const int &decimation)
{
    m_decimation = decimation;
    slot_checkRangeFrequency(w_frequencySignalBox->currentIndex());
    slot_checkRangeDuration(w_durationSignalBox->currentIndex());
    m_modulationUI->setDecimationFrequence(decimation);
}

void SignalsUI::slot_timeOut()
{
    if (w_levelSignalSlider->value() != w_levelSignalSlider->maximum())
    {
        w_levelSignalSlider->setValue(w_levelSignalSlider->value() + 1);
    }
    else
    {
        w_levelSignalSlider->setValue(w_levelSignalSlider->minimum());
    }
}

void SignalsUI::slot_checkRangeFrequency(const int &index)
{
    switch(w_signalsBox->currentIndex())
    {
        case SIGNALS :: NO_SIGNAL : {return;};
        case SIGNALS :: SINE :
        {
            if (index == FREQUENCY :: kHz)
            {
                w_frequencySignalNum->setMaximum(static_cast<double>(m_decimation / 2e3));
                w_frequencySignalNum->setValue(m_frequency / 1e3);
                w_frequencySignalNum->setSingleStep(5.0);
                return;
            }
            else
            {
                w_frequencySignalNum->setValue(m_frequency / 1e6);
                w_frequencySignalNum->setMaximum(static_cast<double>(m_decimation / 2e6));
                w_frequencySignalNum->setSingleStep(0.5);
                return;
            }
        }
        case SIGNALS :: RECTANGLE :
        {
            if (index == FREQUENCY :: kHz)
            {
                w_frequencySignalNum->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e3);
                w_frequencySignalNum->setValue(m_frequency / 1e3);
                w_frequencySignalNum->setSingleStep(5.0);
                return;
            }
            else
            {
                w_frequencySignalNum->setValue(m_frequency / 1e6);
                w_frequencySignalNum->setMaximum(m_decimation / (m_duration * m_decimation + 2) / 1e6);
                w_frequencySignalNum->setSingleStep(0.5);
                return;
            }
        }
    }


}

void SignalsUI::slot_checkRangeDuration(const int &index)
{
    switch (index)
    {
        case DURATION :: ms:
        {
            w_durationSignalNum->setValue(m_duration * 1e3);
            w_durationSignalNum->setMaximum(1e3 * 255 / static_cast<double>(m_decimation));
            w_durationSignalNum->setSingleStep(0.001);
            return;
        }
        case DURATION :: us:
        {
            if (w_durationSignalNum->value() > m_duration * 1e6)
            {
                w_durationSignalNum->setValue(m_duration * 1e6);
                w_durationSignalNum->setMaximum(1e6 * 255 / static_cast<double>(m_decimation));

            }
            else
            {
                w_durationSignalNum->setMaximum(1e6 * 255 / static_cast<double>(m_decimation));
                w_durationSignalNum->setValue(m_duration * 1e6);
            }
            w_durationSignalNum->setSingleStep(0.1);
            return;
        }
        case DURATION :: ns:
        {
            w_durationSignalNum->setMaximum(1e9 * 255 / static_cast<double>(m_decimation));
            w_durationSignalNum->setValue(m_duration * 1e9);
            w_durationSignalNum->setSingleStep(10.0);
            return;
        }
    }
}

void SignalsUI::slot_setDuration(const double &value)
{
    switch (w_durationSignalBox->currentIndex())
    {
        case DURATION :: ms: {m_duration = value / 1e3; break;}
        case DURATION :: us: {m_duration = value / 1e6; break;}
        case DURATION :: ns: {m_duration = value / 1e9; break;}
    }
    slot_checkRangeFrequency(w_frequencySignalBox->currentIndex());
    m_modulationUI->setDurationMainSignal(m_duration);
    emit signal_signalDuration(m_duration);
}

void SignalsUI::slot_setFrequency(const double &value)
{
    if (w_frequencySignalBox->currentIndex() == FREQUENCY :: kHz)
    {
        m_frequency = value * 1e3;
    }
    else
    {
        m_frequency = value * 1e6;
    }
    emit signal_signalFrequency(m_frequency);
    m_modulationUI->setFrequencyMainSignal(m_frequency);
}


