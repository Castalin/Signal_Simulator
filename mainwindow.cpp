#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QFormLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_ctrDataMain = new ProcessIncomingData;
    m_signalGenerator = new SignalGenerator(m_all_Data.getMainSignalVar(), m_all_Data.getModSignalVar(), m_all_Data.getNoiseVar());
    m_signalDataMain = new SignalDataMain(m_signalGenerator);
    m_all_Data = All_Data();

    w_ctrSettings_1 = new ControlSettingsOne;
    w_ctrSettings_2 = new ControlSettingsTwo;
    w_adc_Delay = new ADCDelay;
    w_ctrAngle = new ControlAngle;
    w_ctrAddresses = new ControlAddresses;
    w_signalsUI = new SignalsUI(m_all_Data.getMainSignalVar(), m_all_Data.getModSignalVar());
    w_noiseUI = new NoiseUI(m_all_Data.getNoiseVar());
    w_allPlots = new AllPlotsUI(m_signalGenerator, m_signalDataMain->getMessagePtr());

    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QVBoxLayout *settingsLayout_1 = new QVBoxLayout;
    QVBoxLayout *settingsLayout_2 = new QVBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    w_checkPlots = new QCheckBox(QString("Plots"));

    settingsLayout_1->addWidget(w_signalsUI);
    settingsLayout_1->addWidget(w_ctrAngle);
    settingsLayout_1->addWidget(w_ctrAddresses, 1);

    settingsLayout_2->addWidget(w_noiseUI);
    settingsLayout_2->addWidget(w_ctrSettings_1);
    settingsLayout_2->addWidget(w_ctrSettings_2);
    settingsLayout_2->addWidget(w_adc_Delay);
    settingsLayout_2->addSpacerItem(new QSpacerItem(0, 25, QSizePolicy :: Minimum, QSizePolicy :: Minimum));
    settingsLayout_2->addWidget(w_checkPlots, 0, Qt :: AlignCenter);
    settingsLayout_2->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy :: Minimum, QSizePolicy :: Expanding));
    //settingsLayout->setMargin(2);

    //settingsLayout->setVerticalSpacing(2);
   /*
    settingsLayout->addWidget(m_signalsUI, 0, 0, 6, 6, Qt :: AlignTop);
    settingsLayout->addWidget(m_noiseUI, 0, 6, 4, 3);
    settingsLayout->addWidget(m_ctrSettings_1, 3, 6, 2, 3, Qt :: AlignTop);
    settingsLayout->addWidget(m_ctrSettings_2, 5, 6, 2, 3, Qt :: AlignTop);
    settingsLayout->addWidget(m_adc_Delay, 7, 6, 2, 3, Qt :: AlignTop);
    settingsLayout->addWidget(m_ctrAngle, 5, 0, 2, 6, Qt :: AlignBottom);
    settingsLayout->addWidget(m_ctrAddresses, 7, 0, 2, 6, Qt :: AlignTop);
    settingsLayout->addWidget(m_adc_Delay, 8, 6, 3, 3, Qt :: AlignCenter);
    settingsLayout->addWidget(m_signalPlot, 0, 9, 3, 3, Qt :: AlignCenter);
*/
    mainLayout->addLayout(settingsLayout_1);
    mainLayout->addLayout(settingsLayout_2);
    mainLayout->addWidget(w_allPlots);
    w_allPlots->setVisible(false);

    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);
    // UI ends here



    // connects controlAdresses object and receiving/bindings slots
    connect(w_ctrAddresses, &ControlAddresses :: signal_setControlSettings, m_ctrDataMain, &ProcessIncomingData :: slot_setAddressSettings);
    connect(w_ctrAddresses, &ControlAddresses :: signal_startControlThread, m_ctrDataMain, &ProcessIncomingData :: slot_startThread);
    connect(w_ctrAddresses, &ControlAddresses :: signal_stopControlThread, m_ctrDataMain, &ProcessIncomingData :: slot_stopThread);


    // connects incoming data with UI
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_controlSettingsOne, w_ctrSettings_1, &ControlSettingsOne :: slot_processingIncomingDataControl);
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_LED, w_ctrSettings_1, &ControlSettingsOne :: slot_processingIncomingDataLED);
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_controlSettingsTwo, w_ctrSettings_2, &ControlSettingsTwo :: slot_proccessingIncomingDataControl);

    connect(m_ctrDataMain, &ProcessIncomingData :: signal_ADC_A_DELAY_0, w_adc_Delay, &ADCDelay :: slot_proccessingADC_A_DELAY_0);
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_ADC_A_DELAY_1, w_adc_Delay, &ADCDelay :: slot_proccessingADC_A_DELAY_1);
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_ADC_B_DELAY_0, w_adc_Delay, &ADCDelay :: slot_proccessingADC_B_DELAY_0);
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_ADC_B_DELAY_1, w_adc_Delay, &ADCDelay :: slot_proccessingADC_B_DELAY_1);



    connect(w_ctrAddresses, &ControlAddresses :: signal_setSignalSettings, m_signalDataMain, &SignalDataMain :: slot_setAddressSettings);                   // binds address
    connect(w_ctrAngle, &ControlAngle :: signal_angleValueChanged, m_signalDataMain, &SignalDataMain :: slot_angleChanged);
    connect(w_ctrAngle, &ControlAngle :: signal_angleSpeedValueChanged, m_signalDataMain, &SignalDataMain :: slot_angleSpeedChanged);
    connect(m_signalDataMain, &SignalDataMain :: signal_angleValueChanged, w_ctrAngle, QOverload<const double&> :: of(&ControlAngle :: slot_angleChanged));

    connect(w_ctrSettings_1, &ControlSettingsOne :: signal_RxValueChanged, m_signalDataMain, &SignalDataMain :: slot_RxEnableValueChanged);                 // signal_RxValueChanged has got info about rxEnable
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_controlSettingsTwo, m_signalDataMain, &SignalDataMain :: slot_startSourceScale);                      //signal_controlSettingsTwo has got info about sourceScale
    connect(m_ctrDataMain, &ProcessIncomingData :: signal_controlSettingsTwo, m_signalGenerator, &SignalGenerator :: slot_setStrobeSize);
    connect(w_ctrSettings_1, QOverload<const int&>  :: of(&ControlSettingsOne :: signal_DecimationChanged), this, [this](const int &decimation)->void{m_all_Data.setDecimationFrequence(decimation);});
    connect(w_ctrSettings_1, QOverload<> :: of(&ControlSettingsOne :: signal_DecimationChanged), w_signalsUI, &SignalsUI :: slot_decimationFrequenceChanged);

    connect(m_signalDataMain, &SignalDataMain :: finished, w_ctrAngle, &ControlAngle :: slot_stopBtn);                                                       // stops timers
    connect(m_signalDataMain, &SignalDataMain :: finished, w_signalsUI, &SignalsUI :: slot_stopMovingSliderOut);                                                // stops timers
    connect(w_signalsUI, &SignalsUI :: signal_signalType, m_signalGenerator, &SignalGenerator :: slot_setSignalType);
    connect(w_noiseUI, &NoiseUI :: signal_noiseState, m_signalGenerator, &SignalGenerator :: slot_setNoiseState);

    connect(w_checkPlots, &QCheckBox :: stateChanged, this, [this](const int &state)->void{state == Qt :: Checked ? w_allPlots->setVisible(true) : w_allPlots->setVisible(false);});

}


MainWindow::~MainWindow()
{
}

