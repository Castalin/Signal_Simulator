#ifndef A_RANDOMGENERATOR_H
#define A_RANDOMGENERATOR_H


class A_RandomGenerator
{
public:
    A_RandomGenerator();

protected:
    double m_randVariable;
    virtual void generateValue() = 0;
    int i;
};

#endif // A_RANDOMGENERATOR_H
