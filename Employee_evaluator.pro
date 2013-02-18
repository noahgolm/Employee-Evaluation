#-------------------------------------------------
#
# Project created by QtCreator 2012-10-28T19:16:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Employee_Evaluator
TEMPLATE = app

INCLUDEPATH += entities/ \
    start \
    evaluation \
    datahandler \

SOURCES += main.cpp \
    entities/entity.cpp \
    entities/employee.cpp \
    entities/employer.cpp \
    start/mainwindow.cpp \
    evaluation/evaluation.cpp \
    evaluation/evaluationwin.cpp \
    evaluation/generalevaluation.cpp \
    evaluation/selectemployee.cpp \
    start/wingroupbox.cpp \
    datahandler/datainterface.cpp \
    entities/evaluationdata.cpp

HEADERS  += \
    entities/entity.h \
    entities/employee.h \
    entities/employer.h \
    start/mainwindow.h \
    evaluation/evaluation.h \
    evaluation/evaluationwin.h \
    evaluation/generalevaluation.h \
    evaluation/selectemployee.h \
    start/wingroupbox.h \
    datahandler/datainterface.h \
    entities/evaluationdata.h

FORMS    += mainwindow.ui

static { # everything below takes effect with CONFIG += static
    CONFIG += static
    CONFIG += staticlib # this is needed if you create a static library, not a static executable
    DEFINES += STATIC
    message("~~~ static build ~~~") # this is for information, that the static build is done
    mac: TARGET = $$join(TARGET,,,_static) #this adds an _static in the end, so you can seperate static build from non static build
    win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from non static build
}

# change the nama of the binary, if it is build in debug mode
CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
}
