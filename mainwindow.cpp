#include "mainwindow.h"
#include <QGroupBox>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_signalUI = new signalsUI;
    m_ctrSettings_1 = new ControlSettings_1;
    QGroupBox *mainWidget = new QGroupBox(QString("  Signal Simulator"));
    QGridLayout *mainLayout = new QGridLayout;

    mainLayout->addWidget(m_signalUI, 0, 0, 6, 5);
    mainLayout->addWidget(m_ctrSettings_1, 0, 6, 5, 4);
    mainWidget->setLayout(mainLayout);
    this->setCentralWidget(mainWidget);


}

MainWindow::~MainWindow()
{
}

