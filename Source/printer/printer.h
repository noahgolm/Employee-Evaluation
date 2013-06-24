#ifndef PRINTLIST_H
#define PRINTLIST_H

#include <QList>
#include "employee.h"
#include "employer.h"
#include "evaluationdata.h"

class QPrinter;

class Printer
{
public:
    Printer();

    static void printEmployeeList(QList<Employee> employeeList, bool sorted);
    static void printEmployerList(QList<Employer> employerList);

    static void printEvaluation(EvaluationData evaluation);

private:
};

#endif // PRINTLIST_H
