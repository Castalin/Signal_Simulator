#ifndef CONTROLANGLE_H
#define CONTROLANGLE_H

#include <QWidget>
#include <QDial>
#include <QLabel>
#include <QPushButton>
#include <QDoubleSpinBox>

class ControlAngle : public QWidget
{
    Q_OBJECT
public:
    explicit ControlAngle(QWidget *parent = nullptr);

signals:
    void signal_angleValueChanged(const double &value);
    void signal_angleSpeedValueChanged(const double &value);

private:
    QDial *w_dialForAngle;
    QLabel *w_angleLabel;
    QPushButton *w_startChangeAngle;
    QPushButton *w_stopChangeAngle;
    QDoubleSpinBox *w_angleSpeedBox;
    double m_angleValue;



private slots:
    void slot_angleChanged(int position);
    void slot_startBtn();

public slots:
    void slot_angleChanged(const double &value);
    void slot_stopBtn();

};

#endif // CONTROLANGLE_H
