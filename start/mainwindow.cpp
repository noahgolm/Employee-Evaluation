/**
  * @file MainWindow.cpp
  */

#include "mainwindow.h"
#include "evaluationwin.h"
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QDir>
#include "employee.h"
#include "wingroupbox.h"

//Entity type constants for slot/signal connections
#define E_EMPLOYEE 0
#define E_EMPLOYER 1



//Window size constants
const int winX = 600;
const int winY = 500;

/**
  * @brief Default constructor.
  */
MainWindow::MainWindow() :
    QWidget()
{
    //Setup main layout
    mainLayout = new QGridLayout();
    mainLayout->setHorizontalSpacing(50);
    mainLayout->setVerticalSpacing(50);
    setLayout(mainLayout);

    setFixedSize(winX, winY);

    initButtons();
    createBoxes();
    connectButtons();

    evaluationWinInstance = new EvaluationWin();

    workingDirLabel = new QLabel(QDir::currentPath());
    workingDirBox->layout()->addWidget(workingDirLabel);
}

void MainWindow::connectButtons()
{
    connect(viewEmployeesButton,     SIGNAL(released()), this, SLOT(openPrintViewEmployee()));
    connect(viewEmployersButton,     SIGNAL(released()), this, SLOT(openPrintViewEmployer()));
    connect(createNewEmployeeButton, SIGNAL(released()), this, SLOT(createNewEmployeeInit()));
    connect(createNewEmployerButton, SIGNAL(released()), this, SLOT(createNewEmployerInit()));
    connect(evaluationButton,        SIGNAL(released()), this, SLOT(newEvaluationInit()));
    connect(assignEmployeeButton,    SIGNAL(released()), this, SLOT(assignEmployeeInit()));
    connect(selectDirButton,         SIGNAL(released()), this, SLOT(selectWorkingDir()));
}

void MainWindow::createBoxes()
{
    //View selection
    viewSelectBox = new WinGroupBox("Select View", 2, viewEmployeesButton, viewEmployersButton);
    mainLayout->addWidget(viewSelectBox, 0, 0);

    //Create a new employee/employer
    createNewBox = new WinGroupBox("Create New", 2, createNewEmployeeButton, createNewEmployerButton);
    mainLayout->addWidget(createNewBox, 0, 1);

    //Create an evaluation
    evaluationBox = new WinGroupBox("Evaluation", 1, evaluationButton);
    mainLayout->addWidget(evaluationBox, 1, 0);

    //Employee assignment
    assignmentBox = new WinGroupBox("Assignment", 1,assignEmployeeButton);
    mainLayout->addWidget(assignmentBox, 1, 1);

    //Working file directory
    workingDirBox = new WinGroupBox("Working Directory", 1, selectDirButton);
    //mainLayout->addWidget(workingDirBox, 2, 1);
}

void MainWindow::initButtons()
{
    this->viewEmployeesButton = new QPushButton("View Employees");
    this->viewEmployersButton = new QPushButton("View Employers");

    createNewEmployeeButton = new QPushButton("Create New Employee");
    createNewEmployerButton = new QPushButton("Create new Employer");

    evaluationButton = new QPushButton("Select Employee...");

    assignEmployeeButton = new QPushButton("Assign Employee");

    selectDirButton  = new QPushButton("Select Directory");
}

void MainWindow::newEvaluationInit()
{
    // Check if there is not an instance already open.
    // If there isn't, create a new one and instantiate it.
    if(!evaluationWinInstance->isVisible())
    {
        evaluationWinInstance->close();
        evaluationWinInstance = new EvaluationWin();
    }

    evaluationWinInstance->show();
}

void MainWindow::createNewEmployeeInit()
{

}

void MainWindow::createNewEmployerInit()
{

}

void MainWindow::assignEmployeeInit()
{

}

void MainWindow::selectWorkingDir()
{

}

void MainWindow::openPrintViewEmployee()
{

}

void MainWindow::openPrintViewEmployer()
{

}
