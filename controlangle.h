#ifndef CONTROLANGLE_H
#define CONTROLANGLE_H

#include <QWidget>
#include <QDial>
#include <QLabel>

class ControlAngle : public QWidget
{
    Q_OBJECT
public:
    explicit ControlAngle(QWidget *parent = nullptr);

signals:

private:
    QDial *dialForAngle;
    QLabel *angleLabel;

private slots:
    void angleChanged(int position);

};

#endif // CONTROLANGLE_H
