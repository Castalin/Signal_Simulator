#include "controlangle.h"
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGroupBox>

ControlAngle::ControlAngle(QWidget *parent)
    : QWidget{parent}
{
    dialForAngle = new QDial;
    dialForAngle->setMaximumSize(35, 35);
    dialForAngle->setMinimum(0);
    dialForAngle->setMaximum(360);
    angleLabel = new QLabel(QString("0"));

    QHBoxLayout *hbox = new QHBoxLayout;
    QGroupBox *angleBox = new QGroupBox(QString("Angle Control"));
    QFormLayout *mainForm = new QFormLayout;

    mainForm->addWidget(angleBox);
    angleBox->setLayout(hbox);

    hbox->addWidget(new QLabel(QString("Angle: ")));
    hbox->addWidget(angleLabel);
    hbox->addWidget(dialForAngle);

    this->setLayout(mainForm);

    connect(dialForAngle, &QDial :: sliderMoved, this, &ControlAngle :: angleChanged);
    connect(dialForAngle, &QDial :: valueChanged, this, &ControlAngle :: angleChanged);
}

void ControlAngle::angleChanged(int position)
{
    angleLabel->clear();
    angleLabel->setText(QString :: number(position));
}


