#include "viewemployers.h"
#include "datainterface.h"
#include <QHeaderView>
#include <QTableView>
#include <QStandardItem>
#include <QStandardItemModel>

ViewEmployers::ViewEmployers(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Employer List");

    employers = DataInterface::getEmployers();

    listView = new QTableView(this);
    QStandardItemModel *listModel = new QStandardItemModel(employers.size(), 2, this);

    listModel->setHorizontalHeaderItem(0, new QStandardItem("Employer Name"));
    listModel->setHorizontalHeaderItem(1, new QStandardItem("Employer ID"));

    listView->setModel(listModel);
    listView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    listView->setSortingEnabled(true);

    for(int i = 0; i < employers.size(); i++)
    {
        Employer e = employers.at(i);
        listModel->setItem(i, 0, new QStandardItem(e.getName()));
        listModel->setItem(i, 1, new QStandardItem(QString::number(e.getID())));
    }

    //listView->horizontalHeader()->setResizeMode(QHeaderView::Fixed);
    listView->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    listView->verticalHeader()->hide();
    listView->resize(getTotalWidth(), getTotalHeight());
    this->setFixedSize(listView->size());

    listView->setSelectionBehavior(QAbstractItemView::SelectRows);
    listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

int ViewEmployers::getTotalHeight()
{
    int totalRowHeight = 0;
    for(int i = 0; i < listView->model()->rowCount(); i++)
        totalRowHeight += listView->rowHeight(i);

    totalRowHeight += listView->horizontalHeader()->height();
    return totalRowHeight;
}

int ViewEmployers::getTotalWidth()
{
    int totalColumnWidth = 0;
    for(int i = 0; i < listView->model()->columnCount(); i++)
        totalColumnWidth += listView->columnWidth(i);

    return totalColumnWidth;
}

Employer ViewEmployers::getEmployerAtCell(int index)
{
    return employers.at(index);
}
