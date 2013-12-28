#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QGLWidget(parent)
{
    curve = new BezierCurve();
    isPressed = false;
}

void MainWindow::initializeGL()
{
    qglClearColor(Qt::black);
}

void MainWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, h, 0, -1, 1);
}

void MainWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPointSize(5.0f);
    glLineWidth(2.0f);

    drawCurve();
    drawNodes();
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        isPressed = true;
        if(!(captureNode(event->pos())))
        {
            curve->addPoint(new QPoint(event->pos()));
        }
        updateGL();
        break;
    case Qt::RightButton:
        curve->clear();
        updateGL();
        break;
    default:
        break;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    switch(event->button())
    {
    case Qt::LeftButton:
        isPressed = false;
        capturedNode = nullptr;
        break;
    default:
        break;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(isPressed && capturedNode != nullptr)
    {
        capturedNode->setX(event->x());
        capturedNode->setY(event->y());

        curve->recalculate();

        updateGL();
    }
}

void MainWindow::drawNodes()
{
    glColor3f(0, 1, 0);

    glBegin(GL_POINTS);

    foreach(QPoint* point, curve->getNodes())
    {
        glVertex3f(point->x(), point->y(), 0);
    }

    glEnd();
}

void MainWindow::drawCurve()
{
    glColor3f(1, 0, 0);

    glBegin(GL_LINE_STRIP);

    foreach(QPoint* point, curve->getCurvePoints())
    {
        glVertex3f(point->x(), point->y(), 0);
    }

    glEnd();
}

bool MainWindow::captureNode(QPoint pos)
{
    QList<QPoint*> nodes = curve->getNodes();
    for(int i = 0; i < nodes.size(); i++)
    {
        if(abs(pos.x() - nodes[i]->x()) < 10 && abs(pos.y() - nodes[i]->y()) < 10)
        {
            capturedNode = nodes[i];

            return true;
        }
    }

    return false;
}

