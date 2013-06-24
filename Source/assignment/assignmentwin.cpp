/**
 * @file AssignmentWin.cpp
 */

#include "assignmentwin.h"
#include "lists/viewemployees.h"
#include "lists/viewemployers.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QTableView>
#include <QMessageBox>
#include "employee.h"
#include "employer.h"
#include "datainterface.h"
#include <QPair>

/**
 * @brief Constructor to create the assignment window objects.
 */
AssignmentWin::AssignmentWin(QWidget *parent) :
    QWidget(parent)
{

    //Set the window title
    this->setWindowTitle("Assign Employee");

    //Create the new main layout and set minimum spacing
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setSpacing(15);

    //Create our list views
    QGroupBox* viewBox = new QGroupBox();
    QHBoxLayout* viewLayout = new QHBoxLayout();
    employeeView = new ViewEmployees(false, 0);
    employerView = new ViewEmployers();

    //Set our maximum size for formatting
    employeeView->listView->setMaximumHeight(150);
    employerView->listView->setMaximumHeight(150);
    employeeView->setMaximumHeight(150);
    employerView->setMaximumHeight(150);

    //Create our finish button and set its size for formatting
    finishButton = new QPushButton("Pair");
    finishButton->setFixedWidth(200);

    //Add the objects to the window and set the size.
    viewLayout->addWidget(employeeView);
    viewLayout->addWidget(employerView);
    viewBox->setLayout(viewLayout);
    viewBox->setMaximumHeight(200);
    viewBox->setFixedWidth(employeeView->width() + employerView->width() + 30);
    mainLayout->addWidget(viewBox);
    mainLayout->addWidget(finishButton, 0, Qt::AlignCenter);
    this->setLayout(mainLayout);

    //Connect the button to our save method
    connect(finishButton, SIGNAL(released()), this, SLOT(savePairing()));
}
/**
 * @brief Saves the pair data to the placements file.
 */
void AssignmentWin::savePairing()
{
    //Gets data about the selected rows here. This is a list of selected rows from each table view.
    QModelIndexList employeeIndexList = employeeView->listView->selectionModel()->selectedRows();
    QModelIndexList employerIndexList = employerView->listView->selectionModel()->selectedRows();

    //Check if we have more than one selection.
    if(employeeIndexList.size() > 1 || employerIndexList.size() > 1)
    {
        QMessageBox::information(this, "Select Only One", "You may only select one employer and one employee to pair.");
        return;
    }

    //Check if there are no selections.
    if(employeeIndexList.size() == 0 || employerIndexList.size() == 0)
    {
        QMessageBox::information(this, "Must Select One", "You must select both an employer and an employee to pair together.");
        return;
    }

    //Create our entities from the row data and write them to the placement file
    Employee employee = employeeView->getEmployeeAtCell(employeeIndexList.at(0).row());
    Employer employer = employerView->getEmployerAtCell(employerIndexList.at(0).row());
    DataInterface::writePlacement(employee.getID(), employer.getID());

    //End pop-up message and closing
    QMessageBox::information(this, "Saved Placement", "Successfuly saved employee placement.");
    this->close();
}
