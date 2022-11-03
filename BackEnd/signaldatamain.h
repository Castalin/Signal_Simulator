#ifndef SIGNALDATAMAIN_H
#define SIGNALDATAMAIN_H

#include "settingssender.h"
#include <QThread>
#include <QMutex>
#include "anglecounter.h"
#include "signalgenerator.h"

class SignalDataMain : public QThread, public SettingsSender
{
    Q_OBJECT
public:
    explicit SignalDataMain(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, QObject *parent = nullptr);

signals:
    void signal_angleValueChanged(const double &value);

private:
    QByteArray *m_Message;
    QMutex *m_mutex;
    bool m_workingThreadEnable;
    void run() override;
    bool isWorking();
    int m_sleepValue;

    AngleCounter *m_angleCounter;
    SignalGenerator *m_signalGenerator;

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
    void slot_angleSpeedChanged(const double &value);
    void slot_RxEnableValueChanged(const unsigned char &sentData);
    void slot_StrobeSizeValueChanged(const unsigned char &sentData);
    void slot_startSourceScale(const unsigned char &info);

    void slot_setSignalType(const QPair<int, int> &signalType);



private:


};

#endif // SIGNALDATAMAIN_H
