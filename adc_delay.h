#ifndef ADC_DELAY_H
#define ADC_DELAY_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

class ADCDelay : public QWidget
{
    Q_OBJECT
public:
    explicit ADCDelay(QWidget *parent = nullptr);

signals:

private:
    QSpinBox *w_spinDelay_1;
    QSpinBox *w_spinDelay_2;
    QCheckBox *w_checkSynchronize;
    QLabel *w_label_2;


private slots:
    void slot_SynchronizeChanged(int state);

};

#endif // ADC_DELAY_H
