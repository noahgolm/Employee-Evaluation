#ifndef ENTITY_H
#define ENTITY_H

#include <QString>

/**
  * @class Entity
  * @abstract Base class for the employer and employee classes
  */
class Entity
{
public:
    Entity(); // Default constructor
    Entity(int id); // Constructor with ID

    // Setter methods for properties
    void setID(int id);
    void setEmailAddress(QString email);
    void setPhoneNumber(QString number);
    void setLocation(QString address, QString c, QString s, QString zip);

    // Getter methods for properties
    int getID();
    QString getEmailAddress();
    QString getPhoneNumber();
    QString getStreetAddress();
    QString getCity();
    QString getState();
    QString getZipCode();

private:
    int uniqueID; // Unique entity identifier
    QString emailAddress; // Email address
    QString phoneNumber; // Phone number
    QString streetAddress, city, state, zipCode; // Address and location information
};

#endif // ENTITY_H
