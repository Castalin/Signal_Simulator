#ifndef ADC_DELAY_H
#define ADC_DELAY_H

#include <QWidget>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QLabel>

class ADC_Delay : public QWidget
{
    Q_OBJECT
public:
    explicit ADC_Delay(QWidget *parent = nullptr);

signals:

private:
    QSpinBox *w_spinDelay_1;
    QSpinBox *w_spinDelay_2;
    QPushButton *w_setDelay_1;
    QPushButton *w_setDelay_2;
    QCheckBox *w_checkSynchronize;
    QLabel *w_label_2;


};

#endif // ADC_DELAY_H
