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

private:
    QDial *w_dialForAngle;
    QLabel *w_angleLabel;
    QTimer *m_timer;
    QPushButton *w_startChangeAngle;
    QPushButton *w_stopChangeAngle;
    QDoubleSpinBox *w_angleSpeedBox;
    double *m_angleValue;
    void timeOut();



private slots:
    void slot_angleChanged(int position);
    void slot_startBtn();
    void slot_stopBtn();

};

#endif // CONTROLANGLE_H
