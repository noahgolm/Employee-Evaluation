/**
  * @file MainWindow.h
  * @brief Contains the main window of the program.
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>

//Forward declarations
class QVBoxLayout;
class QTabWidget;
class QStatusBar;

class MainWindow : public QMainWindow
{
public:
    MainWindow(); //Main constructor.
private:
    QVBoxLayout* layout; //Holds the layout of the main window.
    QTabWidget*  evaluationTabs; //Contains each new instance of Evaluation as a tabbed widget.
};

#endif // MAINWINDOW_H
