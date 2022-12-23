#ifndef A_RANDOMGENERATOR_H
#define A_RANDOMGENERATOR_H


class A_RandomGenerator
{
public:
    A_RandomGenerator();
protected:
    int i;
    double m_randVariable;

public:
    virtual double generateValue();

};

#endif // A_RANDOMGENERATOR_H
