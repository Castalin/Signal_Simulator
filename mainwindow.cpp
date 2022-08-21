#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_signalUI = new SignalsUI;
    m_ctrSettings_1 = new ControlSettingsOne;
    m_ctrSettings_2 = new ControlSettingsTwo;
    m_adc_Delay = new ADCDelay;
    m_ctrAngle = new ControlAngle;
    m_ctrAddresses = new ControlAddresses;
    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->setVerticalSpacing(6);
    mainLayout->setMargin(2);
    mainLayout->addWidget(m_signalUI, 0, 0, 5, 6, Qt :: AlignTop);
    mainLayout->addWidget(m_ctrSettings_1, 0, 6, 2, 2);
    mainLayout->addWidget(m_ctrSettings_2, 2, 6, 2, 2, Qt :: AlignTop);
    mainLayout->addWidget(m_adc_Delay, 4, 6, 2, 2, Qt :: AlignTop);
    mainLayout->addWidget(m_ctrAngle, 3, 0, 2, 6, Qt :: AlignBottom);
    mainLayout->addWidget(m_ctrAddresses, 5, 0, 2, 6, Qt :: AlignTop);

    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    // ui ends here

    m_ctrDataMain = new ControlDataMain;

    connect(m_ctrAddresses, &ControlAddresses :: signal_setControlSettings, m_ctrDataMain, &ControlDataMain :: slot_setControlSettings);
    connect(m_ctrAddresses, &ControlAddresses :: signal_startControlThread, m_ctrDataMain, &ControlDataMain :: slot_startControlThread);
    connect(m_ctrAddresses, &ControlAddresses :: signal_stopControlThread, m_ctrDataMain, &ControlDataMain :: slot_stopControlThread);


}

MainWindow::~MainWindow()
{
}

