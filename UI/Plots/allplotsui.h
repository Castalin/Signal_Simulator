#ifndef ALLPLOTSUI_H
#define ALLPLOTSUI_H

#include <QWidget>
#include "signalplot.h"
#include "BackEnd/preparerdatagraphs.h"

class AllPlotsUI : public QWidget
{
    Q_OBJECT
public:
    explicit AllPlotsUI(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                        QWidget *parent = nullptr);
    virtual ~AllPlotsUI();


private:
    SignalPlot *m_signalPlot;

    PreparerDataGraphs *m_preparerDataGraphs;

public slots:
    void slot_setPlottingEnable(const int &cond);
    void slot_setStrobeSize(const int &newStrobeSize);
    void slot_setDecimation(const int &decimation);
    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);
    void slot_stopDrawing();
    void slot_startDrawing();
signals:

};

#endif // ALLPLOTSUI_H
