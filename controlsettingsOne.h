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
    QComboBox *w_sampleFrequanceBox;
    QComboBox *w_trigFrequanceBox;
    QComboBox *w_trigSrcBox;
    QPushButton *w_setSettings;
    QCheckBox *w_testLED;


signals:

};

#endif // CONTROLSETTINGSONE_H
