#ifndef CONTROLSETTINGSTWO_H
#define CONTROLSETTINGSTWO_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class ControlSettingsTwo : public QWidget
{
    Q_OBJECT
public:
    explicit ControlSettingsTwo(QWidget *parent = nullptr);

private:
    QComboBox *w_trigFrequencyBox;
    QComboBox *w_trigOutBox;
    QComboBox *w_strobeSizeBox;


    enum struct IntenernalStartSourceScale
    {
        Frequency_1kHz                  =   0b00,
        Frequency_2kHz                  =   0b01,
        Frequency_3kHz                  =   0b10,
        Frequency_4kHz                  =   0b11
    };

    enum struct TriggerOut
    {
        Enable                          =   0b0,
        Disable                         =   0b1
    };

    enum struct StrobeSize
    {
        Strobe_A32_B2016                =   0b000,
        Strobe_A64_B1984                =   0b001,
        Strobe_A128_B1920               =   0b010,
        Strobe_A256_B1792               =   0b011,
    };


    IntenernalStartSourceScale m_frequencyScale;
    TriggerOut m_triggerOut;
    StrobeSize m_strobeSize;

signals:

public slots:
    void slot_proccessingIncomingDataControl(const unsigned char &info);
};

#endif // CONTROLSETTINGSTWO_H
