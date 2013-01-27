/**
  * @file main.cpp
  * The main class of the program. Launches the main window.
  */

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "employee.h"
#include "evaluationwin.h"

int main(int argc, char *argv[])
{
    //Instantiate application and the main window.
    QApplication a(argc, argv);
    MainWindow w;

    EvaluationWin gw;
    gw.show();

    //Execute the application.
    return a.exec();
}
