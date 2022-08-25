#include "UI/controladdresses.h"
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSpacerItem>

ControlAddresses::ControlAddresses(QWidget *parent)
    : QWidget{parent}
{

    QString IpRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegularExpression IpRegex ("^" + IpRange
                                    + "(\\." + IpRange + ")"
                                    + "(\\." + IpRange + ")"
                                    + "(\\." + IpRange + ")$");
    QRegularExpressionValidator *ipValidator = new QRegularExpressionValidator(IpRegex, this);

    w_signalAddress = new QLineEdit;
    w_signalAddress->setValidator(ipValidator);

    w_signalSendPort = new QSpinBox;
    w_signalSendPort->setMinimum(0);
    w_signalSendPort->setMaximum(65535);

    w_signalReceivePort = new QSpinBox;
    w_signalReceivePort->setMinimum(0);
    w_signalReceivePort->setMaximum(65535);

    w_controlAddress = new QLineEdit;
    w_controlAddress->setValidator(ipValidator);

    w_controlSendPort = new QSpinBox;
    w_controlSendPort->setMinimum(0);
    w_controlSendPort->setMaximum(65535);

    w_controlReceivePort = new QSpinBox;
    w_controlReceivePort->setMinimum(0);
    w_controlReceivePort->setMaximum(65535);

    w_setSettings = new QPushButton(QString("Set"));
    w_startReceiving = new QPushButton(QString("Start"));
    w_startReceiving->setEnabled(false);
    w_stopReceiving = new QPushButton(QString("Stop"));
    w_stopReceiving->setEnabled(false);

    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *ctrAddressesBox = new QGroupBox(QString("Control Addresses"));
    QGridLayout *ctrAddressesLayout = new QGridLayout;

    mainForm->addWidget(ctrAddressesBox);
    ctrAddressesBox->setLayout(ctrAddressesLayout);

    ctrAddressesLayout->addWidget(new QLabel(QString("Signal Address")), 0, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Send Port")), 0, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 0, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_signalAddress, 1, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_signalSendPort, 1, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_signalReceivePort, 1, 2, 1, 1);

    w_signalAddress->setEnabled(false);
    w_signalSendPort->setEnabled(false);
    w_signalReceivePort->setEnabled(false);

    ctrAddressesLayout->addWidget(new QLabel(QString("Settings Address")), 2, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Send Port")), 2, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 2, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_controlAddress, 3, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_controlSendPort, 3, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_controlReceivePort, 3, 2, 1, 1);


    ctrAddressesLayout->addWidget(w_setSettings, 4, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_startReceiving, 4, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_stopReceiving, 4, 2, 1, 1);

    this->setLayout(mainForm);

    connect(w_setSettings, &QPushButton :: clicked, this, &ControlAddresses :: slot_setControlSettings);
    // connect(w_setSettings, &QPushButton :: clicked, this, &ControlAddresses :: slot_setSignalSettings); will be added soon
    connect(w_startReceiving, &QPushButton :: clicked, this, &ControlAddresses :: slot_startControlThread);
    connect(w_stopReceiving, &QPushButton :: clicked, this, &ControlAddresses :: slot_stopControlThread);
}

QHostAddress ControlAddresses::getControlAddress()
{
    return QHostAddress(w_controlAddress->text());
}

int ControlAddresses::getControlSendPort()
{
    return w_controlSendPort->value();
}

int ControlAddresses::getControlReceivePort()
{
    return w_controlReceivePort->value();
}

QHostAddress ControlAddresses::getSignalAddress()
{
    return QHostAddress(w_signalAddress->text());
}

int ControlAddresses::getSignalSendPort()
{
    return w_signalSendPort->value();
}

int ControlAddresses::getSignalReceivePort()
{
    return w_signalReceivePort->value();
}

void ControlAddresses::slot_setControlSettings()
{
    w_startReceiving->setEnabled(true);
    emit signal_setControlSettings(w_controlAddress->text(), w_controlSendPort->value());
}

void ControlAddresses::slot_startControlThread()
{
    w_stopReceiving->setEnabled(true);
    w_startReceiving->setEnabled(false);
    w_controlSendPort->setEnabled(false);
    w_controlReceivePort->setEnabled(false);
    w_setSettings->setEnabled(false);
    w_controlAddress->setEnabled(false);
    emit signal_startControlThread(w_controlAddress->text(), w_controlReceivePort->value());

}

void ControlAddresses::slot_stopControlThread()
{
    w_stopReceiving->setEnabled(false);
    w_startReceiving->setEnabled(true);
    w_controlSendPort->setEnabled(true);
    w_controlReceivePort->setEnabled(true);
    w_setSettings->setEnabled(true);
    w_controlAddress->setEnabled(true);
    emit signal_stopControlThread();
}





