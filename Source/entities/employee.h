/**
  * @file Employee.h
  * @brief Employee-specific properties extending the entity class.
  */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "entity.h"
#include <QList>
#include "evaluationdata.h"

/**
  * @class Employee
  * Entity with first and last name
  */

class Employer;

class Employee : public Entity
{
public:
    // Overriden constructors also add self to static list of employees
    Employee();
    Employee(int id);

    void setName(QString first, QString last); // Sets employee name
    void setCellNumber(QString cell);

    // Getters
    QString getFirstName(); // Gets employee first name
    QString getLastName(); // Get s employee last name
    QString getCellNumber();

    Employer getEmployer();
    EvaluationData getMostRecentEvaluation(); //Gets the most recent evaluation with julian calendar days

    int getOverallScore();

    //Operator for use with qSort, have to do an operator overload.
    friend bool operator< (const Employee &eOne, const Employee &eTwo) { return eOne.overallScore < eTwo.overallScore; }
private:
    int overallScore = 0; //Thanks C++11 for initalizing it here

    // Employee's name
    QString firstName;
    QString lastName;
    QString cellPhoneNumber; //Cell phone number
};

#endif // EMPLOYEE_H
