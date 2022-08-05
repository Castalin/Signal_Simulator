#ifndef CONTROLSETTINGS_2_H
#define CONTROLSETTINGS_2_H

#include <QWidget>
#include <QComboBox>
#include <QPushButton>

class ControlSettings_2 : public QWidget
{
    Q_OBJECT
public:
    explicit ControlSettings_2(QWidget *parent = nullptr);

signals:

private:
    QComboBox *w_trigFrequanceBox;
    QComboBox *w_trigOutBox;
    QComboBox *w_strobSizeBox;
    QPushButton *w_setSettings;


};

#endif // CONTROLSETTINGS_2_H
