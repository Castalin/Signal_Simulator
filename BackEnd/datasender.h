#ifndef DATASENDER_H
#define DATASENDER_H

#include "settingssender.h"
#include <QThread>
#include <QMutex>
#include "anglecounter.h"

class DataSender : public QThread, public SettingsSender
{
    Q_OBJECT
public:
    explicit DataSender(QByteArray *ptrToData, QObject *parent = nullptr);


private:
    QMutex *m_mutex;
    bool m_workingThreadEnable;
    void run() override;
    bool isWorking();
    QByteArray *m_ptrToData;
    int m_sleepValue;

    AngleCounter *m_angleCounter;


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

public:
    void startThread();
    void stopThread();
    void sleepValueChanged(const int &i);
    void setAddressSettings(const QString &address, const int &port) override;

    void angleChanged(const double &value);
    void angleSpeedChanged(const double &value);

signals:
    void signal_angleValueChanged(const double &value);


};

#endif // DATASENDER_H
