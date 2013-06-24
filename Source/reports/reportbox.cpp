#include "reportbox.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <typeinfo>
#include "evaluationreportbox.h"

ReportBox::ReportBox()
{
    this->boxLayout = new QVBoxLayout();
    this->setLayout(boxLayout);

    this->numBoxes = 0;
}

ReportBox::ReportBox(int index, int totalNum)
{
    this->reportIndex = index;
    this->totalReportSize = totalNum;

    this->setTitle(QString("%1 / %2").arg(reportIndex + 1).arg(totalReportSize));
    this->boxLayout = new QVBoxLayout();
    this->setLayout(boxLayout);

    this->numBoxes = 0;
}

void ReportBox::makeBox(QString text)
{
    QGroupBox* box = new QGroupBox();
    box->setLayout(new QVBoxLayout());
    QLabel* label = new QLabel(text);
    box->layout()->addWidget(label);
    box->setFixedHeight(60);
    this->boxLayout->addWidget(box);
    numBoxes += 1;
}

int ReportBox::getNumBoxes()
{
    return this->numBoxes;
}
