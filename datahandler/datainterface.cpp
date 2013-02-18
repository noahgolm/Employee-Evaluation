#include "datainterface.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include "employee.h"
#include "employer.h"
#include "evaluationdata.h"

//Data file allocation
QFile* DataInterface::employeeFile;
QFile* DataInterface::employerFile;
QFile* DataInterface::placementFile;
QFile* DataInterface::evaluationsFile;

DataInterface::DataInterface()
{

}

void DataInterface::init()
{
    //Initialize the files...
    employeeFile    = new QFile("EMPLOYEES.txt");
    employerFile    = new QFile("EMPLOYERS.txt");
    placementFile   = new QFile("PLACEMENTS.txt");
    evaluationsFile = new QFile("EVALUATIONS.txt");

    //Open/create the files...
    employeeFile->open(QIODevice::Append | QIODevice::Text);
    employerFile->open(QIODevice::Append | QIODevice::Text);
    evaluationsFile->open(QIODevice::Append | QIODevice::Text);
}

void DataInterface::writeEmployee(Employee* employee)
{
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

void DataInterface::writeEmployer(Employer* employer)
{
    employerFile->open(QIODevice::Append, QIODevice::Text);
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


void DataInterface::writePlacement(int employeeID, int employerID)
{
    //Open the file with appending rights. Then output the data through the stream.
    placementFile->open(QIODevice::Append | QIODevice::Text);
    QTextStream placementWriteStream(placementFile);
    placementWriteStream << employeeID << "," << employerID << endl;
    placementFile->close(); //Close the file when we are done to use other rights.
}

void DataInterface::writeEvaluation(EvaluationData* eval)
{
    evaluationsFile->open(QIODevice::Append | QIODevice::Text);
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
                          << QString(eval->getRecommend() ? "Y" : "N") << endl;
    evaluationsFile->close();
}
