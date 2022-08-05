#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signalsui.h"
#include "controlsettings_1.h"
#include "controlsettings_2.h"
#include "adc_delay.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    signalsUI *m_signalUI;
    ControlSettings_1 *m_ctrSettings_1;
    ControlSettings_2 *m_ctrSettings_2;
    ADC_Delay *m_adc_Delay;
};
#endif // MAINWINDOW_H
