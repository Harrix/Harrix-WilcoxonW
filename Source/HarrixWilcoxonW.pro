#-------------------------------------------------
#
# Project created by QtCreator 2013-09-29T16:45:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HarrixWilcoxonW
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mtrand.cpp \
    HarrixMathLibrary.cpp \
    HarrixQtLibrary.cpp

HEADERS  += mainwindow.h \
    mtrand.h \
    HarrixMathLibrary.h \
    HarrixQtLibrary.h

FORMS    += mainwindow.ui

win32:RC_FILE = myapp.rc
