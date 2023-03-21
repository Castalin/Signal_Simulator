#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/SignalSettings/signalsui.h"
#include "UI/Untouchable/controlsettingsOne.h"
#include "UI/Untouchable/controlsettingsTwo.h"
#include "UI/Untouchable/adc_delay.h"
#include "UI/controlangle.h"
#include "UI/controladdresses.h"
#include "BackEnd/controldatamain.h"
#include "BackEnd/signaldatamain.h"
#include "UI/noiseui.h"
#include "UI/Plots/signalplot.h"

#include "Structes/all_data.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:


private:
    SignalsUI *m_signalsUI;
    ControlSettingsOne *m_ctrSettings_1;
    ControlSettingsTwo *m_ctrSettings_2;
    ADCDelay *m_adc_Delay;
    ControlAngle *m_ctrAngle;
    ControlAddresses *m_ctrAddresses;
    ControlDataMain *m_ctrDataMain;
    SignalDataMain *m_signalDataMain;
    NoiseUI *m_noiseUI;
    SignalPlot *m_signalPlot;
    QCheckBox *m_checkPlots;

    All_Data m_all_Data;
};
#endif // MAINWINDOW_H
