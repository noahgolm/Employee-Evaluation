#ifndef EMPLOYEEREPORTBOX_H
#define EMPLOYEEREPORTBOX_H

#include "reportbox.h"
#include "employee.h"


class EmployeeReportBox : public ReportBox
{
public:
    EmployeeReportBox(Employee e, int index, int totalNum);
    Employee getEmployee();
private:
    Employee employee;

};

#endif // EMPLOYEEREPORTBOX_H
