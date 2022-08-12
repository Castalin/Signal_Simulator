#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signalsui.h"
#include "controlsettingsOne.h"
#include "controlsettingsTwo.h"
#include "adc_delay.h"
#include "controlangle.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    signalsUI *m_signalUI;
    ControlSettingsOne *m_ctrSettings_1;
    ControlSettingsTwo *m_ctrSettings_2;
    ADCDelay *m_adc_Delay;
    ControlAngle *m_ctrAngle;
};
#endif // MAINWINDOW_H
