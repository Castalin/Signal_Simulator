#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>
#include "Signal/factoryofsignal.h"

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables, NoiseVariables *const noiseVariables,  QObject *parent = nullptr);

private:
    int m_strobeSize;
    FactoryOfSignal m_factoryOfSignal;
    const int c_header;
    const int m_packetSize;
    const int numOfPackets;
    void countChannelA(QByteArray * const byteArrayPtr);
    void countChannelB(QByteArray * const byteArrayPtr);
    void countChannelA(QVector<double> &signalRe, QVector<double> &signalIm);

public:
    void countSignal(const int &numberOfPackage, QByteArray *const byteArrayPtr);
    void countSignal(QVector<double> &signalRe, QVector<double> &signalIm);

public slots:
    void slot_setStrobeSize(const unsigned char &info);
    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);
signals:

};

#endif // SIGNALGENERATOR_H
