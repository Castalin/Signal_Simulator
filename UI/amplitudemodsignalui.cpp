#include "amplitudemodsignalui.h"
#include <QGridLayout>

AmplitudeModSignalUI::AmplitudeModSignalUI(SetterModSignal * const ptrToSetterModSignal, QWidget *parent)
    : QWidget{parent}, m_ptrToSetterModSignal{ptrToSetterModSignal}
{

    stringMap[NO_SIGNAL]    = QPair<QString, QString>(QString{"Ampl: "}, QString{"Amplitude"});
    stringMap[SINE_HAM]     = QPair<QString, QString>(QString{"Ampl: "}, QString{"Amplitude"});
    stringMap[RECTANGLE]    = QPair<QString, QString>(QString{"Ampl: "}, QString{"Amplitude"});
    stringMap[HFM]          = QPair<QString, QString>(QString{"Fdev: "}, QString{"Frequency deviation, kHz"});
    stringMap[HPM]          = QPair<QString, QString>(QString{"Pdev: "}, QString{"Phase deviation, 0.01Rad"});

    w_levelSignalSliderMod = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSliderMod->setMaximum(100);
    w_levelSignalSliderMod->setMinimum(-100);
    w_levelSignalSliderMod->setEnabled(false);
    w_levelSignalLabelMod = new QLabel(stringMap[NO_SIGNAL].first + QString("0"));
    w_levelSignalLabelMod->setToolTip(QString(stringMap[NO_SIGNAL].second));
    w_startSliderMod = new QPushButton(QString("Start"));
    w_startSliderMod->setEnabled(false);
    w_stopSliderMod = new QPushButton(QString("Stop"));
    w_stopSliderMod->setEnabled(false);
    w_timerMod = new QTimer(this);

    m_step = 1;

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);

    QGridLayout *AmplitudeModSignalLayout = new QGridLayout();

    AmplitudeModSignalLayout->addWidget(frame, 0, 0, 1, 5);
    AmplitudeModSignalLayout->addWidget(w_startSliderMod, 1, 0, 1, 1, Qt :: AlignCenter);
    AmplitudeModSignalLayout->addWidget(w_stopSliderMod, 1, 1, 1, 1, Qt :: AlignCenter);
    AmplitudeModSignalLayout->addWidget(w_levelSignalSliderMod, 1, 2, 1, 2);
    AmplitudeModSignalLayout->addWidget(w_levelSignalLabelMod, 1, 4, 1, 1, Qt :: AlignCenter);
    AmplitudeModSignalLayout->setVerticalSpacing(10);
    AmplitudeModSignalLayout->setHorizontalSpacing(5);

    this->setLayout(AmplitudeModSignalLayout);

    connect(w_startSliderMod, &QPushButton :: clicked, this, &AmplitudeModSignalUI :: slot_startMovingSlider);
    connect(w_stopSliderMod, &QPushButton :: clicked, this, &AmplitudeModSignalUI :: slot_stopMovingSlider);
    connect(w_timerMod, &QTimer :: timeout, this, &AmplitudeModSignalUI :: slot_timeOut);
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, this, [this](const int &modAmplitude)->void{m_ptrToSetterModSignal->setModAmplitude(modAmplitude);});
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, this, &AmplitudeModSignalUI :: slot_updateLabel);
}

void AmplitudeModSignalUI::disable()
{
    w_startSliderMod->setEnabled(false);
    w_levelSignalSliderMod->setEnabled(false);
    w_stopSliderMod->setEnabled(false);
    w_timerMod->stop();
}

void AmplitudeModSignalUI::enable()
{
    w_startSliderMod->setEnabled(true);
    w_levelSignalSliderMod->setEnabled(true);
}

void AmplitudeModSignalUI::slot_updateLabel(const int &index)
{
    w_levelSignalLabelMod->setText(m_label + QString :: number(index));
}

void AmplitudeModSignalUI::slot_startMovingSlider()
{
    w_levelSignalSliderMod->setEnabled(false);
    w_timerMod->start(std :: chrono :: milliseconds(100));
    w_startSliderMod->setEnabled(false);
    w_stopSliderMod->setEnabled(true);
}

void AmplitudeModSignalUI::slot_timeOut()
{
    if (w_levelSignalSliderMod->value() == w_levelSignalSliderMod->maximum())
    {
        m_step = -1;
    }
    else if (w_levelSignalSliderMod->value() == w_levelSignalSliderMod->minimum())
    {
        m_step = 1;
    }

    w_levelSignalSliderMod->setValue(w_levelSignalSliderMod->value() + m_step);
}

void AmplitudeModSignalUI::slot_stopMovingSlider()
{
    w_timerMod->stop();
    w_startSliderMod->setEnabled(true);
    w_levelSignalSliderMod->setEnabled(true);
    w_stopSliderMod->setEnabled(false);
}

void AmplitudeModSignalUI::setLabel(const int &index)
{
    m_label = stringMap[index].first;
    w_levelSignalLabelMod->setToolTip(stringMap[index].second);
    slot_updateLabel(w_levelSignalSliderMod->value());

}

QSlider *AmplitudeModSignalUI::getSliderPtr()
{
    return w_levelSignalSliderMod;
}
