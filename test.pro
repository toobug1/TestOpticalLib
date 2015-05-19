#-------------------------------------------------
#
# Project created by QtCreator 2015-05-14T08:30:48
#
#-------------------------------------------------

QT       += core gui

TARGET = test
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

#LIBS += -lgsl \
#        -lgslcblas

#INCLUDEPATH += C:/QT/Qt5.4.1/Tools/mingw491_32/include

win32: LIBS += -L$$PWD/../../../../QtProject/ProjectSrc/OpticalLib/build-Debug/debug/ -lopticalLib

INCLUDEPATH += $$PWD/../OpticalLib
DEPENDPATH += $$PWD/../OpticalLib


