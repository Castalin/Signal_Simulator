#ifndef A_SIGNALGENERATOR_H
#define A_SIGNALGENERATOR_H

class a_SignalGenerator
{
public:
    a_SignalGenerator(const int numOfPackets, const int sizeOfPacket);

    void setStrobeSize(const int &newStrobeSize);

protected:
    const int m_numOfPackets;
    const int m_sizeOfPacket;
    int m_strobeSize;

    virtual void countChannelA() = 0;
    virtual void countChannelB() = 0;

};

#endif // A_SIGNALGENERATOR_H
