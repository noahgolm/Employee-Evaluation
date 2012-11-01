#include "employee.h"
#include "entity.h"

/**
  * @class Employee
  * Entity with first and last name
  */

QList<Employee*> Employee::employees; // Static declaration of employee list


Employee::Employee(int id) : Entity(id)
{
    employees.append(this);
}

Employee::Employee() : Entity()
{
    employees.append(this);
}

/* Overriden destructor removes self from total list */
Employee::~Employee()
{
    employees.removeOne(this);
}

/* Static method to return an employee through an ID number */
Employee* Employee::getByID(int id)
{
    foreach(Employee* emp, employees) // Iterate through all employees
    {
        if(emp->getID() == id) // Check if IDs match
            return emp;
    }
    return NULL;
}
