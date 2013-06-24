#include "evaluationreportbox.h"
#include "employee.h"
#include "datainterface.h"
#include <QAction>
#include <QVBoxLayout>
#include <QMenu>
#include <QMenuBar>
#include <QLabel>
#include "printer/printer.h"

const int max_chars_in_row = 60;

EvaluationReportBox::EvaluationReportBox(EvaluationData e)
{
    this->numBoxes = 0;

    printAction = new QAction("&Print...", this);
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(printAction);
    printAction->setShortcut(QKeySequence::Print);
    connect(printAction, SIGNAL(triggered()), this, SLOT(print()));

    QWidget* central = new QWidget();
    this->setCentralWidget(central);
    this->boxLayout = new QVBoxLayout();
    central->setLayout(boxLayout);

    this->evaluationData = e;
    Employee evalEmployee = DataInterface::getEmployeeFromID(e.getInfo(EvaluationData::employeeID));
    this->setWindowTitle(QString("Evaluation View - %1 %2")
                         .arg(evalEmployee.getFirstName())
                         .arg(evalEmployee.getLastName()));

    QString comment; //To insert new lines into the comment before showing in the label

    //ID numbers
    makeBox(QString("Evaluation ID: %1\n"
                    "Employee ID: %2\n"
                    "Employer ID: %3")
            .arg(evaluationData.getInfo(EvaluationData::evalNumber))
            .arg(evaluationData.getInfo(EvaluationData::employeeID))
            .arg(evaluationData.getInfo(EvaluationData::employerID)));

    //Dates
    makeBox(QString("Date of Evaluation: %1\n"
                    "Next Evaluation Date: %2")
            .arg(evaluationData.getDate(EvaluationData::currentDate).toString(Qt::ISODate))
            .arg(evaluationData.getDate(EvaluationData::nextDate).toString(Qt::ISODate)));

    //Work quality
    comment = addNewLines(evaluationData.getComment(EvaluationData::workQuality));
    makeBox(QString("Work Quality Score: %1\n"
                    "Comments:\n%2")
            .arg(evaluationData.getScore(EvaluationData::workQuality))
            .arg(comment));

    //Work Habits
    comment = addNewLines(evaluationData.getComment(EvaluationData::workHabits));
    makeBox(QString("Work Habits Score: %1\n"
                    "Comments:\n%2")
            .arg(evaluationData.getScore(EvaluationData::workHabits))
            .arg(comment));

    //Job Knowledge
    comment = addNewLines(evaluationData.getComment(EvaluationData::jobKnowledge));
    makeBox(QString("Job Knowledge Score: %1\n"
                    "Comments:\n%2")
            .arg(evaluationData.getScore(EvaluationData::jobKnowledge))
            .arg(comment));

    //Behavior
    comment = addNewLines(evaluationData.getComment(EvaluationData::behavior));
    makeBox(QString("Behavior Score: %1\n"
                    "Comments:\n%2")
            .arg(evaluationData.getScore(EvaluationData::behavior))
            .arg(comment));

    //Average Score
    makeBox(QString("Average Score: %1").arg(evaluationData.getAverageScore()));

    //Overall
    comment = addNewLines(evaluationData.getComment(EvaluationData::overall));
    makeBox(QString("Overall Score: %1\n"
                    "Comments:\n%2")
            .arg(evaluationData.getScore(EvaluationData::overall))
            .arg(comment));

    //Recommendation
    QString recommend = evaluationData.getRecommend() ? "Y" : "N";
    makeBox(QString("Recommendation? (Y/N): %1").arg(recommend));

}

QString EvaluationReportBox::addNewLines(QString comment)
{
    int numNewLines = comment.length() / max_chars_in_row;
    if(numNewLines == 0)
        return comment;

    for(int i = 1; i <= numNewLines; i++)
    {
        comment.insert(i * max_chars_in_row, "\n");
    }
    return comment;
}

EvaluationData EvaluationReportBox::getEvaluationData()
{
    return this->evaluationData;
}

void EvaluationReportBox::makeBox(QString text)
{
    QGroupBox* box = new QGroupBox();
    box->setLayout(new QVBoxLayout());
    QLabel* label = new QLabel(text);
    box->layout()->addWidget(label);
    box->setFixedHeight(80);
    this->boxLayout->addWidget(box);
    numBoxes += 1;
}

void EvaluationReportBox::print()
{
    Printer::printEvaluation(this->evaluationData);
}
