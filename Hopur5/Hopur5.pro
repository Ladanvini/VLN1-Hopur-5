QT += core
QT -= gui
QT += core sql

CONFIG += c++11

TARGET = Hopur5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    consoleui.cpp \
    database.cpp \
    person.cpp \
    appservice.cpp \
    comps.cpp \
    compservice.cpp \
    computerui.cpp

DISTFILES += \
    database \
    database.txt

HEADERS += \
    consoleui.h \
    database.h \
    person.h \
    appservice.h \
    comps.h \
    compservice.h \
    computerui.h
