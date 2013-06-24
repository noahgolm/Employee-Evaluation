/**
  * @file MainWindow.h
  * @brief Contains the main window of the program.
  */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "wingroupbox.h"

//Forward declarations
class QVBoxLayout;
class QPushButton;
class QLabel;
class QGroupBox;
class QGridLayout;
class SelectEmployee;
class CreateEmployeeWin;
class CreateEmployerWin;
class ViewEmployees;
class ViewEmployers;
class ReportList;
class QCheckBox;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    MainWindow(); //Main constructor.
private:
    QGridLayout* mainLayout; //Main layout of the window

    void createBoxes();
    void initButtons();
    void connectButtons();

    //View layout
    WinGroupBox*    viewSelectBox;
    QPushButton*    viewEmployeesButton;
    QPushButton*    viewEmployersButton;
    QPushButton*    viewEvaluationButton;

    //"Create new" layout
    WinGroupBox*    createNewBox;
    QPushButton*    createNewEmployeeButton;
    QPushButton*    createNewEmployerButton;

    //Evaluation layout
    WinGroupBox*    evaluationBox;
    QPushButton*    evaluationButton;

    //Button to assign an employee to an employer
    WinGroupBox*    assignmentBox;
    QPushButton*    assignEmployeeButton;

    //Instances of the windows to make sure we only have one open at a time.
    SelectEmployee*       selectEmployeeWinInstance;
    SelectEmployee*       selectEmployeeEvalWinInstance;
    CreateEmployeeWin*    createEmployeeWinInstance;
    CreateEmployerWin*    createEmployerWinInstance;
    ReportList*           employeeReportListWinInstance;
    ReportList*           employerReportListWinInstance;

    QCheckBox*  sortByScoreBox;
private slots:
    void createNewEmployeeInit();
    void createNewEmployerInit();
    void newEvaluationInit();
    void assignEmployeeInit();
    void openPrintViewEmployee();
    void openPrintViewEmployer();
    void openPrintViewEvaluation();
};

#endif // MAINWINDOW_H
