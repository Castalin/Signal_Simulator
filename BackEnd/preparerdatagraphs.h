#ifndef PREPARERDATAGRAPHS_H
#define PREPARERDATAGRAPHS_H
#include <QTimer>
#include <QMutex>
#include "BackEnd/signalgenerator.h"

class PreparerDataGraphs : public QObject
{
    Q_OBJECT
public:
    explicit PreparerDataGraphs(SignalGenerator * const signalGenerator, QVector<QByteArray*> * const arraySignal, QObject *parent = nullptr);
    virtual ~PreparerDataGraphs();

private:
    QMutex *m_mutex;
    QTimer *m_timer;
    bool m_workingThread;
    bool m_plotGraphs;
    const int m_packetSize;
    const int c_header;

    SignalGenerator *m_signalGenerator;
    QVector<QByteArray*> *m_sendedMessage;           // watch signalDataMain

    QVector<double> m_signalRe, m_signalIm, m_signalAbs;

    void copyFromMessage();
    void getFromSignalGenerator();
    void makeAbs();

public:
    void setPlottingEnable(const int &cond);
    void setThreadCondition(const bool &cond);

private slots:
    void slot_timerShot();

signals:
    void signalReAndIm(const QVector<double> &signalRe, const QVector<double> &signalIm);
    void signalAbs(const QVector<double> &signalAbs);
};

#endif // PREPARERDATAGRAPHS_H
