#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signalsui.h"
#include "controlsettings_1.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    signalsUI *m_signalUI;
    ControlSettings_1 *m_ctrSettings_1;
};
#endif // MAINWINDOW_H
