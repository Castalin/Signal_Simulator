#ifndef SIGNALPLOT_H
#define SIGNALPLOT_H

#include <QWidget>
#include <QCheckBox>
#include "otherLibs/qcustomplot.h"

class SignalPlot : public QWidget
{
    Q_OBJECT
public:
    explicit SignalPlot(QWidget *parent = nullptr);


private:
    QCustomPlot *w_mainPlot;

    QCheckBox *w_checkBoxRePlot;
    QCheckBox *w_checkBoxImPlot;
    QCheckBox *w_checkBoxAbsPlot;

    int m_strobeSize;
    char m_GraphsCondition;

    enum graphs
    {
        REAL           = 0,
        IMAG           = 1,
        ABS            = 2,
    };

public slots:
    void slot_redrawReAndIm(const QVector<double> &signalRe, const QVector<double> &signalIm);
    void slot_redrawAbs(const QVector<double> &signalAbs);

private slots:
    void slot_checkRealPartState();
    void slot_checkImagPartState();
    void slot_checkABSPartState();

};

#endif // SIGNALPLOT_H
