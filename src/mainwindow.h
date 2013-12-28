#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGLWidget>
#include <QMouseEvent>
#include <QPoint>

#include "beziercurve.h"

class MainWindow : public QGLWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);

private:
    bool captureNode(QPoint pos);

    void drawNodes();
    void drawCurve();

private:
    BezierCurve* curve;

    bool isPressed;
    QPoint* capturedNode;
};

#endif // MAINWINDOW_H
