#include "signalplot.h"
#include <QVBoxLayout>

SignalPlot::SignalPlot(QWidget *parent)
    : QWidget{parent}, m_strobeSize{32}, m_GraphsCondition{0x00}
{
    QVBoxLayout *vectLayout = new QVBoxLayout();

    w_mainPlot = new QCustomPlot();
    w_mainPlot->setMinimumSize(QSize(500, 300));
    w_mainPlot->setSizePolicy(QSizePolicy :: Expanding , QSizePolicy :: Expanding);
    w_mainPlot->setInteractions(QCP :: Interaction :: iRangeDrag | QCP :: Interaction :: iRangeZoom);
    w_mainPlot->addGraph();
    w_mainPlot->graph(REAL)->setPen(QPen(QColor(Qt :: GlobalColor :: blue), 3, Qt :: PenStyle :: SolidLine));
    w_mainPlot->addGraph();
    w_mainPlot->graph(IMAG)->setPen(QPen(QColor(Qt :: GlobalColor :: red), 3, Qt :: PenStyle :: SolidLine));
    w_mainPlot->addGraph();
    w_mainPlot->graph(ABS)->setPen(QPen(QColor(Qt :: GlobalColor :: black), 3, Qt :: PenStyle :: SolidLine));

    for (int i{0}; i < 3; i++)
    {
        w_mainPlot->graph(i)->setData(QVector<double>(2048, 0.0), QVector<double>(2048, 0.0));
    }

    w_mainPlot->xAxis->grid()->setZeroLinePen(QPen(QColor(Qt :: GlobalColor :: red), 1.2));
    w_mainPlot->xAxis->setTickLength(7);
    w_mainPlot->xAxis->setSubTickLength(3);
    w_mainPlot->yAxis->setTickLength(7);
    w_mainPlot->yAxis->setSubTickLength(3);
    w_mainPlot->yAxis->grid()->setZeroLinePen(QPen(QColor(Qt :: GlobalColor :: red), 1.2));

    w_checkBoxRePlot = new QCheckBox(QString("Real"));
    w_checkBoxRePlot->setCheckState(Qt :: CheckState :: Unchecked);
    w_checkBoxImPlot = new QCheckBox(QString("Imag"));
    w_checkBoxImPlot->setCheckState(Qt :: CheckState :: Unchecked);
    w_checkBoxAbsPlot = new QCheckBox(QString("Abs"));
    w_checkBoxAbsPlot->setCheckState(Qt :: CheckState :: Unchecked);

    QHBoxLayout *horLayout = new QHBoxLayout();
    horLayout->addWidget(w_checkBoxRePlot, 0, Qt :: AlignCenter);
    horLayout->addWidget(w_checkBoxImPlot, 0, Qt :: AlignCenter);
    horLayout->addWidget(w_checkBoxAbsPlot, 0, Qt :: AlignCenter);
    //horLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy :: Expanding));

    connect(w_checkBoxRePlot, &QCheckBox :: stateChanged, this, &SignalPlot :: slot_checkRealPartState);
    connect(w_checkBoxImPlot, &QCheckBox :: stateChanged, this, &SignalPlot :: slot_checkImagPartState);
    connect(w_checkBoxAbsPlot, &QCheckBox :: stateChanged, this, &SignalPlot :: slot_checkABSPartState);

    vectLayout->addWidget(w_mainPlot);
    vectLayout->addLayout(horLayout);
    this->setLayout(vectLayout);
}

void SignalPlot::slot_checkRealPartState()
{
    m_GraphsCondition ^= (1 << REAL);
    w_mainPlot->graph(REAL)->setVisible(m_GraphsCondition & (1 << REAL));
    w_mainPlot->replot();
}

void SignalPlot::slot_checkImagPartState()
{
    m_GraphsCondition ^= (1 << IMAG);
    w_mainPlot->graph(IMAG)->setVisible(m_GraphsCondition & (1 << IMAG));
    w_mainPlot->replot();
}

void SignalPlot::slot_checkABSPartState()
{
    m_GraphsCondition ^= (1 << ABS);
    w_mainPlot->graph(ABS)->setVisible(m_GraphsCondition & (1 << ABS));
    w_mainPlot->replot();
}
