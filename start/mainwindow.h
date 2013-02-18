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
class EvaluationWin;

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

    //Working dir layout
    WinGroupBox*    workingDirBox;
    QPushButton*    selectDirButton;  //Select the working directory for the application
    QLabel*         workingDirLabel;  //Displays the working directory of the program

    EvaluationWin*  evaluationWinInstance;
private slots:
    void createNewEmployeeInit();
    void createNewEmployerInit();
    void newEvaluationInit();
    void assignEmployeeInit();
    void selectWorkingDir();
    void openPrintViewEmployee();
    void openPrintViewEmployer();
};

#endif // MAINWINDOW_H
