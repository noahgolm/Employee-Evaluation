#include "entity.h"
#include <QString>

/**
  * @class Entity
  * Base class for the employer and employee classes
  */

/** Default Constructor */
Entity::Entity()
{
}

/**
  * Constructor with instantiation of ID
  * @param id Unique ID of entity
  */
Entity::Entity(int id)
{
    setID(id);
}

/**** Setters ****/

void Entity::setID(int id)
{
    uniqueID = id;
}

void Entity::setEmailAddress(QString email)
{
    emailAddress = email;
}

void Entity::setPhoneNumber(QString number)
{
    emailAddress = number;
}

/**
  * @name setLocation
  * Collectively sets all location info (reduces unneccessary getters/setters)
  */
void Entity::setLocation(QString address, QString c, QString s, QString zip)
{
    streetAddress = address;
    city = c;
    state = s;
    zipCode = zip;
}

/**** Getters ****/


int Entity::getID()
{
    return uniqueID;
}

QString Entity::getEmailAddress()
{
    return emailAddress;
}

QString Entity::getPhoneNumber()
{
    return phoneNumber;
}

QString Entity::getStreetAddress()
{
    return streetAddress;
}

QString Entity::getCity()
{
    return city;
}

QString Entity::getState()
{
    return state;
}

QString Entity::getZipCode()
{
    return zipCode;
}
