#include "employeereportbox.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QSet>

EmployeeReportBox::EmployeeReportBox(Employee e, int index, int totalNum)
    : ReportBox(index, totalNum)
{
    this->employee = e;

    //ID Box
    makeBox(QString("Employee ID: %1").arg(employee.getID()));

    //Name box
    makeBox(QString("First Name: %1\n"
                    "Last Name: %2")
            .arg(employee.getFirstName())
            .arg(employee.getLastName()));

    //Email box
    makeBox(QString("Email Address: %1").arg(employee.getEmailAddress()));

    //Phone number
    makeBox(QString("Phone Number: %1\n"
                    "Cell Phone Number: %2")
            .arg(employee.getPhoneNumber())
            .arg(employee.getCellNumber()));

    //Address
    makeBox(QString("Address: %1, %2, %3 %4")
            .arg(employee.getStreetAddress())
            .arg(employee.getCity())
            .arg(employee.getState())
            .arg(employee.getZipCode()));

}

Employee EmployeeReportBox::getEmployee()
{
    return this->employee;
}
