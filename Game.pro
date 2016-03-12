#-------------------------------------------------
#
# Project created by QtCreator 2016-01-24T14:21:06
#
#-------------------------------------------------

QT       += core gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game
TEMPLATE = app


SOURCES += main.cpp\
    roundone.cpp \
    spell.cpp \
    harry.cpp \
    dragon.cpp \
    fireball.cpp \
    egg.cpp \
    score.cpp \
    health.cpp \
    seaweed.cpp

HEADERS  += \
    roundone.h \
    spell.h \
    harry.h \
    dragon.h \
    fireball.h \
    egg.h \
    score.h \
    health.h \
    timer.h \
    seaweed.h

FORMS    +=

RESOURCES += \
    resources.qrc

CONFIG += c++11
