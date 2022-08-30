#ifndef SIGNALDATAMAIN_H
#define SIGNALDATAMAIN_H

#include "a_controller.h"


class SignalDataMain : public a_Controller
{
    Q_OBJECT
public:
    SignalDataMain();

signals:

private:
    quint8 m_angle[2];
    quint8 m_velocityOfAngle[2];

    enum
    {
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
    void slot_angleChanged(const int &value);
    void slot_velocityOfAngleChanged(const double &value);
    void slot_prepareData(const int &num);

};

#endif // SIGNALDATAMAIN_H
