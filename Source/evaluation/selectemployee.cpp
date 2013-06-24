#include "selectemployee.h"
#include "lists/viewemployees.h"
#include <QPushButton>
#include <QGridLayout>
#include <QTableView>
#include <QLabel>
#include <QItemSelectionModel>
#include <QLineEdit>
#include <QItemSelection>
#include <QMessageBox>
#include "employee.h"
#include <QDebug>
#include "evaluationwin.h"
#include <QVBoxLayout>
#include <QGroupBox>
#include <QScrollBar>
#include "reports/evaluationreportbox.h"
#include <QHBoxLayout>

SelectEmployee::SelectEmployee(bool useIDField)
{
    this->useIDField = useIDField;

    this->setWindowTitle("Select Employee");

    QLabel *selectLabel = new QLabel("Select an employee:");
    selectLabel->setFixedHeight(20);

    QVBoxLayout *viewLayout = new QVBoxLayout();

    employeeView = new ViewEmployees(true, 0);

    //Field to contain evaluation ID. Using a horizontal layout to contain both the label and field in one line.

    QGroupBox   *fieldBox = new QGroupBox();
    QHBoxLayout *fieldLayout = new QHBoxLayout();
    identifierField = new QLineEdit();
    identifierField->setFixedHeight(20);

    QLabel *idFieldLabel = new QLabel("Enter a valid evaluation identifier:");
    idFieldLabel->setFixedHeight(20);

    //Button to create the new evaluation once an employee is selected.
    doneButton = new QPushButton("Select");
    doneButton->setFixedHeight(30);

    //Add the lineedit and the label to the evaluation ID field and set the object's layout.
    if(useIDField)
    {
        fieldLayout->addWidget(idFieldLabel);
        fieldLayout->addWidget(identifierField);
        fieldBox->setLayout(fieldLayout);
        fieldBox->setFixedHeight(idFieldLabel->height() + 20);
    }

    //Add all of the objects to our window's layout.
    viewLayout->addWidget(selectLabel);
    viewLayout->addWidget(employeeView);
    if(useIDField)
        viewLayout->addWidget(fieldBox);
    viewLayout->addWidget(doneButton);

    setFixedWidth(employeeView->getTotalWidth() + 25);
    setFixedHeight(employeeView->getTotalHeight() + 15
                   + doneButton->height()
                   + selectLabel->height()
                   + idFieldLabel->height()
                   + 50);

    //setFixedSize(employeeView->getTotalWidth(), employeeView->getTotalHeight() + doneButton->height());

    this->setLayout(viewLayout);
    connect(doneButton, SIGNAL(released()), this, SLOT(selectedEmployee()));
}

void SelectEmployee::selectedEmployee()
{
    QModelIndexList indexList = employeeView->listView->selectionModel()->selectedRows();
    if(indexList.size() > 1)
    {
        QMessageBox::information(this, "Too Many Selections", "You may only select one employee to evaluate.");
        return;
    }

    if(indexList.size() == 0)
    {
        QMessageBox::information(this, "No Selection", "You must select an employee to view the evaluation of.");
        return;
    }

    if(this->useIDField && this->identifierField->text().isEmpty())
    {
        QMessageBox::information(this, "No Evaluation ID", "You must enter a valid evaluation number.");
        return;
    }

    Employee e = employeeView->getEmployeeAtCell(indexList.at(0).row());
    if(useIDField)
    {
        EvaluationWin *evalWin = new EvaluationWin(identifierField->text().toInt(), e, 0);
        evalWin->show();
    } else
    {
        if(e.getMostRecentEvaluation().getInfo(EvaluationData::evalNumber) == 0)
        {
            QMessageBox::information(this, "No Evaluations Available","There are no evaluations available for this employee.");
            return;
        }
        EvaluationReportBox* evalReport = new EvaluationReportBox(e.getMostRecentEvaluation());
        ((QMainWindow*)evalReport)->show();
    }


    this->close();
}
