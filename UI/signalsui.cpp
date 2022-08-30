#include "UI/signalsui.h"
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QFormLayout>
#include <QTimer>

SignalsUI::SignalsUI(QWidget *parent)
    : QWidget{parent}
{

    w_signalsBox = new QComboBox;
    w_signalsBox->addItems(QStringList{"None", "Sin", "Rect"});

    w_frequanceBox = new QComboBox;
    w_frequanceBox->addItems(QStringList{"Hz", "kHz", "MHz", "GHz"});
    w_frequanceBox->setEnabled(false);

    w_frequanceNum = new QSpinBox;
    w_frequanceNum->setMinimum(0);
    w_frequanceNum->setMaximum(1000);
    w_frequanceNum->setEnabled(false);

    w_durationSignalBox = new QComboBox;
    w_durationSignalBox->addItems(QStringList{"s", "ms", "us", "ns"});
    w_durationSignalBox->setEnabled(false);

    w_durationSignalNum = new QSpinBox;
    w_durationSignalNum->setMinimum(0);
    w_durationSignalNum->setMaximum(1000);
    w_durationSignalNum->setEnabled(false);

    w_setSignalSettings = new QPushButton(QString("Set"));

    w_checkModulation = new QCheckBox(QString("Modulation"));
    w_checkModulation->setCheckable(true);

    w_signalsBoxModul = new QComboBox;
    w_signalsBoxModul->addItems(QStringList{"None", "Sin", "Rect"});
    w_signalsBoxModul->setEnabled(false);

    w_frequanceBoxModul = new QComboBox;
    w_frequanceBoxModul->addItems(QStringList{"Hz", "kHz", "MHz", "GHz"});
    w_frequanceBoxModul->setEnabled(false);

    w_frequanceNumModul = new QSpinBox;
    w_frequanceNumModul->setMinimum(0);
    w_frequanceNumModul->setMaximum(1000);
    w_frequanceNumModul->setEnabled(false);

    w_durationSignalBoxModul = new QComboBox;
    w_durationSignalBoxModul->addItems(QStringList{"s", "ms", "us", "ns"});
    w_durationSignalBoxModul->setEnabled(false);

    w_durationSignalNumModul = new QSpinBox;
    w_durationSignalNumModul->setMinimum(0);
    w_durationSignalNumModul->setMaximum(1000);
    w_durationSignalNumModul->setEnabled(false);

    QGridLayout *signalLayout = new QGridLayout();
    signalLayout->setVerticalSpacing(10);

    signalLayout->addWidget(new QLabel(QString("Signal type")), 0, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(new QLabel(QString("Frequance")), 0, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(new QLabel(QString("Duration")), 0, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    signalLayout->addWidget(w_signalsBox, 1, 0, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequanceNum, 1, 1, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_frequanceBox, 1, 2, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalNum, 1, 3, 1, 1, Qt :: AlignCenter);
    signalLayout->addWidget(w_durationSignalBox, 1, 4, 1, 1, Qt :: AlignCenter);



    QGridLayout *modulationGrid = new QGridLayout;
    QGroupBox *modulationGroup = new QGroupBox();
    modulationGroup->setLayout(modulationGrid);

    modulationGrid->addWidget(w_checkModulation, 0, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(new QLabel(QString("Signal type")), 1, 0, 1, 1, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Frequance")), 1, 1, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(new QLabel(QString("Duration")), 1, 3, 1, 2, Qt :: AlignHCenter | Qt :: AlignBottom);
    modulationGrid->addWidget(w_signalsBoxModul, 2, 0, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequanceNumModul, 2, 1, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_frequanceBoxModul, 2, 2, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalNumModul, 2, 3, 1, 1, Qt :: AlignCenter);
    modulationGrid->addWidget(w_durationSignalBoxModul, 2, 4, 1, 1, Qt :: AlignCenter);


    signalLayout->addWidget(modulationGroup, 2, 0, 3, 5);
    signalLayout->addWidget(w_setSignalSettings, 5, 0, 1, 5, Qt :: AlignCenter);


    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *signalGroup = new QGroupBox(QString("Signal settings"));


    signalGroup->setLayout(signalLayout);
    mainForm->addWidget(signalGroup);


    this->setLayout(mainForm);

    connect(w_checkModulation, &QCheckBox :: stateChanged, this, &SignalsUI :: slot_checkedModul);
    connect(w_signalsBox, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalChanged);
    connect(w_signalsBoxModul, QOverload<int> :: of(&QComboBox :: currentIndexChanged), this, &SignalsUI :: slot_signalModulChanged);

    // ui ends here

    m_externalTimer = new QTimer(this);
    m_internalTimer = new QTimer(this);
    m_counter = 0;

    connect(m_externalTimer, &QTimer :: timeout, this, [this]()->void{m_internalTimer->start(2);});
    connect(m_internalTimer, &QTimer :: timeout, this, &SignalsUI :: slot_signalSendData);

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
        w_frequanceBoxModul->setEnabled(false);
        w_frequanceNumModul->setEnabled(false);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);

    }
}


void SignalsUI :: slot_signalChanged(int currentIndex)
{
    switch (currentIndex)
    {
    case 0:
    {
        w_frequanceBox->setEnabled(false);
        w_frequanceNum->setEnabled(false);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);
        break;
    }
    case 1:
    {
        w_frequanceBox->setEnabled(true);
        w_frequanceNum->setEnabled(true);
        w_durationSignalBox->setEnabled(false);
        w_durationSignalNum->setEnabled(false);
        break;
    }
    case 2:
    {
        w_frequanceBox->setEnabled(true);
        w_frequanceNum->setEnabled(true);
        w_durationSignalBox->setEnabled(true);
        w_durationSignalNum->setEnabled(true);
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
        w_frequanceBoxModul->setEnabled(false);
        w_frequanceNumModul->setEnabled(false);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);
        break;
    }
    case 1:
    {
        w_frequanceBoxModul->setEnabled(true);
        w_frequanceNumModul->setEnabled(true);
        w_durationSignalBoxModul->setEnabled(false);
        w_durationSignalNumModul->setEnabled(false);
        break;
    }
    case 2:
    {
        w_frequanceBoxModul->setEnabled(true);
        w_frequanceNumModul->setEnabled(true);
        w_durationSignalBoxModul->setEnabled(true);
        w_durationSignalNumModul->setEnabled(true);
        break;
    }
    };
}


void SignalsUI::slot_signalSendData()
{
    ++m_counter;
    emit signal_sendData(m_counter);
    if (m_counter == 8)
    {
        m_counter = 0;
        m_internalTimer->stop();
    }
}

void SignalsUI::slot_RxEnableValueChanged(const unsigned char &rxEnable)
{
    if (rxEnable == 0x00)
    {
        m_externalTimer->stop();
    }
    else
    {
        m_externalTimer->start(20);
        m_internalTimer->start(1);
    }
}

