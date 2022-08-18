#include "controladdresses.h"
#include <QGridLayout>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QSpacerItem>
#include <QHostAddress>

ControlAddresses::ControlAddresses(QWidget *parent)
    : QWidget{parent}
{
    m_sendingSocket = new QUdpSocket;

    QString IpRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    QRegularExpression IpRegex ("^" + IpRange
                                    + "(\\." + IpRange + ")"
                                    + "(\\." + IpRange + ")"
                                    + "(\\." + IpRange + ")$");
    QRegularExpressionValidator *ipValidator = new QRegularExpressionValidator(IpRegex, this);

    w_signalAddress = new QLineEdit;
    w_signalAddress->setValidator(ipValidator);

    w_signalDataPort = new QSpinBox;
    w_signalDataPort->setMinimum(0);
    w_signalDataPort->setMaximum(65535);

    w_signalAnswerPort = new QSpinBox;
    w_signalAnswerPort->setMinimum(0);
    w_signalAnswerPort->setMaximum(65535);

    w_controlAddress = new QLineEdit;
    w_controlAddress->setValidator(ipValidator);

    w_controlDataPort = new QSpinBox;
    w_controlDataPort->setMinimum(0);
    w_controlDataPort->setMaximum(65535);

    w_controlAnswerPort = new QSpinBox;
    w_controlAnswerPort->setMinimum(0);
    w_controlAnswerPort->setMaximum(65535);

    w_setSettings = new QPushButton(QString("Set"));
    w_startReceiving = new QPushButton(QString("Start"));
    w_stopReceiving = new QPushButton(QString("Stop"));

    QFormLayout *mainForm = new QFormLayout;
    QGroupBox *ctrAddressesBox = new QGroupBox(QString("Control Addresses"));
    QGridLayout *ctrAddressesLayout = new QGridLayout;

    mainForm->addWidget(ctrAddressesBox);
    ctrAddressesBox->setLayout(ctrAddressesLayout);

    ctrAddressesLayout->addWidget(new QLabel(QString("PC Address")), 0, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Data Port")), 0, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 0, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_signalAddress, 1, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_signalDataPort, 1, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_signalAnswerPort, 1, 2, 1, 1);

    ctrAddressesLayout->addWidget(new QLabel(QString("Board Address")), 2, 0, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Data Port")), 2, 1, 1, 1);
    ctrAddressesLayout->addWidget(new QLabel(QString("Control Port")), 2, 2, 1, 1);

    ctrAddressesLayout->addWidget(w_controlAddress, 3, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_controlDataPort, 3, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_controlAnswerPort, 3, 2, 1, 1);


    ctrAddressesLayout->addWidget(w_setSettings, 4, 0, 1, 1);
    ctrAddressesLayout->addWidget(w_startReceiving, 4, 1, 1, 1);
    ctrAddressesLayout->addWidget(w_stopReceiving, 4, 2, 1, 1);

    this->setLayout(mainForm);

}

void ControlAddresses :: slot_setSendingSettings()
{
    m_sendingSocket->abort();
    m_sendingSocket->bind(QHostAddress(w_controlAddress->text()), w_controlAnswerPort->value());
    m_sendingSocket->open(QUdpSocket :: ReadWrite);
}
