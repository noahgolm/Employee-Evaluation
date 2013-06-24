/**
  * @file Employer.cpp
  */

#include "employer.h"

/**
  * @class Employer
  * Entity with one company name
  */

/* Constructors here also add self to total list */
Employer::Employer() : Entity()
{
}

Employer::Employer(int id) : Entity(id)
{
}

/* Sets employer name */
void Employer::setName(QString name)
{
    employerName = name;
}

/* Sets employer contact person */
void Employer::setContact(QString contactPerson)
{
    this->contactPerson = contactPerson;
}

/* Returns employer name */
QString Employer::getName()
{
    return employerName;
}

/* Returns employer contact person */
QString Employer::getContact()
{
    return contactPerson;
}
