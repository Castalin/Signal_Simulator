#include "amplitudemodsignalui.h"
#include <QGridLayout>

AmplitudemodsignalUI::AmplitudemodsignalUI(SetterModSignal * const ptrToSetterModSignal, QWidget *parent)
    : QWidget{parent}, m_ptrToSetterModSignal{ptrToSetterModSignal}
{
    w_levelSignalSliderMod = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSliderMod->setMaximum(100);
    w_levelSignalSliderMod->setMinimum(-100);
    w_levelSignalSliderMod->setEnabled(false);
    w_levelSignalLabelMod = new QLabel(QString("0"));
    w_levelSignalLabelMod->setToolTip(QString("Amplitude"));
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

    connect(w_startSliderMod, &QPushButton :: clicked, this, &AmplitudemodsignalUI :: slot_startMovingSlider);
    connect(w_stopSliderMod, &QPushButton :: clicked, this, &AmplitudemodsignalUI :: slot_stopMovingSlider);
    connect(w_timerMod, &QTimer :: timeout, this, &AmplitudemodsignalUI :: slot_timeOut);
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, this, [this](const int &modAmplitude)->void{m_ptrToSetterModSignal->setModAmplitude(modAmplitude);});
    connect(w_levelSignalSliderMod, &QSlider :: valueChanged, w_levelSignalLabelMod, QOverload<int> :: of (&QLabel :: setNum));
}

void AmplitudemodsignalUI::disable()
{
    w_startSliderMod->setEnabled(false);
    w_levelSignalSliderMod->setEnabled(false);
    w_stopSliderMod->setEnabled(false);
    w_timerMod->stop();
}

void AmplitudemodsignalUI::enable()
{
    w_startSliderMod->setEnabled(true);
    w_levelSignalSliderMod->setEnabled(true);
}

void AmplitudemodsignalUI::slot_startMovingSlider()
{
    w_levelSignalSliderMod->setEnabled(false);
    w_timerMod->start(std :: chrono :: milliseconds(100));
    w_startSliderMod->setEnabled(false);
    w_stopSliderMod->setEnabled(true);
}

void AmplitudemodsignalUI::slot_timeOut()
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

void AmplitudemodsignalUI::slot_stopMovingSlider()
{
    w_timerMod->stop();
    w_startSliderMod->setEnabled(true);
    w_levelSignalSliderMod->setEnabled(true);
    w_stopSliderMod->setEnabled(false);
}
