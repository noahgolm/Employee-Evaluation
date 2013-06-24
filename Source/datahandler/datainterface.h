/**
 * @file DataInterface.h
 */

#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <QList>
#include <QMap>
#include <QPair>

//Forward declarations
class Employee;
class Employer;
class EvaluationData;
class QFile;

/**
 * @class DataInterface
 * @brief Static methods to interface the classes here with textual data in the files.
 */
class DataInterface
{
public:
    //This constructor is not used with our static methods.
    DataInterface();

    //Initialization
    static void init();

    //Get item methods for all from a file. These lists are repetitive, but are required for the QList template.
    static QList<Employee>            getEmployees();
    static QList<Employer>            getEmployers();
    static QList<QPair<int, int> >    getPlacements();
    static QList<EvaluationData>      getEvaluations();

    //Get the item from an ID
    static Employee getEmployeeFromID(int id);
    static Employer getEmployerFromID(int id);
    static EvaluationData getEvaluationDataFromID(int id);

    //Get item methods for individual lines using formatted file data.
    static Employee           employeeFromLine(QString dataLine);
    static Employer           employerFromLine(QString dataLine);
    static EvaluationData     evaluationDataFromLine(QString dataLine);
    static QPair<int, int>    placementFromLine(QString dataLine);

    //Write methods to save an object to the appropriate file.
    static void writeEmployee(Employee* employee);
    static void writeEmployer(Employer* employer);
    static void writePlacement(int employeeID, int employerID);
    static void writeEvaluation(EvaluationData* eval);

    //Check whether or not an item with the same ID exists in a file
    static bool hasSameID(int id, QFile* file);

    //Data files
    static QFile *employeeFile;
    static QFile *employerFile;
    static QFile *placementFile;
    static QFile *evaluationsFile;
};

#endif // DATAINTERFACE_H
