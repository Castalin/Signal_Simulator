#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_signalUI = new signalsUI;
    m_ctrSettings_1 = new ControlSettings_1;
    m_ctrSettings_2 = new ControlSettings_2;
    m_adc_Delay = new ADC_Delay;
    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QGridLayout *mainLayout = new QGridLayout;
    //QVBoxLayout *secondColumn = new QVBoxLayout;


    mainLayout->addWidget(m_signalUI, 0, 0, 6, 5);

    //secondColumn->addWidget(m_ctrSettings_1);
    //secondColumn->addWidget(m_ctrSettings_2);
    //secondColumn->addWidget(m_adc_Delay);
    //mainLayout->addLayout(secondColumn, 0, 6);
    mainLayout->setVerticalSpacing(1);
    mainLayout->addWidget(m_ctrSettings_1, 0, 6, 4, 4);
    mainLayout->addWidget(m_ctrSettings_2, 4, 6, 2, 4, Qt :: AlignTop);
    mainLayout->addWidget(m_adc_Delay, 6, 6, 1, 4, Qt :: AlignTop);
    mainLayout->setVerticalSpacing(1);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);


}

MainWindow::~MainWindow()
{
}

