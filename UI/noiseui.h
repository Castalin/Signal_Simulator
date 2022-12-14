#ifndef NOISEUI_H
#define NOISEUI_H

#include <QWidget>
#include <QCheckBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include "SettersVarANDRangeCheck/setternoise.h"
#include <QSlider>
class NoiseUI : public QWidget
{
    Q_OBJECT
public:
    explicit NoiseUI(NoiseVariables * const noiseVariables, QWidget *parent = nullptr);

private:
    QCheckBox *w_checkNoiseChanel_1;
    QCheckBox *w_checkNoiseChanel_2;
    QDoubleSpinBox *w_levelDispSpin_1;
    QSlider *w_levelDispSlider_1;
    QDoubleSpinBox *w_levelDispSpin_2;
    QSlider *w_levelDispSlider_2;
    QLabel *w_levelDispLabel_1;
    QLabel *w_levelDispLabel_2;
    SetterNoise m_setterNoise;

    QCheckBox *w_checkSynchronize;
    void disconnectAll();
    void connectAll();

private slots:
    void slot_stateChanged_1(const int &state);
    void slot_stateChanged_2(const int &state);
    void slot_updateLblSpin_1(const double &value);
    void slot_updateLblSlid_1(const double &value);
    void slot_updateLblSpin_2(const double &value);
    void slot_updateLblSlid_2(const double &value);

    void slot_updateAll(const double &value);
    void slot_synchronize(const int &state);

signals:
    void signal_noiseState(const QPair<int, int> &state);

};

#endif // NOISEUI_H
