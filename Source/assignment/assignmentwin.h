/**
 * @file AssignmentWin.h
 */

#ifndef ASSIGNMENTWIN_H
#define ASSIGNMENTWIN_H

#include <QWidget>

//Forward declarations
class ViewEmployees;
class ViewEmployers;
class QPushButton;

/**
 * @class AssignmentWin
 * @brief Window to assign an employee to an employer.
 */

class AssignmentWin : public QWidget
{
    Q_OBJECT
public:
    explicit AssignmentWin(QWidget *parent = 0);
    
private:
    ViewEmployees* employeeView; //Table view to hold the employees
    ViewEmployers* employerView; //Table view to hold the employers
    QPushButton*   finishButton; //Button to finish and pair them
public slots:
    void savePairing(); //Saves the pairing once the finish button is pressed
    
};

#endif // ASSIGNMENTWIN_H
