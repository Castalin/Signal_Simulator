#ifndef ANGLECOUNTER_H
#define ANGLECOUNTER_H

#include <QObject>
#include <QTimer>

class AngleCounter : public QObject
{
    Q_OBJECT
public:
    explicit AngleCounter(QObject *parent = nullptr);

private:
    double m_angleValue;
    double m_angleSpeedValue;
    QTimer *m_timer;
    quint16 m_angle16;
    void timerOut();

public:
    void angleChanged(const double &value);
    void angleSpeedChanged(const double &value);
    void* getAngleint16();

signals:
    void signal_angleValueChanged(const double &value);


};

#endif // ANGLECOUNTER_H
