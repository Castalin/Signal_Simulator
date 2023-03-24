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
    double m_decimation;
    char m_GraphsCondition;
    const double c_lightSpeed;

    enum graphs
    {
        REAL           = 0,
        IMAG           = 1,
        ABS            = 2,
    };

    void countXAxis();

public slots:
    void slot_redrawReAndIm(const QVector<double> &signalRe, const QVector<double> &signalIm);
    void slot_redrawAbs(const QVector<double> &signalAbs);

private slots:
    void slot_checkRealPartState();
    void slot_checkImagPartState();
    void slot_checkABSPartState();

public:
    void setStrobeSize(int newStrobeSize);
    void setDecimation(int newDecimation);
};

#endif // SIGNALPLOT_H
