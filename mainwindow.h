#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signalsui.h"
#include "controlsettingsOne.h"
#include "controlsettingsTwo.h"
#include "adc_delay.h"
#include "controlangle.h"
#include "controladdresses.h"

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
};
#endif // MAINWINDOW_H
