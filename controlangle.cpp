#include "controlangle.h"
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QTimer>

ControlAngle::ControlAngle(QWidget *parent)
    : QWidget{parent}
{
    m_angleValue = new double{0.0};
    w_dialForAngle = new QDial;
    w_dialForAngle->setMaximumSize(35, 35);
    w_dialForAngle->setMinimum(0);
    w_dialForAngle->setMaximum(360);
    w_angleLabel = new QLabel(QString("0"));

    w_timer = new QTimer(this);
    w_startChangeAngle = new QPushButton(QString("Start"));
    w_stopChangeAngle = new QPushButton(QString("Stop"));
    w_angleSpeedBox = new QDoubleSpinBox;
    w_angleSpeedBox->setMinimum(-10.0);
    w_angleSpeedBox->setMaximum(10.0);

    QGridLayout *ctrAngleGrid = new QGridLayout;
    QGroupBox *angleBox = new QGroupBox(QString("Angle Control"));
    QFormLayout *mainForm = new QFormLayout;

    mainForm->addWidget(angleBox);
    angleBox->setLayout(ctrAngleGrid);

    ctrAngleGrid->addWidget(new QLabel(QString("Angle: ")), 0, 0, 2, 1);
    ctrAngleGrid->addWidget(w_angleLabel, 0, 1, 2, 1);
    ctrAngleGrid->addWidget(w_dialForAngle, 0, 2, 2, 1, Qt :: AlignLeft);
    ctrAngleGrid->addWidget(new QLabel(QString("Speed Deg/s")), 0, 3, 1, 2, Qt :: AlignCenter);
    ctrAngleGrid->addWidget(w_angleSpeedBox, 0, 5, 1, 2);
    ctrAngleGrid->addWidget(w_startChangeAngle, 1, 3, 1, 2);
    ctrAngleGrid->addWidget(w_stopChangeAngle, 1, 5, 1, 2);

    this->setLayout(mainForm);

    connect(w_dialForAngle, &QDial :: sliderMoved, this, &ControlAngle :: slot_angleChanged);
    connect(w_dialForAngle, &QDial :: valueChanged, this, &ControlAngle :: slot_angleChanged);
    connect(w_startChangeAngle, &QPushButton :: clicked, this, &ControlAngle :: slot_startBtn);
    connect(w_stopChangeAngle, &QPushButton :: clicked, this, &ControlAngle :: slot_stopBtn);
    connect(w_timer, &QTimer :: timeout, this, &ControlAngle :: timeOut);
}

void ControlAngle::slot_angleChanged(int position)
{
    *m_angleValue = static_cast<double>(position);
    w_angleLabel->setText(QString :: number(position));
}

void ControlAngle::slot_startBtn()
{
    w_startChangeAngle->setEnabled(false);
    w_dialForAngle->setEnabled(false);
    w_angleSpeedBox->setEnabled(false);
    w_stopChangeAngle->setEnabled(true);
    w_timer->start(100);

}

void ControlAngle::slot_stopBtn()
{
    w_startChangeAngle->setEnabled(true);
    w_dialForAngle->setEnabled(true);
    w_angleSpeedBox->setEnabled(true);
    w_stopChangeAngle->setEnabled(false);
    w_timer->stop();
}

void ControlAngle :: timeOut()
{
    *m_angleValue += 0.1*(w_angleSpeedBox->value());

    if (*m_angleValue < 0.0)
    {
        *m_angleValue += 360.0;
    }
    else if (*m_angleValue > 360.0)
    {
        *m_angleValue -= 360.0;
    }

    w_angleLabel->setText(QString :: number(*m_angleValue));
}

ControlAngle :: ~ControlAngle()
{
    delete m_angleValue;
}
