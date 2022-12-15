#ifndef NOISEUI_H
#define NOISEUI_H

#include <QWidget>
#include <QCheckBox>
#include <QSlider>
#include <QLabel>
#include "SettersVarANDRangeCheck/setternoise.h"

class NoiseUI : public QWidget
{
    Q_OBJECT
public:
    explicit NoiseUI(NoiseVariables * const noiseVariables, QWidget *parent = nullptr);

private:
    QCheckBox *w_checkNoise;
    QSlider *w_levelDispSlider;
    QLabel *w_levelDispLabel;
    SetterNoise m_setterNoise;


private slots:
    void slot_stateChanged(const int &state);
    void slot_updateLabel(const int &value);

signals:
    void signal_noiseState(const int &state);

};

#endif // NOISEUI_H
