#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "UI/signalsui.h"
#include "UI/controlsettingsOne.h"
#include "UI/controlsettingsTwo.h"
#include "UI/adc_delay.h"
#include "UI/controlangle.h"
#include "UI/controladdresses.h"
#include "controldatamain.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    const ControlAddresses &ctrAddresses() const;
    void setCtrAddresses(const ControlAddresses &newCtrAddresses);

signals:
    void ctrAddressesChanged();

private:
    SignalsUI *m_signalUI;
    ControlSettingsOne *m_ctrSettings_1;
    ControlSettingsTwo *m_ctrSettings_2;
    ADCDelay *m_adc_Delay;
    ControlAngle *m_ctrAngle;
    ControlAddresses *m_ctrAddresses;
    ControlDataMain *m_ctrDataMain;

};
#endif // MAINWINDOW_H
