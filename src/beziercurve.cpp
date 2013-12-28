#include "beziercurve.h"

BezierCurve::BezierCurve()
{

}

void BezierCurve::addPoint(QPoint* point)
{
    nodes.append(point);

    recalculate();
}

QVector<QPoint*> BezierCurve::getCurvePoints()
{
    return curvePoints;
}

QList<QPoint*> BezierCurve::getNodes()
{
    return nodes;
}

void BezierCurve::clear()
{
    curvePoints.clear();
    nodes.clear();
}

void BezierCurve::recalculate()
{
    if(nodes.size() < 2)
    {
        return;
    }

    curvePoints.clear();

    int n = nodes.size() - 1;
    double x = 0, y = 0;

    for(double t = 0; t <= 1; t += step)
    {
        for(int i = 0; i <= n; ++i)
        {
            x += nodes[i]->x() * (c(n, i) * pow(t, i) * pow((1 - t), n - i));
            y += nodes[i]->y() * (c(n, i) * pow(t, i) * pow((1 - t), n - i));
        }

        curvePoints.append(new QPoint(x, y));
        x = y = 0;
    }
}

int BezierCurve::c(int n, int k)
{
    double res = 1;

    for(int i = 1; i <= k; ++i)
    {
        res = res * (n - k + i) / i;
    }

    return (int)(res + 0.01);
}
