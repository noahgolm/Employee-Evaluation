/**
  * @file MainWindow.cpp
  */

#include "mainwindow.h"
#include "selectemployee.h"
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include "employee.h"
#include "wingroupbox.h"
#include "createemployeewin.h"
#include "createemployerwin.h"
#include "lists/viewemployees.h"
#include "lists/viewemployers.h"
#include "assignment/assignmentwin.h"
#include "datainterface.h"
#include <QMessageBox>
#include <QList>
#include <QCheckBox>
#include "reports/reportlist.h"

//Window size constants
const int winX = 600;
const int winY = 500;

/**
  * @brief Default constructor.
  */
MainWindow::MainWindow() :
    QWidget()
{
    this->setWindowTitle("MMT Employee Evaluator");

    //Setup main layout
    mainLayout = new QGridLayout();
    mainLayout->setHorizontalSpacing(50);
    mainLayout->setVerticalSpacing(50);
    setLayout(mainLayout);

    setFixedSize(winX, winY);

    initButtons();
    createBoxes();
    connectButtons();

    selectEmployeeWinInstance = new SelectEmployee(true);
    selectEmployeeEvalWinInstance = new SelectEmployee(false);
    createEmployeeWinInstance = new CreateEmployeeWin();
    createEmployerWinInstance = new CreateEmployerWin();
    employeeReportListWinInstance  = new ReportList(ReportList::employee, 0);
    employerReportListWinInstance  = new ReportList(ReportList::employer, 0);



}

void MainWindow::connectButtons()
{
    connect(viewEmployeesButton,     SIGNAL(released()), this, SLOT(openPrintViewEmployee()));
    connect(viewEmployersButton,     SIGNAL(released()), this, SLOT(openPrintViewEmployer()));
    connect(viewEvaluationButton,    SIGNAL(released()), this, SLOT(openPrintViewEvaluation()));
    connect(createNewEmployeeButton, SIGNAL(released()), this, SLOT(createNewEmployeeInit()));
    connect(createNewEmployerButton, SIGNAL(released()), this, SLOT(createNewEmployerInit()));
    connect(evaluationButton,        SIGNAL(released()), this, SLOT(newEvaluationInit()));
    connect(assignEmployeeButton,    SIGNAL(released()), this, SLOT(assignEmployeeInit()));
}

void MainWindow::createBoxes()
{
    //View selection
    viewSelectBox = new WinGroupBox("Select View", 3, viewEmployeesButton, viewEmployersButton, viewEvaluationButton);
    sortByScoreBox = new QCheckBox("Sort employees by average score.");
    viewSelectBox->layout()->addWidget(sortByScoreBox);
    mainLayout->addWidget(viewSelectBox, 0, 0);

    //Create a new employee/employer
    createNewBox = new WinGroupBox("Create New", 2, createNewEmployeeButton, createNewEmployerButton);
    mainLayout->addWidget(createNewBox, 0, 1);

    //Create an evaluation
    evaluationBox = new WinGroupBox("Evaluation", 1, evaluationButton);
    mainLayout->addWidget(evaluationBox, 1, 0);

    //Employee assignment
    assignmentBox = new WinGroupBox("Assignment", 1, assignEmployeeButton);
    mainLayout->addWidget(assignmentBox, 1, 1);
}

void MainWindow::initButtons()
{
    this->viewEmployeesButton = new QPushButton("View Employees");
    this->viewEmployersButton = new QPushButton("View Employers");
    this->viewEvaluationButton = new QPushButton("View Evaluation...");

    createNewEmployeeButton = new QPushButton("Create New Employee");
    createNewEmployerButton = new QPushButton("Create new Employer");

    evaluationButton = new QPushButton("Select Employee for Evaluation...");

    assignEmployeeButton = new QPushButton("Assign Employee to an Employer");
}

void MainWindow::newEvaluationInit()
{
    //Check for valid employees/employers
    if(DataInterface::getEmployees().size() == 0)
    {
        QMessageBox::information(this, "No Employees Available", "There are no employees to evaluate.");
        return;
    }

    // Check if there is not an instance already open.
    // If there isn't, create a new one and instantiate it.
    if(!selectEmployeeWinInstance->isVisible())
    {
        selectEmployeeWinInstance->close();
        selectEmployeeWinInstance = new SelectEmployee(true);
    }

    selectEmployeeWinInstance->show();
}

void MainWindow::createNewEmployeeInit()
{
    if(!createEmployeeWinInstance->isVisible())
    {
        createEmployeeWinInstance->close();
        createEmployeeWinInstance = new CreateEmployeeWin();
    }

    createEmployeeWinInstance->show();
}

void MainWindow::createNewEmployerInit()
{
    if(!createEmployerWinInstance->isVisible())
    {
        createEmployerWinInstance->close();
        createEmployerWinInstance = new CreateEmployerWin();
    }

    createEmployerWinInstance->show();

}

void MainWindow::assignEmployeeInit()
{
    //Check for valid employees/employers
    if(DataInterface::getEmployees().size() == 0)
    {
        QMessageBox::information(this, "No Employees Available", "There are no employees to assign.");
        return;
    }

    if(DataInterface::getEmployers().size() == 0)
    {
        QMessageBox::information(this, "No Employers Available", "There are no employers to assign.");
        return;
    }

    AssignmentWin *assWin = new AssignmentWin();
    assWin->show();

}

void MainWindow::openPrintViewEmployee()
{
    //Check for valid employees/employers
    if(DataInterface::getEmployees().size() == 0)
    {
        QMessageBox::information(this, "No Employees Available", "There are no employees to view.");
        return;
    }

    if(!employeeReportListWinInstance->isVisible())
    {
        employeeReportListWinInstance->close();
        employeeReportListWinInstance = new ReportList(ReportList::employee, sortByScoreBox->isChecked(), 0);
    }

    employeeReportListWinInstance->show();
}

void MainWindow::openPrintViewEmployer()
{
    if(DataInterface::getEmployers().size() == 0)
    {
        QMessageBox::information(this, "No Employers Available", "There are no employers to view.");
        return;
    }

    if(!employerReportListWinInstance->isVisible())
    {
        employerReportListWinInstance->close();
        employerReportListWinInstance = new ReportList(ReportList::employer, 0);
    }

    employerReportListWinInstance->show();
}

void MainWindow::openPrintViewEvaluation()
{
    //Check for valid employees/employers
    if(DataInterface::getEmployees().size() == 0)
    {
        QMessageBox::information(this, "No Employees Available", "There are no employees to evaluate.");
        return;
    }

    if(DataInterface::getEvaluations().size() == 0)
    {
        QMessageBox::information(this, "No Evaluations Available", "There are no evaluations to display.");
        return;
    }

    // Check if there is not an instance already open.
    // If there isn't, create a new one and instantiate it.
    if(!selectEmployeeEvalWinInstance->isVisible())
    {
        selectEmployeeEvalWinInstance->close();
        selectEmployeeEvalWinInstance = new SelectEmployee(false);
    }

    selectEmployeeEvalWinInstance->show();

}
