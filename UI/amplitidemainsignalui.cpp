#include "amplitidemainsignalui.h"
#include <QGridLayout>

AmplitideMainSignalUI::AmplitideMainSignalUI(SetterMainSignal *const ptrToSetterMainSignal, QWidget *parent)
    : QWidget{parent}, m_setterMainSignal{ptrToSetterMainSignal}
{
    w_levelSignalSlider = new QSlider(Qt :: Orientation :: Horizontal);
    w_levelSignalSlider->setMaximum(100);
    w_levelSignalSlider->setMinimum(-100);
    w_levelSignalLabel = new QLabel(QString("0"));
    w_startSlider = new QPushButton(QString("Start"));
    w_stopSlider = new QPushButton(QString("Stop"));
    w_stopSlider->setEnabled(false);
    w_timer = new QTimer(this);
    m_step = 1;

    QGridLayout *AmplitudeMainSignalLayout = new QGridLayout();
    AmplitudeMainSignalLayout->setVerticalSpacing(10);

    QFrame *frame = new QFrame;
    frame->setFrameShape(QFrame :: Shape :: HLine);
    frame->setFrameShadow(QFrame :: Shadow :: Sunken);
    frame->setMidLineWidth(2);
    AmplitudeMainSignalLayout->addWidget(frame, 0, 0, 1, 5);
    AmplitudeMainSignalLayout->addWidget(w_startSlider, 1, 0, 1, 1, Qt :: AlignCenter);
    AmplitudeMainSignalLayout->addWidget(w_stopSlider, 1, 1, 1, 1, Qt :: AlignCenter);
    AmplitudeMainSignalLayout->addWidget(w_levelSignalSlider, 1, 2, 1, 2);
    AmplitudeMainSignalLayout->addWidget(w_levelSignalLabel, 1, 4, 1, 1, Qt :: AlignCenter);

    this->setLayout(AmplitudeMainSignalLayout);


    connect(w_startSlider, &QPushButton :: clicked, this, &AmplitideMainSignalUI :: slot_startMovingSlider);
    connect(w_stopSlider, &QPushButton :: clicked, this, &AmplitideMainSignalUI :: slot_stopMovingSlider);
    connect(w_timer, &QTimer :: timeout, this, &AmplitideMainSignalUI :: slot_timeOut);
    connect(w_levelSignalSlider, &QSlider :: valueChanged, this, [this](const int &amplitude)->void{m_setterMainSignal->setAmplitude(amplitude);});
    connect(w_levelSignalSlider, &QSlider :: valueChanged, w_levelSignalLabel, QOverload<int> :: of (&QLabel :: setNum));
}


void AmplitideMainSignalUI::slot_startMovingSlider()
{
    w_levelSignalSlider->setEnabled(false);
    w_timer->start(std :: chrono :: milliseconds(100));
    w_startSlider->setEnabled(false);
    w_stopSlider->setEnabled(true);
}

void AmplitideMainSignalUI::slot_stopMovingSlider()
{
    w_timer->stop();
    w_startSlider->setEnabled(true);
    w_levelSignalSlider->setEnabled(true);
    w_stopSlider->setEnabled(false);
}


void AmplitideMainSignalUI::slot_timeOut()
{
    if (w_levelSignalSlider->value() == w_levelSignalSlider->maximum())
    {
        m_step = -1;
    }
    else if (w_levelSignalSlider->value() == w_levelSignalSlider->minimum())
    {
        m_step = 1;
    }

    w_levelSignalSlider->setValue(w_levelSignalSlider->value() + m_step);

}
