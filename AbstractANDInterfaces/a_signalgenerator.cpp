#include "a_signalgenerator.h"

a_SignalGenerator::a_SignalGenerator(const int numOfPackets, const int sizeOfPacket)
    : m_numOfPackets{numOfPackets}, m_sizeOfPacket{sizeOfPacket}
{
    m_strobeSize = 32;
}


void a_SignalGenerator::setStrobeSize(const int &newStrobeSize)
{
    m_strobeSize = newStrobeSize;
}
