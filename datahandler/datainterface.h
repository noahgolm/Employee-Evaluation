#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include <QList>
#include <QMap>
#include <QFile>

//Forward declarations
class Employee;
class Employer;
class Evaluation;
class EvaluationData;

class DataInterface
{
public:
    DataInterface();

    //Initialization
    static void init();

    //Get item methods
    static QList<Employee*>       getEmployees();
    static QList<Employer*>       getEmployers();
    static QMap<int, int>         getPlacements();
    static QList<EvaluationData*> getEvaluations();

    //Write methods
    static void writeEmployee(Employee* employee);
    static void writeEmployer(Employer* employer);
    static void writePlacement(int employeeID, int employerID);
    static void writeEvaluation(EvaluationData* eval);
private:
    //Data files
    static QFile *employeeFile;
    static QFile *employerFile;
    static QFile *placementFile;
    static QFile *evaluationsFile;
};

#endif // DATAINTERFACE_H
