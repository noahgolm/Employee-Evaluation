/**
  * @file Employer.h
  * @brief Employer-specific properties working as an extension of the entity class.
  */

#ifndef EMPLOYER_H
#define EMPLOYER_H

#include "entity.h"
#include <QList>

/**
  * @class Employer
  * Entity with one company name
  */

class Employer : public Entity
{
public:
    // Overriden constructors also add self to static list of employers
    Employer();
    Employer(int id);

    void setName(QString name); // Sets employer name
    void setContact(QString contactPerson);
    QString getName(); // Returns company name
    QString getContact(); // Returns the company contact person
private:
    QString employerName;
    QString contactPerson;
};

#endif // EMPLOYER_H
