#ifndef DATASENDER_H
#define DATASENDER_H

#include "settingssender.h"
#include <QThread>
#include <QMutex>

class DataSender : public QThread, public SettingsSender
{
    Q_OBJECT
public:
    explicit DataSender(QByteArray *ptrToData, QObject *parent = nullptr);


private:
    QMutex *m_mutex;
    bool m_workingThreadEnable;
    void run() override;
    bool isWorking();
    const QByteArray *m_ptrToData;
    const int m_sleepArray[4]{1000 - 8, 500 - 8, 333 - 8, 250 - 8};
    int m_sleepValue;
    int m_numberOfPackage;

    int m_sentMessages = 0;

public:
    void startThread();
    void stopThread();
    void sleepValueChanged(int i);
    void setAddressSettings(const QString &address, const int &port) override;
    void messagePrepared(const int &numberOfPackage);



signals:
    void signal_MessageSended(const int num);



};

#endif // DATASENDER_H
