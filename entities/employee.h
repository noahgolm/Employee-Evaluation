/**
  * @file Employee.h
  * @brief Employee-specific properties extending the entity class.
  */
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "entity.h"
#include <QList>

/**
  * @class Employee
  * Entity with first and last name
  */

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

private:
    // Employee's name
    QString firstName;
    QString lastName;
    QString cellPhoneNumber; //Cell phone number
};

#endif // EMPLOYEE_H
