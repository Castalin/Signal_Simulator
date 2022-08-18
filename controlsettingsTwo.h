#ifndef CONTROLSETTINGSTWO_H
#define CONTROLSETTINGSTWO_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class ControlSettingsTwo : public QWidget
{
    Q_OBJECT
public:
    explicit ControlSettingsTwo(QWidget *parent = nullptr);

signals:

private:
    QComboBox *w_trigFrequanceBox;
    QComboBox *w_trigOutBox;
    QComboBox *w_strobSizeBox;


};

#endif // CONTROLSETTINGSTWO_H
