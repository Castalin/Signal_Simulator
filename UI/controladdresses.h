#ifndef CONTROLADDRESSES_H
#define CONTROLADDRESSES_H

#include <QWidget>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QUdpSocket>

class ControlAddresses : public QWidget
{
    Q_OBJECT
public:
    explicit ControlAddresses(QWidget *parent = nullptr);

signals:
    void signal_setControlSettings(const QString &address, const int &sendPort);
    void signal_startControlThread(const QString &address, const int &receiverPort);
    void signal_stopControlThread();

    //void signal_setSignalSettings(const QHostAddress &address, const int &sendPort);

private:
    QLineEdit *w_PCAddress;
    QSpinBox *w_PCDataPort;
    QSpinBox *w_PCControlPort;

    QLineEdit *w_BoardAddress;
    QSpinBox *w_BoardDataPort;
    QSpinBox *w_BoardControlPort;

    QPushButton *w_setSettings;
    QPushButton *w_startReceiving;
    QPushButton *w_stopReceiving;


    QHostAddress getBoardAddress();
    int getBoardDataPort();
    int getBoardControlPort();
    QHostAddress getPCAddress();
    int getPCDataPort();
    int getPCControlPort();

private slots:
    void slot_setControlSettings();
    void slot_startControlThread();
    void slot_stopControlThread();


};

#endif // CONTROLADDRESSES_H
