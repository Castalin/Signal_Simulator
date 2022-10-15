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
    m_sampleFrequency = 80e6;
    w_signalsBox = new QComboBox;
    w_signalsBox->addItems(QStringList{"None", "Sine", "Rect"});

    w_frequencyBox = new QComboBox;
    w_frequencyBox->addItems(QStringList{"kHz", "MHz"});
    w_frequencyBox->setEnabled(false);

    w_frequencyNum = new QDoubleSpinBox;
    w_frequencyNum->setMinimum(0.0);
    w_frequencyNum->setMaximum(1000.0);
    w_frequencyNum->setDecimals(3);
    w_frequencyNum->setEnabled(false);

    w_durationSignalBox = new QComboBox;
    w_durationSignalBox->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBox->setEnabled(false);

    w_durationSignalNum = new QDoubleSpinBox;
    w_durationSignalNum->setMinimum(0.0);
    w_durationSignalNum->setMaximum(1000.0);
    w_durationSignalNum->setDecimals(3);
    w_durationSignalNum->setEnabled(false);

    w_checkModulation = new QCheckBox(QString("Modulation"));
    w_checkModulation->setCheckable(true);

    w_signalsBoxModul = new QComboBox;
    w_signalsBoxModul->addItems(QStringList{"None", "Sine", "Rect"});
    w_signalsBoxModul->setEnabled(false);

    w_frequencyBoxModul = new QComboBox;
    w_frequencyBoxModul->addItems(QStringList{"Hz", "kHz", "MHz"});
    w_frequencyBoxModul->setEnabled(false);

    w_frequencyNumModul = new QDoubleSpinBox;
    w_frequencyNumModul->setMinimum(0.0);
    w_frequencyNumModul->setMaximum(1000.0);
    w_frequencyNumModul->setEnabled(false);

    w_durationSignalBoxModul = new QComboBox;
    w_durationSignalBoxModul->addItems(QStringList{"ms", "us", "ns"});
    w_durationSignalBoxModul->setEnabled(false);

    w_durationSignalNumModul = new QDoubleSpinBox;
    w_durationSignalNumModul->setMinimum(0.0);
    w_durationSignalNumModul->setMaximum(1000.0);
    w_durationSignalNumModul->setEnabled(false);

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
    signalLayout->addWidget(new QLabel(QString("Frequance")), 0, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(new QLabel(QString("Duration")), 0, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(w_signalsBox, 1, 0, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequencyNum, 1, 1, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequencyBox, 1, 2, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalNum, 1, 3, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalBox, 1, 4, 1, 1, Qt :: AlignCenter);


    QGridLayout *modulationGrid = new QGridLayout;
    QGroupBox *modulationGroup = new QGroupBox;
    modulationGroup->setLayout(modulationGrid);

    modulationGrid->addWidget(w_checkModulation, 0, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(new QLabel(QString("Signal type")), 1, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Frequance")), 1, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Duration")), 1, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(w_signalsBoxModul, 2, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyNumModul, 2, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequencyBoxModul, 2, 2, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalNumModul, 2, 3, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalBoxModul, 2, 4, 1, 1, Qt :: AlignCenter);


    signalLayout->addWidget(modulationGroup, 2, 0, 3, 5);
    signalLayout->addWidget(w_startSlider, 5, 0, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_stopSlider, 5, 1, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_levelSignalSlider, 5, 2, 1, 2);
    signalLayout->addWidget(w_levelSignalLabel, 5, 4, 1, 1, Qt :: AlignCenter);


    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *signalGroup = new QGroupBox(QString("Signal settings"));


    signalGroup->setLayout(signalLayout);
    mainForm->addWidget(signalGroup);

    slot_checkRangeFrequency(w_frequencyBox->currentIndex());
    slot_checkRangeDuration(w_durationSignalBox->currentIndex());

    this->setLayout(mainForm);

    connect(w_checkModulation, &QCheckBox :: stateChanged, this, &SignalsUI :: slot_checkedModul);
    connect(w_signalsBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalChanged);
    connect(w_signalsBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: signal_signalType);
    connect(w_signalsBoxModul, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalModulChanged);

    // all about slider block
    connect(w_startSlider, &QPushButton :: clicked, this, &SignalsUI :: slot_startMovingSlider);
    connect(w_stopSlider, &QPushButton :: clicked, this, &SignalsUI :: slot_stopMovingSlider);
    connect(w_timer, &QTimer :: timeout, this, &SignalsUI :: slot_timeOut);
    connect(w_levelSignalSlider, &QSlider :: valueChanged, this, &SignalsUI :: signal_signalValue);
    connect(w_levelSignalSlider, &QSlider :: valueChanged, w_levelSignalLabel, QOverload<int> :: of (&QLabel :: setNum));

    connect(w_frequencyBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_checkRangeFrequency);
    connect(w_durationSignalBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_checkRangeDuration);
    connect(w_durationSignalNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &SignalsUI :: slot_setDuration);
    connect(w_frequencyNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &SignalsUI :: slot_setFrequency);
}

void SignalsUI :: slot_checkedModul(int state)
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


void SignalsUI :: slot_signalChanged(int currentIndex)
{
    emit signal_signalType(currentIndex);

    switch (currentIndex)
    {
    case 0:
    {
        w_frequencyBox->setEnabled(false);
        w_frequencyNum->setEnabled(false);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);
        break;
    }
    case 1:
    {
        w_frequencyBox->setEnabled(true);
        w_frequencyNum->setEnabled(true);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);

        slot_checkRangeFrequency(w_frequencyBox->currentIndex());

        break;
    }
    case 2:
    {
        w_frequencyBox->setEnabled(true);
        w_frequencyNum->setEnabled(true);
        w_durationSignalBox->setEnabled(true);
        w_durationSignalNum->setEnabled(true);

        slot_checkRangeFrequency(w_frequencyBox->currentIndex());
        break;
    }
    };
}

void SignalsUI :: slot_signalModulChanged(int currentIndex)
{
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

void SignalsUI::slot_setDecimationFrequence(const int &value)
{
    m_sampleFrequency = value;
    slot_checkRangeFrequency(w_frequencyBox->currentIndex());
    slot_checkRangeDuration(w_durationSignalBox->currentIndex());
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
    if (w_durationSignalBox->isEnabled() == 0 || m_duration == 0)
    {
        if (index == FREQUENCY :: kHz)
        {
            w_frequencyNum->setMaximum(static_cast<double>(m_sampleFrequency / 2e3));
            w_frequencyNum->setValue(m_frequency / 1e3);
        }
        else
        {
            w_frequencyNum->setMaximum(static_cast<double>(m_sampleFrequency / 2e6));
            w_frequencyNum->setValue(m_frequency / 1e6);

        }
    }
    else
    {
        if (index == FREQUENCY :: kHz)
        {
            w_frequencyNum->setMaximum(m_sampleFrequency / (m_duration * m_sampleFrequency + 2) / 1e3);
            w_frequencyNum->setValue(m_frequency / 1e3);
        }
        else
        {
            w_frequencyNum->setMaximum(m_sampleFrequency / (m_duration * m_sampleFrequency + 2) / 1e6);
            w_frequencyNum->setValue(m_frequency / 1e6);
        }
    }

}

void SignalsUI::slot_checkRangeDuration(const int &index)
{
    switch (index)
    {
        case DURATION :: ms:
        {
            w_durationSignalNum->setMaximum(1e3 * 511 / static_cast<double>(m_sampleFrequency));
            w_durationSignalNum->setValue(m_duration * 1e3);
            return;
        }
        case DURATION :: us:
        {
            w_durationSignalNum->setMaximum(1e6 * 511 / static_cast<double>(m_sampleFrequency));
            w_durationSignalNum->setValue(m_duration * 1e6);
            return;
        }
        case DURATION :: ns:
        {
            w_durationSignalNum->setMaximum(1e9 * 511 / static_cast<double>(m_sampleFrequency));
            w_durationSignalNum->setValue(m_duration * 1e9);
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
    slot_checkRangeFrequency(w_frequencyBox->currentIndex());

    emit signal_signalDuration(m_duration);
}

void SignalsUI::slot_setFrequency(const double &value)
{
    if (w_frequencyBox->currentIndex() == FREQUENCY :: kHz)
    {
        m_frequency = value * 1e3;
    }
    else
    {
        m_frequency = value * 1e6;
    }
    emit signal_signalFrequency(m_frequency);
}


