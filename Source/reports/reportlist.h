#ifndef EMPLOYERREPORTLIST_H
#define EMPLOYERREPORTLIST_H

#include <QMainWindow>
#include "employer.h"
#include "employee.h"
#include <QStackedWidget>
#include <QScrollBar>

class QMenuBar;
class QAction;

class ReportList : public QMainWindow
{
    Q_OBJECT
public:
    enum BoxType {
        employee,
        employer,
    };

    explicit ReportList(BoxType type, bool sortByScore, QWidget* parent = 0);
    bool compareEmployees(Employee one, Employee two);
private:
    bool sort;
    QStackedWidget* reports;
    QAction* printAction;

    QList<Employee> employeeData;
    QList<Employer> employerData;
public slots:
    void moveToBox(int pos);
    void print();
};

#endif // EMPLOYERREPORTLIST_H
