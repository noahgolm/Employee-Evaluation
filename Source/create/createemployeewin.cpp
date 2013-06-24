/**
 * @file CreateEmployeeWin.cpp
 */

#include "createemployeewin.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "employee.h"
#include "datainterface.h"
#include "labelfieldpair.h"
#include <QMessageBox>
#include <QGroupBox>
#include <QGridLayout>

/**
 * @brief Creates the entry fields and the button to save their data.
 * @param parent The parent widget.
 */
CreateEmployeeWin::CreateEmployeeWin(QWidget *parent) :
    QWidget(parent)
{
    //Set the window title.
    this->setWindowTitle("Create New Employee");

    //Create a list of label/field pairs with all of our necessary fields.
    labelFieldPairs.push_back(new LabelFieldPair("Employee ID: "));
    labelFieldPairs.push_back(new LabelFieldPair("First Name: "));
    labelFieldPairs.push_back(new LabelFieldPair("Last Name: "));
    labelFieldPairs.push_back(new LabelFieldPair("Email Address: "));
    labelFieldPairs.push_back(new LabelFieldPair("Phone Number: "));
    labelFieldPairs.push_back(new LabelFieldPair("Cell Phone Number: "));
    labelFieldPairs.push_back(new LabelFieldPair("Street Address: "));
    labelFieldPairs.push_back(new LabelFieldPair("City: "));
    labelFieldPairs.push_back(new LabelFieldPair("State: "));
    labelFieldPairs.push_back(new LabelFieldPair("Zip code: "));

    //Create our main layout.
    boxLayout = new QVBoxLayout();

    //=====
    // Each of these boxes contains our fields.
    // We use grid layout for multiple ones so our window isn't crowded
    //====

    //ID And name info
    QGroupBox *nameBox = new QGroupBox();
    nameBox->setTitle("Name and ID");
    QGridLayout* nameBoxLayout = new QGridLayout();
    nameBox->setLayout(nameBoxLayout);
    nameBoxLayout->addWidget(labelFieldPairs.at(0), 0, 0);
    nameBoxLayout->addWidget(labelFieldPairs.at(1), 1, 0);
    nameBoxLayout->addWidget(labelFieldPairs.at(2), 1, 1);
    boxLayout->addWidget(nameBox);

    //Contact info
    QGroupBox *contactBox = new QGroupBox();
    contactBox->setTitle("Contact");
    QGridLayout* contactBoxLayout = new QGridLayout();
    contactBox->setLayout(contactBoxLayout);
    contactBoxLayout->addWidget(labelFieldPairs.at(3), 0, 0);
    contactBoxLayout->addWidget(labelFieldPairs.at(4), 1, 0);
    contactBoxLayout->addWidget(labelFieldPairs.at(5), 1, 1);
    boxLayout->addWidget(contactBox);

    //Location
    QGroupBox *locationBox = new QGroupBox();
    locationBox->setTitle("Location");
    QGridLayout* locationBoxLayout = new QGridLayout();
    locationBox->setLayout(locationBoxLayout);
    locationBoxLayout->addWidget(labelFieldPairs.at(6), 0, 0);
    locationBoxLayout->addWidget(labelFieldPairs.at(7), 0, 1);
    locationBoxLayout->addWidget(labelFieldPairs.at(8), 1, 0);
    locationBoxLayout->addWidget(labelFieldPairs.at(9), 1, 1);
    boxLayout->addWidget(locationBox);

    //Create our save button
    saveButton = new QPushButton("Save Data");
    boxLayout->addWidget(saveButton);

    //Connect the button to our save method
    connect(saveButton, SIGNAL(released()), this, SLOT(saveData()));

    //Set all that stuff to our window.
    this->setLayout(boxLayout);
}

/**
 * @brief Saves the employer data to the file.
 */
void CreateEmployeeWin::saveData()
{
    //Create an employee object based on all of the list entries with our known points.
    Employee employee;
    employee.setID(labelFieldPairs.at(0)->getText().toInt());
    employee.setName(labelFieldPairs.at(1)->getText(), labelFieldPairs.at(2)->getText());
    employee.setEmailAddress(labelFieldPairs.at(3)->getText());
    employee.setPhoneNumber(labelFieldPairs.at(4)->getText());
    employee.setCellNumber(labelFieldPairs.at(5)->getText());
    employee.setLocation(labelFieldPairs.at(6)->getText(),
                         labelFieldPairs.at(7)->getText(),
                         labelFieldPairs.at(8)->getText(),
                         labelFieldPairs.at(9)->getText());

    //Check if the ID is already used. If not, save the employee.
    if(DataInterface::hasSameID(employee.getID(), DataInterface::employeeFile))
    {
        QMessageBox::information(this, "Existing ID", "That ID number is already in use.\nPlease enter another number.");
    } else
    {
        DataInterface::writeEmployee(&employee);
        QMessageBox::information(this, "Employee Created", "The new employee was successfully saved.");
        this->close();
    }

}
