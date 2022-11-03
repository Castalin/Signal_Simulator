#ifndef AMPLITUDEMODSIGNALUI_H
#define AMPLITUDEMODSIGNALUI_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include "SettersVarANDRangeCheck/settermodsignal.h"

class AmplitudemodsignalUI : public QWidget
{
    Q_OBJECT
public:
    explicit AmplitudemodsignalUI(SetterModSignal *const ptrToSetterModSignal, QWidget *parent = nullptr);
    void disable();
    void enable();


private:
    QSlider *w_levelSignalSliderMod;
    QLabel *w_levelSignalLabelMod;
    QPushButton *w_startSliderMod;
    QPushButton *w_stopSliderMod;
    QTimer *w_timerMod;
    SetterModSignal *m_ptrToSetterModSignal;

private slots:
    void slot_startMovingSlider();
    void slot_timeOut();

public slots:
        void slot_stopMovingSlider();
signals:

};

#endif // AMPLITUDEMODSIGNALUI_H
