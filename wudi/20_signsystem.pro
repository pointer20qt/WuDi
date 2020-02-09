#-------------------------------------------------
#
# Project created by QtCreator 2020-02-06T16:26:40
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 20_signsystem
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    person.cpp \
    login.cpp \
    signup.cpp

HEADERS  += widget.h \
    person.h \
    login.h \
    signup.h

FORMS    += widget.ui \
    person.ui \
    login.ui \
    signup.ui

RESOURCES += \
    back/back.qrc \
    back2/back2.qrc
