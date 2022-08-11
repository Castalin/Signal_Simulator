#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signalsui.h"
#include "controlsettingsOne.h"
#include "controlsettingsTwo.h"
#include "adc_delay.h"

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
};
#endif // MAINWINDOW_H
