#-------------------------------------------------
#
# Project created by QtCreator 2024-04-05T09:31:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = invoided
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    login.cpp \
    page1.cpp

HEADERS  += mainwindow.h \
    login.h \
    page1.h \
    global_login.h

FORMS    += mainwindow.ui \
    login.ui \
    page1.ui

DISTFILES += \
    background.jpeg \
    images/background.jpeg \
    images/401182.png

RESOURCES += \
    resources.qrc

RC_ICONS = 7572360.ico
