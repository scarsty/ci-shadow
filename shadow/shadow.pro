#-------------------------------------------------
#
# Project created by QtCreator 2022-05-07T11:24:51
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = shadow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp\
        D:/project/nb/PotConv.cpp\
        D:/project/nb/convert.cpp

HEADERS  += mainwindow.h

INCLUDEPATH += D:/project/lib-collection/include/opencv45
INCLUDEPATH += D:/project/microsoft/vcpkg/installed/x64-windows/include D:/project/ddtest/ddtest
INCLUDEPATH += D:/project/nb/
LIBS += -LD:/project/lib-collection/lib/x64 -lopencv_world454
LIBS += -LD:/project/microsoft/vcpkg/installed/x64-windows/lib -lfreetype -liconv

FORMS    += mainwindow.ui
