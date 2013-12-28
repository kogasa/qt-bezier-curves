#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QVector>
#include <QList>
#include <QPoint>

#include <cmath>

class BezierCurve
{
public:
    BezierCurve();

    void addPoint(QPoint* point);
    QVector<QPoint*> getCurvePoints();
    QList<QPoint*> getNodes();

    void recalculate();

    void clear();

private:
    int c(int n, int k);

private:
    QList<QPoint*> nodes;
    QVector<QPoint*> curvePoints;

    const double step = 0.01;
};

#endif // BEZIERCURVE_H
