#-------------------------------------------------
#
# Project created by QtCreator 2016-12-04T14:31:29
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PK_AVR_Calculator
TEMPLATE = app

RESOURCES += \
    resources.qrc

SOURCES += main.cpp\
        mainwindow.cpp \
    lpt_schematic.cpp \
    kanda_schematic.cpp \
    attiny_con_schematic.cpp \
    ubrr_calculator.cpp

HEADERS  += mainwindow.h \
    lpt_schematic.h \
    kanda_schematic.h \
    attiny_con_schematic.h \
    ubrr_calculator.h

FORMS    += mainwindow.ui \
    lpt_schematic.ui \
    kanda_schematic.ui \
    attiny_con_schematic.ui \
    ubrr_calculator.ui
