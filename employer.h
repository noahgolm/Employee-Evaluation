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

    ~Employer(); // Deconstructor to delete self from list

    void setName(QString name); // Sets employer name

    static Employer* getByID(int id); // Static method to get employer by ID

    QString getName(); // Returns company name
private:
    QString employerName;
    static QList<Employer*> employers;
};

#endif // EMPLOYER_H
