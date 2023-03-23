#ifndef ALLPLOTSUI_H
#define ALLPLOTSUI_H

#include <QWidget>
#include "signalplot.h"
#include "BackEnd/preparerdatagraphs.h"

class AllPlotsUI : public QWidget
{
    Q_OBJECT
public:
    explicit AllPlotsUI(SignalGenerator * const signalGenerator, QVector<QByteArray*> * const arraySignal, QWidget *parent = nullptr);
    virtual ~AllPlotsUI();


private:
    SignalPlot *m_signalPlot;

    PreparerDataGraphs m_preparerDataGraphs;

public slots:
    void slot_threadStarted();
    void slot_threadEnded();
    void slot_setPlottingEnable(const int &cond);

signals:

};

#endif // ALLPLOTSUI_H
