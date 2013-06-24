/**
  * @file Employee.cpp
  */

#include "employee.h"
#include "entity.h"
#include "datainterface.h"

#include "employer.h"

//Just go to our parent constructor
Employee::Employee(int id) : Entity(id)
{
}

//Do nothing...
Employee::Employee() : Entity()
{
}

/** Set the employee name */
void Employee::setName(QString first, QString last)
{
    this->firstName = first;
    this->lastName = last;
}

/** Set employee cell number */
void Employee::setCellNumber(QString cell)
{
    this->cellPhoneNumber = cell;
}

/** Gets the first name */
QString Employee::getFirstName()
{
    return firstName;
}

/** Gets the last name */
QString Employee::getLastName()
{
    return lastName;
}

/** Gets the cell phone number */
QString Employee::getCellNumber()
{
    return cellPhoneNumber;
}

/**
 * @brief Get the overall score from the most recent evaluation
 * @return  most recent overall eval score
 */
int Employee::getOverallScore()
{
    //Loop through our evaluation datas
    foreach(EvaluationData evalData, DataInterface::getEvaluations())
    {
        //If we found a match, return its overall score
        if(evalData.getInfo(EvaluationData::employeeID) == this->getID())
        {
            //Set this for use with operator overloading
            overallScore = evalData.getScore(EvaluationData::overall);
            return overallScore;
        }
    }
    return 0;
}

/**
 * @brief Get the employee's employer
 * @return the Employee's employer
 */
Employer Employee::getEmployer()
{
    QList<QPair<int, int> > pairs = DataInterface::getPlacements();
    Employer retEmployer = Employer(0);
    //Iterate through with the index as the foreach doesn't work with a qpair
    for(int i = 0; i < pairs.size(); i++)
    {
        QPair<int, int> pair = pairs.at(i);
        if(pair.first == this->getID())
            retEmployer = DataInterface::getEmployerFromID(pair.second);
    }
    return retEmployer;
}

EvaluationData Employee::getMostRecentEvaluation()
{
    EvaluationData evalData;
    int mostRecentJulianDay = 0, eJulianDay = 0;
    foreach(EvaluationData e, DataInterface::getEvaluations())
    {
        eJulianDay = e.getDate(EvaluationData::currentDate).toJulianDay();
        if(e.getInfo(EvaluationData::employeeID) == this->getID()
                && eJulianDay > mostRecentJulianDay)
        {
            evalData = e;
            mostRecentJulianDay = eJulianDay;
        }
    }

    return evalData;
}
