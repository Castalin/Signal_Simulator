#include "allplotsui.h"

AllPlotsUI::AllPlotsUI(SignalGenerator * const signalGenerator, QVector<QByteArray*> * const arraySignal, QWidget *parent)
    : QWidget{parent}, m_signalGenerator{signalGenerator}, m_sendedMessage{arraySignal}
{
    QHBoxLayout *horLayout = new QHBoxLayout;
    m_signalPlot = new SignalPlot;

    horLayout->addWidget(m_signalPlot);
    setLayout(horLayout);

    m_mutex = new QMutex;
    m_timer = new QTimer;
}

AllPlotsUI::~AllPlotsUI()
{
    delete m_mutex;
    delete m_timer;
}
