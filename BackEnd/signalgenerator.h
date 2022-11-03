#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include "Signal/factoryofsignal.h"

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, QByteArray *ptrToData, QObject *parent = nullptr);

private:
    int m_strobeSize;
    QByteArray *m_ptrToData;
    FactoryOfSignal m_factoryOfSignal;


public:
    void countSignal();

    void deleteSignal();
    void setStrobeSize(const unsigned char &info);
    void setSignalType(const QPair<int, int> &signalType);



signals:

};

#endif // SIGNALGENERATOR_H
