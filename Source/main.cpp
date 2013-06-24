/**
  * @file main.cpp
  * The main class of the program. Launches the main window.
  */

#include <QApplication>
#include "mainwindow.h"
#include "datainterface.h"

int main(int argc, char *argv[])
{
    //Instantiate application and the main window.
    QApplication a(argc, argv);

    //Instantiate the data interface class to use our files.
    DataInterface::init();

    MainWindow m;
    m.show();

    //Execute the application.
    return a.exec();
}
