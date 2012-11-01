#include <QtGui/QApplication>
#include <QWidget>
//#include "mainwindow.h"
#include "employee.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QWidget w;

    //w.show();

    qDebug() << Employee::getByID(4)->getEmailAddress();
    
    //return a.exec();
}
