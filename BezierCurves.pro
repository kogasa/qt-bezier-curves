#-------------------------------------------------
#
# Project created by QtCreator 2013-12-28T09:43:45
#
#-------------------------------------------------

QT       += core opengl

QT       -= gui

TARGET = BezierCurves
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += src/main.cpp \
    src/mainwindow.cpp \
    src/beziercurve.cpp

HEADERS += \
    src/mainwindow.h \
    src/beziercurve.h
