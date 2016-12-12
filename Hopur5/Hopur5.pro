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
    links.cpp \
    linkservice.cpp \
    tictactoe.cpp \
    unicorn.cpp \
    fcacs.cpp

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
    links.h \
    linkservice.h \
    tictactoe.h \
    unicorn.h \
    fcacs.h

FORMS += \
    fcacs.ui
