#include "UI/signalsui.h"
#include <QGridLayout>
#include <QGroupBox>
#include <QFormLayout>


SignalsUI::SignalsUI(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, QWidget *parent)
    : QWidget{parent}, m_setterMainSignal(signalVariables), m_freqRangesMainSignal{signalVariables}, m_durationRangesMainSignal{signalVariables}
{
    w_signalsBox = new QComboBox;
    w_signalsBox->addItems(QStringList{"None", "Sine", "Rect"});
    w_signalsBox->setItemData(SIGNALS :: RECTANGLE, QString("Rectangle"), Qt :: ToolTipRole);

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


    m_amplitudeMainSignalUI = new AmplitideMainSignalUI(&m_setterMainSignal);
    signalLayout->addWidget(m_amplitudeMainSignalUI, 2, 0, 2, 5);

    m_modulationUI= new ModulationUI(signalVariables, modSignalVariables);
    signalLayout->addWidget(m_modulationUI, 4, 0, 3, 5);


    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *signalGroup = new QGroupBox(QString("Signal settings"));

    signalGroup->setLayout(signalLayout);
    mainForm->addWidget(signalGroup);
    this->setLayout(mainForm);

    m_freqRangesMainSignal.setPtrToFreqSpinNum(w_frequencySignalNum);
    m_durationRangesMainSignal.setPtrToDurationSpinNum(w_durationSignalNum);

    m_freqRangesMainSignal.checkRangeFrequency(w_frequencySignalBox->currentIndex());
    m_durationRangesMainSignal.checkRangeDuration(w_durationSignalBox->currentIndex());

    connect(w_signalsBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalChanged);


    // about duration and frequency switchers
    connect(w_frequencySignalBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged),
            this, [this](const int &index)->void{m_freqRangesMainSignal.checkRangeFrequency(index);});
    connect(w_durationSignalBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged),
            this, [this](const int &index)->void{m_durationRangesMainSignal.checkRangeDuration(index);});
    connect(w_frequencySignalNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this,&SignalsUI :: slot_setFrequency);
    connect(w_durationSignalNum, QOverload<double> :: of(&QDoubleSpinBox :: valueChanged), this, &SignalsUI :: slot_setDuration);

    // connects modulation info with signalData controller
    connect(m_modulationUI, &ModulationUI :: signal_signalType, this, [this](const int &ModType)->void{m_signalType.second = ModType; emit signal_signalType(m_signalType);});

}

void SignalsUI :: slot_signalChanged(const int &currentIndex)
{
    m_signalType.first = currentIndex;
    //emit signal_signalType(m_signalType);
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
    m_freqRangesMainSignal.changeSetterForRange(currentIndex);
    m_freqRangesMainSignal.checkRangeFrequency(w_frequencySignalBox->currentIndex());
}


void SignalsUI::slot_stopMovingSliderOut()
{
    m_amplitudeMainSignalUI->slot_stopMovingSlider();
    m_modulationUI->stopMovingSlider();
}

void SignalsUI::slot_decimationFrequenceChanged()
{
    m_freqRangesMainSignal.checkRangeFrequency(w_frequencySignalBox->currentIndex());
    m_durationRangesMainSignal.checkRangeDuration(w_durationSignalBox->currentIndex());
    m_modulationUI->DecimationFrequencyChanged();
}


void SignalsUI::slot_setDuration(const double &duration)
{
    m_setterMainSignal.setDuration(w_durationSignalBox->currentIndex(), duration);
    m_freqRangesMainSignal.checkRangeFrequency(w_frequencySignalBox->currentIndex());
    m_modulationUI->mainSignalParamChanged();
}

void SignalsUI::slot_setFrequency(const double &frequency)
{
    m_setterMainSignal.setFrequency(w_frequencySignalBox->currentIndex(), frequency);
    m_modulationUI->mainSignalParamChanged();
}



