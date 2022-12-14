#ifndef MODRIP_H
#define MODRIP_H

#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signalmod.h"
#include <QTimer>

class ModRIP : public QObject, protected A_signalMod, public I_getSignal, public I_getSignalIm
{
    Q_OBJECT
public:
    explicit ModRIP(ModSignalVariables  * const modSignalVariables, QObject *parent = nullptr);

    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;
    void startTimer();
    void stopTimer();


private:
    QTimer *m_timer;
    double m_phase;

private slots:
    void slot_timeOut();

};

#endif // MODRIP_H
