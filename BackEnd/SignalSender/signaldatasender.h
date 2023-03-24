#ifndef SIGNALDATASENDER_H
#define SIGNALDATASENDER_H

#include "AbstractANDInterfaces/a_settingssender.h"
#include <QThread>
#include <QMutex>
#include "BackEnd/SignalSender/anglecounter.h"
#include "BackEnd/SignalSender/signalgeneratorsender.h"

class SignalDataSender : public QThread, public a_SettingsSender
{
    Q_OBJECT
public:
    explicit SignalDataSender(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                              QObject *parent = nullptr);
    virtual ~SignalDataSender();

signals:
    void signal_angleValueChanged(const double &value);

private:
    QMutex *m_mutex;
    bool m_workingThreadEnable;
    void run() override;
    bool isWorking();
    int m_sleepValue;

    QVector<QByteArray*> m_Message;
    const int m_numOfPackets;

    AngleCounter *m_angleCounter;
    SignalGeneratorSender *m_signalGeneratorSender;

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

    void slot_RxEnableValueChanged(const bool &sentData);
    void slot_startSourceScale(const int &startSourceScale);
    void slot_setStrobeSize(const int &strobeSize);

    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);

};

#endif // SIGNALDATASENDER_H
