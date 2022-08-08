#ifndef SIGNALSUI_H
#define SIGNALSUI_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QCheckBox>

class signalsUI : public QWidget
{
    Q_OBJECT
public:
    explicit signalsUI(QWidget *parent = nullptr);

signals:

private:
    QComboBox *w_signalsBox;
    QComboBox *w_frequanceBox;
    QSpinBox *w_frequanceNum;
    QComboBox *w_durationSignalBox;
    QSpinBox *w_durationSignalNum;

    QCheckBox *w_checkModulation;
    QComboBox *w_signalsBoxModul;
    QComboBox *w_frequanceBoxModul;
    QSpinBox *w_frequanceNumModul;
    QComboBox *w_durationSignalBoxModul;
    QSpinBox *w_durationSignalNumModul;

    QPushButton *w_setSignalSettings;


public slots:
    void slot_checkedModul(int state);
    void slot_signalChanged(int currentIndex);
    void slot_signalModulChanged(int currentIndex);




};

#endif // SIGNALSUI_H
