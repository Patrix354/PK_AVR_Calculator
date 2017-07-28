#-------------------------------------------------
#
# Project created by QtCreator 2017-05-16T23:33:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = PKAvrCalculator
TEMPLATE = app
CONFIG += console

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
        mainwindow.cpp \
    attiny_con_schematic.cpp \
    kanda_schematic.cpp \
    lpt_schematic.cpp \
    ubrr_calculator.cpp \
    gamma_corection.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    attiny_con_schematic.h \
    kanda_schematic.h \
    lpt_schematic.h \
    ubrr_calculator.h \
    gamma_corection.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    attiny_con_schematic.ui \
    kanda_schematic.ui \
    lpt_schematic.ui \
    ubrr_calculator.ui \
    gamma_corection.ui

RESOURCES += \
    resource.qrc

DISTFILES += \
    PKAvrCalculator.pro.user
