#ifndef SIGNALGENERATORSENDER_H
#define SIGNALGENERATORSENDER_H

#include "AbstractANDInterfaces/a_signalgenerator.h"
#include "Signal/factoryofsignal.h"


class SignalGeneratorSender : public a_SignalGenerator
{
public:
    SignalGeneratorSender(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables, NoiseVariables * const noiseVariables,
                          const int numOfPackets, const int sizeOfPacket, QVector<QByteArray*> * const array);

private:
    const int c_header;
    void countChannelA() override;
    void countChannelB() override;
    QVector<QByteArray*> * m_byteArrayPtr;
    int numberOfPackage;
    FactoryOfSignal *m_factoryOfSignal;

public:
    void countSignal();
    void slot_setSignalType(const QPair<int, int> &signalType);
    void slot_setNoiseState(const QPair<int, int> &state);

};

#endif // SIGNALGENERATORSENDER_H
