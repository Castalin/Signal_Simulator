#ifndef CONTROLSETTINGS_1_H
#define CONTROLSETTINGS_1_H

#include <QWidget>
#include <QComboBox>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>

class ControlSettings_1 : public QWidget
{
    Q_OBJECT
public:
    explicit ControlSettings_1(QWidget *parent = nullptr);

private:
    QComboBox *w_ADCRxBox;
    QComboBox *w_clockSourceBox;
    QComboBox *w_sampleFrequanceBox;
    QComboBox *w_trigFrequanceBox;
    QComboBox *w_trigSrcBox;
    QPushButton *w_initADC;
    QPushButton *w_setSettings;
    QCheckBox *w_testLED;


signals:

};

#endif // CONTROLSETTINGS_1_H
