#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_signalUI = new signalsUI;
    m_ctrSettings_1 = new ControlSettingsOne;
    m_ctrSettings_2 = new ControlSettingsTwo;
    m_adc_Delay = new ADCDelay;
    m_ctrAngle = new ControlAngle;
    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QGridLayout *mainLayout = new QGridLayout;


    mainLayout->addWidget(m_signalUI, 0, 0, 6, 5);

    mainLayout->setVerticalSpacing(1);
    mainLayout->addWidget(m_ctrSettings_1, 0, 6, 4, 4);
    mainLayout->addWidget(m_ctrSettings_2, 4, 6, 2, 4, Qt :: AlignTop);
    mainLayout->addWidget(m_adc_Delay, 6, 6, 1, 4, Qt :: AlignTop);
    mainLayout->addWidget(m_ctrAngle, 5, 0, 1, 4);
    mainLayout->setVerticalSpacing(1);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);


}

MainWindow::~MainWindow()
{
}

