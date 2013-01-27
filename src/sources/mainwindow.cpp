/**
  * @file MainWindow.cpp
  */

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QStatusBar>
#include "evaluation.h"
#include <QLabel>
#include <QStatusBar>

//Window size constants
const int winX = 450;
const int winY = 500;

//Status bar size
const int statusX = winX;
const int statusY = 50;

/**
  * @brief Default constructor.
  */
MainWindow::MainWindow() :
    QMainWindow()
{


}
