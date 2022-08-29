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

    w_PCAddress = new QLineEdit;
    w_PCAddress->setValidator(ipValidator);
    w_PCAddress->setText(QString("192.168.0.1"));

    w_PCDataPort = new QSpinBox;
    w_PCDataPort->setMinimum(0);
    w_PCDataPort->setMaximum(65535);

    w_PCControlPort = new QSpinBox;
    w_PCControlPort->setMinimum(0);
    w_PCControlPort->setMaximum(65535);
    w_PCControlPort->setValue(16416);

    w_BoardAddress = new QLineEdit;
    w_BoardAddress->setValidator(ipValidator);
    w_BoardAddress->setText(QString("192.168.0.2"));

    w_BoardDataPort = new QSpinBox;
    w_BoardDataPort->setMinimum(0);
    w_BoardDataPort->setMaximum(65535);

    w_BoardControlPort = new QSpinBox;
    w_BoardControlPort->setMinimum(0);
    w_BoardControlPort->setMaximum(65535);
    w_BoardControlPort->setValue(16480);

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

    ctrAddressesLayout->addWidget(new QLabel(QString("PC Address")), 0, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Send Port")), 0, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 0, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_PCAddress, 1, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_PCDataPort, 1, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_PCControlPort, 1, 2, 1, 1);

    ctrAddressesLayout->addWidget(new QLabel(QString("Board Address")), 2, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Send Port")), 2, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 2, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_BoardAddress, 3, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_BoardDataPort, 3, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_BoardControlPort, 3, 2, 1, 1);


    ctrAddressesLayout->addWidget(w_setSettings, 4, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_startReceiving, 4, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_stopReceiving, 4, 2, 1, 1);

    this->setLayout(mainForm);

    connect(w_setSettings, &QPushButton :: clicked, this, &ControlAddresses :: slot_setControlSettings);
    // connect(w_setSettings, &QPushButton :: clicked, this, &ControlAddresses :: slot_setSignalSettings); will be added soon
    connect(w_startReceiving, &QPushButton :: clicked, this, &ControlAddresses :: slot_startControlThread);
    connect(w_stopReceiving, &QPushButton :: clicked, this, &ControlAddresses :: slot_stopControlThread);
}

QHostAddress ControlAddresses::getBoardAddress()
{
    return QHostAddress(w_BoardAddress->text());
}

int ControlAddresses::getBoardDataPort()
{
    return w_BoardDataPort->value();
}

int ControlAddresses::getBoardControlPort()
{
    return w_BoardControlPort->value();
}

QHostAddress ControlAddresses::getPCAddress()
{
    return QHostAddress(w_PCAddress->text());
}

int ControlAddresses::getPCDataPort()
{
    return w_PCDataPort->value();
}

int ControlAddresses::getPCControlPort()
{
    return w_PCControlPort->value();
}

void ControlAddresses::slot_setControlSettings()
{
    w_startReceiving->setEnabled(true);
    emit signal_setControlSettings(w_PCAddress->text(), w_PCControlPort->value());
}

void ControlAddresses::slot_startControlThread()
{
    w_stopReceiving->setEnabled(true);
    w_startReceiving->setEnabled(false);
    w_BoardDataPort->setEnabled(false);
    w_BoardControlPort->setEnabled(false);
    w_setSettings->setEnabled(false);
    w_BoardAddress->setEnabled(false);
    emit signal_startControlThread(w_BoardAddress->text(), w_BoardControlPort->value());

}

void ControlAddresses::slot_stopControlThread()
{
    w_stopReceiving->setEnabled(false);
    w_startReceiving->setEnabled(true);
    w_BoardDataPort->setEnabled(true);
    w_BoardControlPort->setEnabled(true);
    w_setSettings->setEnabled(true);
    w_BoardAddress->setEnabled(true);
    emit signal_stopControlThread();
}





