#ifndef AMPLITUDEMODSIGNALUI_H
#define AMPLITUDEMODSIGNALUI_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include "SettersVarANDRangeCheck/settermodsignal.h"
#include <map>
#include "Structes/enumSignals.h"

class AmplitudeModSignalUI : public QWidget
{
    Q_OBJECT
public:
    explicit AmplitudeModSignalUI(SetterModSignal *const ptrToSetterModSignal, QWidget *parent = nullptr);
    void disable();
    void enable();
    void setLabel(const int &index);
    QSlider* getSliderPtr();



private:
    QSlider *w_levelSignalSliderMod;
    QLabel *w_levelSignalLabelMod;
    QPushButton *w_startSliderMod;
    QPushButton *w_stopSliderMod;
    SetterModSignal *m_ptrToSetterModSignal;
    QTimer *w_timerMod;

    int m_step;
    QString m_label;
    std :: map<int, QPair<QString, QString>> stringMap;
private slots:
    void slot_startMovingSlider();
    void slot_timeOut();

public slots:
        void slot_stopMovingSlider();
        void slot_updateLabel(const int &index);
signals:

};

#endif // AMPLITUDEMODSIGNALUI_H
