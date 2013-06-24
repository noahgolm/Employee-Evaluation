#include "viewemployees.h"
#include "datainterface.h"
#include "employee.h"
#include "employer.h"
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTableView>
#include <QDebug>
#include <QHeaderView>
#include <QApplication>
#include <QDesktopWidget>
#include "selectemployee.h"
#include <typeinfo>
#include <QMessageBox>
#include <QScrollBar>

ViewEmployees::ViewEmployees(bool showEmployer, QWidget *parent)
    : QWidget(parent)
{

    //Set window title
    this->setWindowTitle("Employee List");

    //Get the employee list to iterate through
    employees = DataInterface::getEmployees();

    //Initialize the view and the model that will hold the data
    listView = new QTableView(this);

    int numColumns = (showEmployer) ? 5 : 3;
    QStandardItemModel *listModel = new QStandardItemModel(employees.size(), numColumns, this);

    //Create the main columns and set the view's model the the one we've created
    listModel->setHorizontalHeaderItem(0, new QStandardItem("Last Name"));
    listModel->setHorizontalHeaderItem(1, new QStandardItem("First Name"));
    listModel->setHorizontalHeaderItem(2, new QStandardItem("ID"));
    if(showEmployer)
    {
        listModel->setHorizontalHeaderItem(3, new QStandardItem("Employer Name"));
        listModel->setHorizontalHeaderItem(4, new QStandardItem("Employer ID"));
    }

    listView->setModel(listModel);

    listView->setSortingEnabled(true);

    listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Iterate through our employee list and add the appropriate data to each column
    for(int i = 0; i < employees.size(); i++)
    {
        Employee e = employees.at(i);
        listModel->setItem(i, 0, new QStandardItem(e.getLastName()));
        listModel->setItem(i, 1, new QStandardItem(e.getFirstName()));
        listModel->setItem(i, 2, new QStandardItem(QString::number(e.getID())));
        if(showEmployer)
        {
            listModel->setItem(i, 3, new QStandardItem(e.getEmployer().getName()));
            listModel->setItem(i, 4, new QStandardItem(QString::number(e.getEmployer().getID())));
        }

    }

    //listView->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    listView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    //Some resizing info
    listView->verticalHeader()->hide();

    listView->resize(getTotalWidth(), getTotalHeight());
    this->setFixedSize(listView->size());

    listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

int ViewEmployees::getTotalHeight()
{
    int totalRowHeight = 0;
    for(int i = 0; i < listView->model()->rowCount(); i++)
        totalRowHeight += listView->rowHeight(i);

    totalRowHeight += listView->horizontalHeader()->height();
    return totalRowHeight;
}

int ViewEmployees::getTotalWidth()
{
    int totalColumnWidth = 0;
    for(int i = 0; i < listView->model()->columnCount(); i++)
        totalColumnWidth += listView->columnWidth(i);

    return totalColumnWidth;
}

Employee ViewEmployees::getEmployeeAtCell(int index)
{
    return employees.at(index);
}
