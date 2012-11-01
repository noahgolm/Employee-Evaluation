#include "employer.h"

/**
  * @class Employer
  * Entity with one company name
  */

QList<Employer*> Employer::employers; // Static declaration of employer list

/* Constructors here also add self to total list */
Employer::Employer() : Entity()
{
    employers.append(this);
}

Employer::Employer(int id) : Entity(id)
{
    employers.append(this);
}

/* Destructor removes self from list */
Employer::~Employer()
{
    employers.removeOne(this);
}

/* Sets employer name */
void Employer::setName(QString name)
{
    employerName = name;
}

/* Returns employer name */
QString Employer::getName()
{
    return employerName;
}

/* Static method to get an employer through their unique ID */
Employer* Employer::getByID(int id)
{
    foreach(Employer* emp, employers) // Iterate through all employers
    {
        if(emp->getID() == id) // Check if employer IDs match
            return emp;
    }
    return NULL;
}
