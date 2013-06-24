#ifndef SELECTEMPLOYEE_H
#define SELECTEMPLOYEE_H

#include <QWidget>

class ViewEmployees;
class QPushButton;
class QLineEdit;

class SelectEmployee : public QWidget
{
    Q_OBJECT
public:
    SelectEmployee(bool useIDField);
private:
    ViewEmployees*  employeeView;
    QPushButton*    doneButton;
    QLineEdit*      identifierField;
private:
    bool useIDField;
private slots:
    void selectedEmployee();
};

#endif // SELECTEMPLOYEE_H
