#ifndef AMPLITIDEMAINSIGNALUI_H
#define AMPLITIDEMAINSIGNALUI_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QSlider>
#include <QPushButton>
#include "SettersVarANDRangeCheck/settermainsignal.h"

class AmplitideMainSignalUI : public QWidget
{
    Q_OBJECT
public:
    explicit AmplitideMainSignalUI(SetterMainSignal *const ptrToSetterMainSignal, QWidget *parent = nullptr);

private:
    QSlider *w_levelSignalSlider;
    QLabel *w_levelSignalLabel;
    QPushButton *w_startSlider;
    QPushButton *w_stopSlider;
    QTimer *w_timer;
    SetterMainSignal *m_setterMainSignal;
    int m_step;


private slots:
    void slot_startMovingSlider();
    void slot_timeOut();
    void slot_updateLabel(const int &value);

public slots:
    void slot_stopMovingSlider();
signals:

};

#endif // AMPLITIDEMAINSIGNALUI_H
