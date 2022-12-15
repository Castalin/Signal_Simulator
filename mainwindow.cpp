#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_ctrSettings_1 = new ControlSettingsOne;
    m_ctrSettings_2 = new ControlSettingsTwo;
    m_adc_Delay = new ADCDelay;
    m_ctrAngle = new ControlAngle;
    m_ctrAddresses = new ControlAddresses;
    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QGridLayout *mainLayout = new QGridLayout;
    m_all_Data = All_Data();
    m_signalsUI = new SignalsUI(m_all_Data.getMainSignalVar(), m_all_Data.getModSignalVar());
    m_noiseUI = new NoiseUI(m_all_Data.getNoiseVar());

    mainLayout->setVerticalSpacing(2);
    mainLayout->setMargin(2);
    mainLayout->addWidget(m_signalsUI, 0, 0, 6, 6, Qt :: AlignTop);
    mainLayout->addWidget(m_noiseUI, 0, 6, 1, 3);
    mainLayout->addWidget(m_ctrSettings_1, 1, 6, 2, 3);
    mainLayout->addWidget(m_ctrSettings_2, 3, 6, 2, 3, Qt :: AlignTop);
    mainLayout->addWidget(m_adc_Delay, 5, 6, 2, 3, Qt :: AlignTop);
    mainLayout->addWidget(m_ctrAngle, 5, 0, 2, 6, Qt :: AlignBottom);
    mainLayout->addWidget(m_ctrAddresses, 7, 0, 2, 6, Qt :: AlignTop);

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

    m_signalDataMain = new SignalDataMain(m_all_Data.getMainSignalVar(), m_all_Data.getModSignalVar());

    connect(m_ctrAddresses, &ControlAddresses :: signal_setSignalSettings, m_signalDataMain, &SignalDataMain :: slot_setAddressSettings);                   // binds address
    connect(m_ctrAngle, &ControlAngle :: signal_angleValueChanged, m_signalDataMain, &SignalDataMain :: slot_angleChanged);
    connect(m_ctrAngle, &ControlAngle :: signal_angleSpeedValueChanged, m_signalDataMain, &SignalDataMain :: slot_angleSpeedChanged);
    connect(m_signalDataMain, &SignalDataMain :: signal_angleValueChanged, m_ctrAngle, QOverload<const double&> :: of(&ControlAngle :: slot_angleChanged));

    connect(m_ctrSettings_1, &ControlSettingsOne :: signal_RxValueChanged, m_signalDataMain, &SignalDataMain :: slot_RxEnableValueChanged);                 // signal_RxValueChanged has got info about rxEnable
    connect(m_ctrDataMain, &ControlDataMain :: signal_controlSettingsTwo, m_signalDataMain, &SignalDataMain :: slot_startSourceScale);                      //signal_controlSettingsTwo has got info about sourceScale
    connect(m_ctrDataMain, &ControlDataMain :: signal_controlSettingsTwo, m_signalDataMain, &SignalDataMain :: slot_StrobeSizeValueChanged);
    connect(m_ctrSettings_1, QOverload<const int&>  :: of(&ControlSettingsOne :: signal_DecimationChanged), this, [this](const int &decimation)->void{m_all_Data.setDecimationFrequence(decimation);});
    connect(m_ctrSettings_1, QOverload<> :: of(&ControlSettingsOne :: signal_DecimationChanged), m_signalsUI, &SignalsUI :: slot_decimationFrequenceChanged);

    connect(m_signalDataMain, &SignalDataMain :: finished, m_ctrAngle, &ControlAngle :: slot_stopBtn);                                                       // stops timers
    connect(m_signalDataMain, &SignalDataMain :: finished, m_signalsUI, &SignalsUI :: slot_stopMovingSliderOut);                                                // stops timers
    connect(m_signalsUI, &SignalsUI :: signal_signalType, m_signalDataMain, &SignalDataMain :: slot_setSignalType);

}


MainWindow::~MainWindow()
{
}

