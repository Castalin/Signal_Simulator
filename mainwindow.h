#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/SignalSettings/signalsui.h"
#include "UI/Untouchable/controlsettingsOne.h"
#include "UI/Untouchable/controlsettingsTwo.h"
#include "UI/Untouchable/adc_delay.h"
#include "UI/controlangle.h"
#include "UI/controladdresses.h"
#include "BackEnd/processincomingdata.h"
#include "BackEnd/SignalSender/signaldatasender.h"
#include "UI/noiseui.h"
#include "UI/Plots/allplotsui.h"

#include "Structes/all_data.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:


private:
    SignalsUI *w_signalsUI;
    ControlSettingsOne *w_ctrSettings_1;
    ControlSettingsTwo *w_ctrSettings_2;
    ADCDelay *w_adc_Delay;
    ControlAngle *w_ctrAngle;
    ControlAddresses *w_ctrAddresses;
    NoiseUI *w_noiseUI;
    AllPlotsUI *w_allPlots;
    QCheckBox *w_checkPlots;
    QPushButton *w_startDrawing;
    QPushButton *w_stopDrawing;

    ProcessIncomingData *m_ctrDataMain;
    SignalDataSender *m_signalDataSender;
    All_Data m_all_Data;
};
#endif // MAINWINDOW_H
