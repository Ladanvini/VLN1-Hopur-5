QT += core
QT -= gui

CONFIG += c++11

TARGET = Hopur5
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    database.cpp \
    person.cpp \
    process.cpp \
    consoleui.cpp

HEADERS += \
    database.h \
    person.h \
    process.h \
    consoleui.h

DISTFILES += \
    database \
    database.txt
