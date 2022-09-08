#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <QObject>

class SignalGenerator : public QObject
{
    Q_OBJECT
public:
    explicit SignalGenerator(QObject *parent = nullptr);

signals:

};

#endif // SIGNALGENERATOR_H
