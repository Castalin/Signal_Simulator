#ifndef ALLPLOTSUI_H
#define ALLPLOTSUI_H

#include <QWidget>
#include "signalplot.h"
#include "BackEnd/signalgenerator.h"
#include <QTimer>
#include <QMutex>

class AllPlotsUI : public QWidget
{
    Q_OBJECT
public:
    explicit AllPlotsUI(SignalGenerator * const signalGenerator, QVector<QByteArray*> * const arraySignal, QWidget *parent = nullptr);
    virtual ~AllPlotsUI();


private:
    SignalPlot *m_signalPlot;

    SignalGenerator *m_signalGenerator;

    QVector<QByteArray*> *m_sendedMessage;           // watch signalDataMain
    QMutex *m_mutex;
    QTimer *m_timer;
signals:

};

#endif // ALLPLOTSUI_H
