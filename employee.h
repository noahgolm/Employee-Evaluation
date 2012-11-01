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

    ~Employee(); // Deconstructor to delete self from list

    void setName(QString first, QString last); // Sets employee nam

    // Getters
    QString getFirstName(); // Gets employee first name
    QString getLastName(); // Get s employee last name

    static Employee* getByID(int id); // Gets an employee by Id

private:
    // Employee's name
    QString firstName;
    QString lastName;

    static QList<Employee*> employees; // List of all employees
};

#endif // EMPLOYEE_H
