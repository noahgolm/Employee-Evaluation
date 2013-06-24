#ifndef VIEWEMPLOYERS_H
#define VIEWEMPLOYERS_H

#include <QWidget>
#include <QList>
#include "employer.h"

//Forward declarations
class QTableView;

class ViewEmployers : public QWidget
{
public:
    ViewEmployers(QWidget* parent = 0);
    QTableView* listView;

    int getTotalHeight();
    int getTotalWidth();

    Employer getEmployerAtCell(int index);
private:
    QList<Employer> employers;
};

#endif // VIEWEMPLOYERS_H
