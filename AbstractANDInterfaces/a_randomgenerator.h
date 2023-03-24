#ifndef A_RANDOMGENERATOR_H
#define A_RANDOMGENERATOR_H


class A_RandomGenerator
{
public:
    A_RandomGenerator(const int &refreshNum = 1);
protected:
    int i;
    double m_randVariable;
    int m_refreshNum;

public:
    virtual double generateValue();

};

#endif // A_RANDOMGENERATOR_H
