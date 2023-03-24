#include "allplotsui.h"

AllPlotsUI::AllPlotsUI(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                       QWidget *parent)
    : QWidget{parent}
{

    QHBoxLayout *horLayout = new QHBoxLayout;
    m_preparerDataGraphs = new PreparerDataGraphs{signalVariables, modSignalVariables, noiseVariables};
    m_signalPlot = new SignalPlot;

    horLayout->addWidget(m_signalPlot);
    setLayout(horLayout);
    m_signalPlot->setVisible(false);

    connect(m_preparerDataGraphs, &PreparerDataGraphs :: signalReAndIm, m_signalPlot, &SignalPlot :: slot_redrawReAndIm);
    connect(m_preparerDataGraphs, &PreparerDataGraphs :: signalAbs, m_signalPlot, &SignalPlot :: slot_redrawAbs);
}

AllPlotsUI::~AllPlotsUI()
{

}

void AllPlotsUI::slot_setPlottingEnable(const int &cond)
{
    m_preparerDataGraphs->setPlottingEnable(cond);

    if (cond == Qt :: Checked)
    {
        m_signalPlot->setVisible(true);
    }
    else
    {
        m_signalPlot->setVisible(false);
    }
}

void AllPlotsUI::slot_setStrobeSize(const int &newStrobeSize)
{
    m_preparerDataGraphs->setStrobeSize(newStrobeSize);
    m_signalPlot->setStrobeSize(newStrobeSize);
}

void AllPlotsUI::slot_setDecimation(const int &decimation)
{
    m_signalPlot->setDecimation(decimation);
}

void AllPlotsUI::slot_setSignalType(const QPair<int, int> &signalType)
{
    m_preparerDataGraphs->slot_setSignalType(signalType);
}

void AllPlotsUI::slot_setNoiseState(const QPair<int, int> &state)
{
    m_preparerDataGraphs->slot_setNoiseState(state);
}

void AllPlotsUI::slot_stopDrawing()
{
    m_preparerDataGraphs->setPlottingEnable(Qt :: Unchecked);
}

void AllPlotsUI::slot_startDrawing()
{
    m_preparerDataGraphs->setPlottingEnable(Qt :: Checked);
}

