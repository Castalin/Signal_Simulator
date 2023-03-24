#ifndef PREPARERDATAGRAPHS_H
#define PREPARERDATAGRAPHS_H
#include <QTimer>
#include <QMutex>
#include "AbstractANDInterfaces/a_signalgenerator.h"
#include "Signal/factoryofsignal.h"

class PreparerDataGraphs : public QObject, public a_SignalGenerator
{
    Q_OBJECT
public:
    explicit PreparerDataGraphs(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                                QObject *parent = nullptr);
    virtual ~PreparerDataGraphs();

private:
    QTimer *m_timer;
    bool m_plotGraphs;
    FactoryOfSignal *m_factoryOfSignal;

    QVector<double> m_signalRe, m_signalIm, m_signalAbs;

    void makeAbs();

    virtual void countChannelA() override;
    virtual void countChannelB() override;

public:
    void setPlottingEnable(const int &cond);
    void setThreadCondition(const bool &cond);
    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);

private slots:
    void slot_timerShot();

signals:
    void signalReAndIm(QVector<double> &signalRe, QVector<double> &signalIm);
    void signalAbs(QVector<double> &signalAbs);
};

#endif // PREPARERDATAGRAPHS_H
