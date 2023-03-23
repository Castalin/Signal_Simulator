#include "allplotsui.h"

AllPlotsUI::AllPlotsUI(SignalGenerator * const signalGenerator, QVector<QByteArray*> * const arraySignal, QWidget *parent)
    : QWidget{parent}, m_preparerDataGraphs{signalGenerator, arraySignal}
{
    QHBoxLayout *horLayout = new QHBoxLayout;
    m_signalPlot = new SignalPlot;

    horLayout->addWidget(m_signalPlot);
    setLayout(horLayout);
    m_signalPlot->setVisible(false);

    connect(&m_preparerDataGraphs, &PreparerDataGraphs :: signalReAndIm, m_signalPlot, &SignalPlot :: slot_redrawReAndIm);
    connect(&m_preparerDataGraphs, &PreparerDataGraphs :: signalAbs, m_signalPlot, &SignalPlot :: slot_redrawReAndIm);
}

AllPlotsUI::~AllPlotsUI()
{

}

void AllPlotsUI::slot_threadStarted()
{
    m_preparerDataGraphs.setThreadCondition(true);
}

void AllPlotsUI::slot_threadEnded()
{
    m_preparerDataGraphs.setThreadCondition(false);
}

void AllPlotsUI::slot_setPlottingEnable(const int &cond)
{
    m_preparerDataGraphs.setPlottingEnable(cond);

    if (cond == Qt :: Checked)
    {
        m_signalPlot->setVisible(true);
    }
    else
    {
        m_signalPlot->setVisible(false);
    }
}
