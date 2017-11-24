#-------------------------------------------------
#
# Project created by QtCreator 2017-11-01T09:14:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
INCLUDEPATH += $$PWD
TARGET = Othello
TEMPLATE = app
CONFIG+= static

SOURCES += main.cpp\
        othello.cpp \
    Posicion.cpp \
    Tablero.cpp

HEADERS  += othello.h \
    Lista.h

FORMS    += othello.ui
