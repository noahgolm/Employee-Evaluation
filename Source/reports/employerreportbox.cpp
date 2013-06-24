#include "employerreportbox.h"

EmployerReportBox::EmployerReportBox(Employer e, int index, int totalNum)
    : ReportBox(index, totalNum)
{
    this->employer = e;

    //ID
    makeBox(QString("Employer ID: %1").arg(employer.getID()));

    //Name
    makeBox(QString("Company Name: %1").arg(employer.getName()));

    //Address
    makeBox(QString("Address: %1, %2, %3 %4")
            .arg(employer.getStreetAddress())
            .arg(employer.getCity())
            .arg(employer.getState())
            .arg(employer.getZipCode()));

    //Phone number
    makeBox(QString("Phone Number: %1").arg(employer.getPhoneNumber()));

    //Contact info
    makeBox(QString("Company Email: %1\n"
                    "Contact Person: %2")
            .arg(employer.getEmailAddress())
            .arg(employer.getContact()));
}

Employer EmployerReportBox::getEmployer()
{
    return this->employer;
}
