/**
 * @file DataInterface.cpp
 */

#include "datainterface.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "employee.h"
#include "employer.h"
#include "evaluationdata.h"
#include <QStringList>
#include <QMessageBox>
#include <QApplication>
#include <QPair>
#include <typeinfo>

//Data file allocation
QFile* DataInterface::employeeFile;
QFile* DataInterface::employerFile;
QFile* DataInterface::placementFile;
QFile* DataInterface::evaluationsFile;

//This constructor is not used since all of the class is used in a static context.
DataInterface::DataInterface()
{
}

/**
 * @brief Initializes our files.
 */
void DataInterface::init()
{
    //Initialize the files...
    employeeFile    = new QFile("EMPLOYEES.txt");
    employerFile    = new QFile("EMPLOYER.txt");
    placementFile   = new QFile("FIELD PLACEMENTS.txt");
    evaluationsFile = new QFile("EVALUATION RESULTS.txt");

    //If there are no files, create them now.
    //If we can't create them due to restricted rights, alert the user.
    if(!employeeFile->open(QIODevice::ReadWrite | QIODevice::Text)
            || !employerFile->open(QIODevice::ReadWrite | QIODevice::Text)
            || !placementFile->open(QIODevice::ReadWrite | QIODevice::Text)
            || !evaluationsFile->open(QIODevice::ReadWrite | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Creation Error", "Failed to create data files.");
    } else
    {
        employeeFile->close();
        employerFile->close();
        placementFile->close();
        evaluationsFile->close();
    }
}

/**
 * @brief Gets the list of our employees from the file.
 * @return A list containing all employee entries.
 */
QList<Employee> DataInterface::getEmployees()
{
    //Create our list to return and open the file for reading
    QList<Employee> retList;
    if(!employeeFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", employeeFile->errorString());
        return retList; //will be empty
    }

    //While we're still reading the file, add the corresponding employee object to the list.
    while(!employeeFile->atEnd())
    {
        QString line = employeeFile->readLine();
        Employee atLine = employeeFromLine(line);
        retList.push_back(atLine);
    }

    //Close the file and return our now-populated list.
    employeeFile->close();
    return retList;
}

/**
 * @brief Gets the list of our employers from the file.
 * @return A list containing all employer entries.
 */
QList<Employer> DataInterface::getEmployers()
{
    //Create our list to return and open the device for reading.
    QList<Employer> retList;
    if(!employerFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", employerFile->errorString());
        return retList;
    }
    //While there's still stuff to read, add the corresponding employer to our list.
    while(!employerFile->atEnd())
    {
        QString line = employerFile->readLine();
        Employer atLine = employerFromLine(line);
        retList.push_back(atLine);
    }

    //Close the file, return our filled list.
    employerFile->close();
    return retList;
}

/**
 * @brief Gets the list of our placements from the file.
 * @return A list containing all employee-employer placements.
 */
QList<QPair<int, int> > DataInterface::getPlacements()
{
    //Create a list of int pairs that use the employee/employer IDs
    QList<QPair<int, int> > retList;

    //Try to open the file for reading.
    if(!placementFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", placementFile->errorString());
        return retList;
    }

    //While we can read, get the placement from the file and add it to the list
    while(!placementFile->atEnd())
    {
        QString line = placementFile->readLine();
        retList.push_back(placementFromLine(line));
    }

    //Close the file and return the list
    placementFile->close();
    return retList;
}

/**
 * @brief Gets the list of our evaluations from the file.
 * @return A list containing all evaluation entries.
 */
QList<EvaluationData> DataInterface::getEvaluations()
{
    QList<EvaluationData> retList;
    if(!evaluationsFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", evaluationsFile->errorString());
        return retList;
    }

    while(!evaluationsFile->atEnd())
    {
        QString line = evaluationsFile->readLine();
        EvaluationData evalData = evaluationDataFromLine(line);
        retList.push_back(evalData);
    }

    evaluationsFile->close();
    return retList;
}


/**
 * @brief Gets employee from a file line string
 * @param dataLine The line of the file with employee data
 * @return And employee object with the data from our param.
 */
Employee DataInterface::employeeFromLine(QString dataLine)
{
    Employee retEmployee;
    QStringList dataVals = dataLine.split(","); //Split our data by commas
    retEmployee.setID(dataVals.at(0).toInt());

    retEmployee.setName(dataVals.at(1), dataVals.at(2));
    retEmployee.setEmailAddress(dataVals.at(3));
    retEmployee.setPhoneNumber(dataVals.at(4));
    retEmployee.setCellNumber(dataVals.at(5));
    retEmployee.setLocation(dataVals.at(6), dataVals.at(7), dataVals.at(8), dataVals.at(9));
    return retEmployee;
}

/**
 * @brief Gets employer from a file line string
 * @param dataLine The line of the file with employer data
 * @return And employer object with the data from our param.
 */
Employer DataInterface::employerFromLine(QString dataLine)
{
    Employer retEmployer;
    QStringList dataVals = dataLine.split(",");
    retEmployer.setID(dataVals.at(0).toInt());
    retEmployer.setName(dataVals.at(1));
    retEmployer.setLocation(dataVals.at(2), dataVals.at(3), dataVals.at(4), dataVals.at(5));
    retEmployer.setPhoneNumber(dataVals.at(6));
    retEmployer.setEmailAddress(dataVals.at(7));
    retEmployer.setContact(dataVals.at(8));
    return retEmployer;

}

/**
 * @brief Gets evaluation data from a file line string
 * @param dataLine The line of the file with evaluation data
 * @return And evaluationdata object with the data from our param.
 */
EvaluationData DataInterface::evaluationDataFromLine(QString dataLine)
{
    EvaluationData retEval;
    QStringList dataVals = dataLine.split(",");
    retEval.setInfo(EvaluationData::evalNumber, dataVals.at(0).toInt());
    retEval.setInfo(EvaluationData::employeeID, dataVals.at(1).toInt());
    retEval.setInfo(EvaluationData::employerID, dataVals.at(2).toInt());

    retEval.setDate(EvaluationData::currentDate, QDate::fromString(dataVals.at(3), Qt::ISODate));
    retEval.setDate(EvaluationData::nextDate, QDate::fromString(dataVals.at(4), Qt::ISODate));

    retEval.setScore(EvaluationData::workQuality, dataVals.at(5).toInt());
    retEval.setComment(EvaluationData::workQuality, dataVals.at(6));

    retEval.setScore(EvaluationData::workHabits, dataVals.at(7).toInt());
    retEval.setComment(EvaluationData::workHabits, dataVals.at(8));

    retEval.setScore(EvaluationData::jobKnowledge, dataVals.at(9).toInt());
    retEval.setComment(EvaluationData::jobKnowledge, dataVals.at(10));

    retEval.setScore(EvaluationData::behavior, dataVals.at(11).toInt());
    retEval.setComment(EvaluationData::behavior, dataVals.at(12));

    retEval.setAverageScore(dataVals.at(13).toFloat());

    retEval.setScore(EvaluationData::overall, dataVals.at(14).toInt());
    retEval.setComment(EvaluationData::overall, dataVals.at(15));

    retEval.setRecommend(dataVals.at(16) == "Y" ? true : false);

    return retEval;
}

/**
 * @brief Get an employee/employer placement from a data file line.
 * @param dataLine Line from file containing data.
 * @return An int par with the IDs of the employee & employer
 */
QPair<int, int> DataInterface::placementFromLine(QString dataLine)
{
    QStringList dataVals = dataLine.split(",");
    return QPair<int, int>(dataVals.at(0).toInt(), dataVals.at(1).toInt());
}

/**
 * @brief Writes an employee to the data file
 * @param employee Employee object to write
 */
void DataInterface::writeEmployee(Employee* employee)
{
    //Try to open the file
    if(!employeeFile->open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Errors", employeeFile->errorString());
        return;
    }
    employeeFile->open(QIODevice::Append, QIODevice::Text);
    QTextStream employeeWriteStream(employeeFile);

    //Write all of the data as per the FBLA challenge documentation...
    employeeWriteStream << employee->getID() << ","
                        << employee->getFirstName() << ","
                        << employee->getLastName() << ","
                        << employee->getEmailAddress() << ","
                        << employee->getPhoneNumber() << ","
                        << employee->getCellNumber() << ","
                        << employee->getStreetAddress() << ","
                        << employee->getCity() << ","
                        << employee->getState() << ","
                        << employee->getZipCode() << endl;
    employeeFile->close();
}

/**
 * @brief Writes an employer to the data file
 * @param employer Employer object to write
 */
void DataInterface::writeEmployer(Employer* employer)
{
    if(!employerFile->open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", employerFile->errorString());
        return;
    }
    QTextStream employerWriteStream(employerFile);
    //Write all of the formatted data...
    employerWriteStream << employer->getID() << ","
                        << employer->getName() << ","
                        << employer->getStreetAddress() << ","
                        << employer->getCity() << ","
                        << employer->getState() << ","
                        << employer->getZipCode() << ","
                        << employer->getPhoneNumber() << ","
                        << employer->getEmailAddress() << ","
                        << employer->getContact() << endl;
    employerFile->close();
}

/**
 * @brief Writes a employee/employer pair to the file
 * @param employeeID ID of the employee
 * @param employerID ID of the employer
 */
void DataInterface::writePlacement(int employeeID, int employerID)
{
    //Open the file with appending rights. Then output the data through the stream.
    if(!placementFile->open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", placementFile->errorString());
        return;
    }
    //Write the data here
    QTextStream placementWriteStream(placementFile);
    placementWriteStream << employeeID << "," << employerID << endl;
    placementFile->close(); //Close the file when we are done to use other rights.
}

/**
 * @brief Writes an evaluation to the evaluations file.
 * @param eval Evaluation Data to write.
 */
void DataInterface::writeEvaluation(EvaluationData* eval)
{
    //Try to open the file
    if(!evaluationsFile->open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", evaluationsFile->errorString());
        return;
    }

    //Open a data stream and write all that data!
    QTextStream evaluationWriteStream(evaluationsFile);
    evaluationWriteStream << eval->getInfo(EvaluationData::evalNumber) << ","
                          << eval->getInfo(EvaluationData::employeeID) << ","
                          << eval->getInfo(EvaluationData::employerID) << ","
                          << eval->getDate(EvaluationData::currentDate).toString(Qt::ISODate) << ","
                          << eval->getDate(EvaluationData::nextDate).toString(Qt::ISODate) << ","
                          << eval->getScore(EvaluationData::workQuality) << ","
                          << eval->getComment(EvaluationData::workQuality) << ","
                          << eval->getScore(EvaluationData::workHabits) << ","
                          << eval->getComment(EvaluationData::workHabits) << ","
                          << eval->getScore(EvaluationData::jobKnowledge) << ","
                          << eval->getComment(EvaluationData::jobKnowledge) << ","
                          << eval->getScore(EvaluationData::behavior) << ","
                          << eval->getComment(EvaluationData::behavior) << ","
                          << eval->getAverageScore() << ","
                          << eval->getScore(EvaluationData::overall) << ","
                          << eval->getComment(EvaluationData::overall) << ","
                          << QString(eval->getRecommend() ? "Y" : "N") << endl; //Convert our boolean to a string here
    evaluationsFile->close();
}

/**
 * @brief Checks if there's an existing ID in the given file
 * @param id ID to check
 * @param file File to check if there's any other ID in
 * @return True if there are others with the same ID.
 */
bool DataInterface::hasSameID(int id, QFile* file)
{
    //Try to open the file
    if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::information(QApplication::activeWindow(), "File Open Error", file->errorString());
        return false;
    }

    //Search through and check if the first param of each line (always the ID) is the same as the param here
    QTextStream fileStream(file);
    while(!file->atEnd())
    {
        QString line = fileStream.readLine();
        if(line.split(",").at(0).toInt() == id)
        {
            file->close();
            return true;
        }
    }

    //Otherwise, close and return none found
    file->close();
    return false;
}

/**
 * @brief Gets an employee from our list with a given ID
 * @param id ID to use to get the Employee with
 * @return Employee object from the ID
 */
Employee DataInterface::getEmployeeFromID(int id)
{
    //Loop through our employees for one with the matching id
    Employee retEmployee;
    foreach(Employee e, getEmployees())
    {
        if(e.getID() == id)
        {
            retEmployee = e;
            break;
        }

    }
    //Return that employee or NULL if there aren't any
    return retEmployee;
}

/**
 * @brief Gets an employer from our list with a given ID
 * @param id ID to use to get the Employer with
 * @return Employer object from the ID
 */
Employer DataInterface::getEmployerFromID(int id)
{
    Employer retEmployer;
    //Loop through our employers for one with the matching id
    foreach(Employer e, getEmployers())
    {
        if(e.getID() == id)
        {
            retEmployer = e;
            break;
        }

    }
    return retEmployer;
}

/**
 * @brief Gets an evaluation from our list with a given ID
 * @param id ID to use to get the evaluation with
 * @return evaluationdata object from the ID
 */
EvaluationData DataInterface::getEvaluationDataFromID(int id)
{
    //Loop through our evaluations for one with the matching id
    EvaluationData retEval;
    foreach(EvaluationData e, getEvaluations())
    {
        if(e.getInfo(EvaluationData::evalNumber) == id)
        {
            retEval = e;
            break;
        }
    }
    return retEval;
}
