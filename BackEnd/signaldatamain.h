#ifndef SIGNALDATAMAIN_H
#define SIGNALDATAMAIN_H

#include <QObject>
#include "datasender.h"

class SignalDataMain : public QObject
{
    Q_OBJECT
public:
    explicit SignalDataMain(QObject *parent = nullptr);

signals:
    void signal_angleValueChanged(const double &value);

private:
    QByteArray *m_Message;
    DataSender *m_DataSender;



public slots:
    void slot_setAddressSettings(const QString &address, const int &port);
    void slot_angleChanged(const double &value);
    void slot_angleSpeedChanged(const double &value);
    void slot_RxEnableValueChanged(const unsigned char &sentData);
    void slot_startSourceScale(const unsigned char &info);

};

#endif // SIGNALDATAMAIN_H
