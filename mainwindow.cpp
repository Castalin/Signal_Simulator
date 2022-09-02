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
    // UI ends here

    m_ctrDataMain = new ControlDataMain;

    // connects controlAdresses object and receiving/bindings slots
    connect(m_ctrAddresses, &ControlAddresses :: signal_setControlSettings, m_ctrDataMain, &ControlDataMain :: slot_setAddressSettings);
    connect(m_ctrAddresses, &ControlAddresses :: signal_startControlThread, m_ctrDataMain, &ControlDataMain :: slot_startThread);
    connect(m_ctrAddresses, &ControlAddresses :: signal_stopControlThread, m_ctrDataMain, &ControlDataMain :: slot_stopThread);


    // connects incoming data with UI
    connect(m_ctrDataMain, &ControlDataMain :: signal_controlSettingsOne, m_ctrSettings_1, &ControlSettingsOne :: slot_processingIncomingDataControl);
    connect(m_ctrDataMain, &ControlDataMain :: signal_LED, m_ctrSettings_1, &ControlSettingsOne :: slot_processingIncomingDataLED);
    connect(m_ctrDataMain, &ControlDataMain :: signal_controlSettingsTwo, m_ctrSettings_2, &ControlSettingsTwo :: slot_proccessingIncomingDataControl);

    connect(m_ctrDataMain, &ControlDataMain :: signal_ADC_A_DELAY_0, m_adc_Delay, &ADCDelay :: slot_proccessingADC_A_DELAY_0);
    connect(m_ctrDataMain, &ControlDataMain :: signal_ADC_A_DELAY_1, m_adc_Delay, &ADCDelay :: slot_proccessingADC_A_DELAY_1);
    connect(m_ctrDataMain, &ControlDataMain :: signal_ADC_B_DELAY_0, m_adc_Delay, &ADCDelay :: slot_proccessingADC_B_DELAY_0);
    connect(m_ctrDataMain, &ControlDataMain :: signal_ADC_B_DELAY_1, m_adc_Delay, &ADCDelay :: slot_proccessingADC_B_DELAY_1);


    m_signalDataMain = new SignalDataMain;

    connect(m_ctrAddresses, &ControlAddresses :: signal_setSignalSettings, m_signalDataMain, &SignalDataMain :: slot_setAddressSettings);
    connect(m_ctrAngle, &ControlAngle :: signal_angleValueChanged, m_signalDataMain, &SignalDataMain :: slot_angleChanged);
    connect(m_ctrSettings_1, &ControlSettingsOne :: signal_RxEnableValueChanged, m_signalDataMain, &SignalDataMain :: slot_RxEnableValueChanged);
    connect(m_ctrSettings_2, &ControlSettingsTwo :: signal_startSourceScale, m_signalDataMain, &SignalDataMain :: slot_startSourceScale);

}


MainWindow::~MainWindow()
{
}

