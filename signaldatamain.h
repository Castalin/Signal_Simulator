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
    quint16 m_angle;
    quint16 m_velocityOfAngle;

    enum struct RxEnable
    {
        DISABLED                        =   0b0,
        ENABLED                         =   0b1
    };

    RxEnable m_rxEnable;

public slots:
    void slot_prepareData();

};

#endif // SIGNALDATAMAIN_H
