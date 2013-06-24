#ifndef EMPLOYERREPORTBOX_H
#define EMPLOYERREPORTBOX_H

#include "reportbox.h"
#include "employer.h"

class EmployerReportBox : public ReportBox
{
public:
    EmployerReportBox(Employer e, int index, int totalNum);
    Employer getEmployer();


private:

    Employer employer;
};

#endif // EMPLOYERREPORTBOX_H
