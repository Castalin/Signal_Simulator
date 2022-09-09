#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QByteArray *ptrToData, QObject *parent = nullptr);

private:
    int m_strobeSize;
    QByteArray *m_ptrToData;
    qint16 m_value;


public:
    void prepareData();
    void setValue(const int &value);
    void setStrobeSize(const unsigned char &info);
signals:

};

#endif // SIGNALGENERATOR_H
