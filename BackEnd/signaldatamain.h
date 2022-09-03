#ifndef SIGNALDATAMAIN_H
#define SIGNALDATAMAIN_H

#include <QObject>
#include "datasender.h"

class SignalDataMain : public QObject
{
    Q_OBJECT
public:
    explicit SignalDataMain(QObject *parent = nullptr);

signals:

private:
    QByteArray *m_Message;
    DataSender *m_DataSender;
    char m_angle[2];
    char m_velocityOfAngle[2];
    int num_Changed = 0;
    const quint8 c_constants[4]{0xAA, 0x55, 0x00, 0x01};

    enum
    {    // firstly
        ANGLE_BYTE_0                = 0,
        ANGLE_BYTE_1                = 1,
        ANGLE_VELOC_BYTE_0          = 2,
        ANGLE_VELOC_BYTE_1          = 3,
        PACKAGE_NUM_BYTE_0          = 4,
        PACKAGE_NUM_BYTE_1          = 5,
        HEADER_BYTE_0               = 6,
        HEADER_BYTE_1               = 7,
        THE_FIRST_DATA_ADDRESS      = 8,
        THE_LAST_DATA_ADDRESS       = 1031,

    };


public slots:
    void slot_setAddressSettings(const QString &address, const int &port);
    void slot_angleChanged(const double &value);
    void slot_prepareData(const int num);
    void slot_RxEnableValueChanged(const unsigned char &sentData);
    void slot_startSourceScale(const unsigned char &info);

};

#endif // SIGNALDATAMAIN_H
