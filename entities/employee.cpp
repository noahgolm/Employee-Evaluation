/**
  * @file Employee.cpp
  */

#include "employee.h"
#include "entity.h"

/**
  * @class Employee
  * Entity with first and last name
  */


Employee::Employee(int id) : Entity(id)
{
}

Employee::Employee() : Entity()
{
}


void Employee::setName(QString first, QString last)
{
    this->firstName = first;
    this->lastName = last;
}

void Employee::setCellNumber(QString cell)
{
    this->cellPhoneNumber = cell;
}

QString Employee::getFirstName()
{
    return firstName;
}

QString Employee::getLastName()
{
    return lastName;
}

QString Employee::getCellNumber()
{
    return cellPhoneNumber;
}
