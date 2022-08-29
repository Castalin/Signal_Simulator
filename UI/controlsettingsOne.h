#ifndef CONTROLSETTINGSONE_H
#define CONTROLSETTINGSONE_H

#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class ControlSettingsOne : public QWidget
{
    Q_OBJECT
public:
    explicit ControlSettingsOne(QWidget *parent = nullptr);

private:
    QComboBox *w_ADCRxBox;
    QComboBox *w_clockSourceBox;
    QComboBox *w_sampleFrequencyBox;
    QComboBox *w_trigFrequencyBox;
    QComboBox *w_trigSrcBox;
    QCheckBox *w_testLED;

    enum struct RxEnable
    {
        DISABLED                        =   0b0,
        ENABLED                         =   0b1
    };

    enum struct ClockSignalSource
    {
        INTERNAL                        =   0b0,
        EXTERNAL                        =   0b1
    };

    enum struct SignalDecimation
    {
        DecimationBy1                   =   0b000,
        DecimationBy2                   =   0b001,
        DecimationBy4                   =   0b010,
        DecimationBy8                   =   0b011,
        DecimationBy16                  =   0b100,
        DecimationBy32                  =   0b101,
        DecimationBy64                  =   0b110,
        DecimationBy128                 =   0b111
    };

    enum struct IntenernalStartSourceScale
    {
        Frequency_1kHz                  =   0b0,
        Frequency_2kHz                  =   0b1
    };

    enum struct StartSignalSource
    {
        INTERNAL                        =   0b0,
        EXTERNAL                        =   0b1
    };

    RxEnable m_rxEnable;
    ClockSignalSource m_clockSignalSource;
    SignalDecimation m_decimation;
    IntenernalStartSourceScale m_frequencyScale;
    StartSignalSource m_startSignalSource;

    bool m_LED;


signals:
    void signal_RxEnableValueChanged(const ControlSettingsOne :: RxEnable &m_rxEnable);

public slots:
    void slot_processingIncomingDataControl(const unsigned char &info);
    void slot_processingIncomingDataLED(const unsigned char &info);


};

#endif // CONTROLSETTINGSONE_H
