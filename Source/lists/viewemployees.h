#ifndef VIEWEMPLOYEES_H
#define VIEWEMPLOYEES_H

#include <QWidget>
#include <QMap>

class QTableView;
class Employee;

class ViewEmployees : public QWidget
{
public:
    ViewEmployees(bool showEmployer, QWidget* parent = 0);
    QTableView* listView;

    //Get the correct dimensions of the list view to use instead of its defaults
    int getTotalWidth();
    int getTotalHeight();

    //Get the employee object associated with a given row
    Employee getEmployeeAtCell(int index);
private:
    QList<Employee> employees;
};

#endif // VIEWEMPLOYEES_H
