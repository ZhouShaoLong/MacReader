#-------------------------------------------------
#
# Project created by QtCreator 2017-05-17T15:46:19
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MacReader
TEMPLATE = app

# 调用python
INCLUDEPATH += -I /usr/include/python2.7
LIBS += -L /usr/lib -lpython2.7

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#icon
ICON =


SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    registdialog.cpp \
    netmanager.cpp \
    textmanage.cpp \
    displaydialog.cpp \
    ftpmanager.cpp \
    usermessage.cpp \
    mybutton.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    registdialog.h \
    netmanager.h \
    textmanage.h \
    displaydialog.h \
    ftpmanager.h \
    usermessage.h \
    mybutton.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    registdialog.ui \
    displaydialog.ui

RESOURCES += \
    image.qrc \
    qss.qrc

DISTFILES += \
    Decode.py
