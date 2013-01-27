/**
  * @file Entity.cpp
  */

#include "entity.h"
#include <QString>

/** Default Constructor. Does nothing. */
Entity::Entity()
{
}

/**
  * Constructor with instantiation of ID.
  * @param id Unique ID of entity.
  */
Entity::Entity(int id)
{
    setID(id);
}

/**** Setters ****/

/** Sets the entity's ID. */
void Entity::setID(int id)
{
    uniqueID = id;
}

/** Sets the email addresss of the entity. */
void Entity::setEmailAddress(QString email)
{
    emailAddress = email;
}

/** Sets the phone number of the entity. */
void Entity::setPhoneNumber(QString number)
{
    emailAddress = number;
}

/**
  * @name setLocation
  * Collectively sets all location info (reduces unneccessary getters/setters)
  * @param address The address of the entity.
  * @param c The city name.
  * @param s The state name.
  * @param zip Zip code of the address.
  */
void Entity::setLocation(QString address, QString c, QString s, QString zip)
{
    streetAddress = address;
    city = c;
    state = s;
    zipCode = zip;
}

/**** Getters ****/

/** @return Entity's ID. */
int Entity::getID()
{
    return uniqueID;
}

/** @return Email address. */
QString Entity::getEmailAddress()
{
    return emailAddress;
}

/** @return Phone number. */
QString Entity::getPhoneNumber()
{
    return phoneNumber;
}

/** @return Street address. */
QString Entity::getStreetAddress()
{
    return streetAddress;
}

/** @return City. */
QString Entity::getCity()
{
    return city;
}

/** @return State. */
QString Entity::getState()
{
    return state;
}

/** @return Zip code. */
QString Entity::getZipCode()
{
    return zipCode;
}
