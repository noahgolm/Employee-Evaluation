#-------------------------------------------------
#
# Project created by QtCreator 2012-10-28T19:16:47
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RC_FILE = evaluator.rc

TARGET = Employee_Evaluator
TEMPLATE = app

INCLUDEPATH += entities/ \
    start \
    evaluation \
    datahandler \
    create \

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
    entities/evaluationdata.cpp \
    create/createemployeewin.cpp \
    create/labelfieldpair.cpp \
    create/createemployerwin.cpp \
    lists/viewemployees.cpp \
    lists/viewemployers.cpp \
    assignment/assignmentwin.cpp \
    reports/reportbox.cpp \
    reports/employeereportbox.cpp \
    reports/employerreportbox.cpp \
    reports/evaluationreportbox.cpp \
    reports/reportlist.cpp \
    printer/printer.cpp

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
    entities/evaluationdata.h \
    create/createemployeewin.h \
    create/labelfieldpair.h \
    create/createemployerwin.h \
    lists/viewemployees.h \
    lists/viewemployers.h \
    assignment/assignmentwin.h \
    reports/reportbox.h \
    reports/employeereportbox.h \
    reports/employerreportbox.h \
    reports/evaluationreportbox.h \
    reports/reportlist.h \
    printer/printer.h

FORMS    += mainwindow.ui

#static { # everything below takes effect with CONFIG += static
#    CONFIG += static
#    CONFIG += staticlib # this is needed if you create a static library, not a static executable
#    DEFINES += STATIC
#    message("~~~ static build ~~~") # this is for information, that the static build is done
#    mac: TARGET = $$join(TARGET,,,_static) #this adds an _static in the end, so you can seperate static build from non static build
#    win32: TARGET = $$join(TARGET,,,s) #this adds an s in the end, so you can seperate static build from non static build
#}

## change the nama of the binary, if it is build in debug mode
#CONFIG(debug, debug|release) {
#     mac: TARGET = $$join(TARGET,,,_debug)
#     win32: TARGET = $$join(TARGET,,,d)
#}
