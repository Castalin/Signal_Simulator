#ifndef SIGNALDATAMAIN_H
#define SIGNALDATAMAIN_H

#include <QObject>

class SignalDataMain : public QObject
{
    Q_OBJECT
public:
    explicit SignalDataMain(QObject *parent = nullptr);

signals:

private:
    char m_angle[2];
    char m_velocityOfAngle[2];
    QByteArray *m_Message;

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
    void slot_angleChanged(const double &value);
    void slot_prepareData(const int &num);

};

#endif // SIGNALDATAMAIN_H
