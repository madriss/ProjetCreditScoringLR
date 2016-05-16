#-------------------------------------------------
#
# Project created by QtCreator 2016-04-17T17:47:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetCPP
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++11
LIBS += -lmlpack
LIBS += -larmadillo
LIBS += -llapack
LIBS += -lblas
SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
