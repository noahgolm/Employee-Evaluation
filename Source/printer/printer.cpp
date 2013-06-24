#include "printer.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QTextDocument>

Printer::Printer()
{
}

void Printer::printEmployeeList(QList<Employee> employeeList, bool sorted)
{
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");
    if (dialog->exec() != QDialog::Accepted)
        return;

    // If we have sorted items, make it into a single table page to print.
    // Otherwise, print out the employee data on each page separately.
    if(sorted)
    {
        QTextDocument* doc = new QTextDocument();
        QString html("<h1 align=center>MMT Employee List");
        html.append(" (sorted by overall evaluation score)");
        html.append("</h1><hr /><hr />");
        html.append("<table align=\"center\" cell-spacing=\"25\" border=\"5\">"
                    "   <tr>"
                    "       <th>ID</th>"
                    "       <th>First Name</th>"
                    "       <th>Last Name</th>"
                    "       <th>Email Address</th>"
                    "       <th>Phone Number</th>"
                    "       <th>Cell Number</th>"
                    "       <th>Overall Score</th>"
                    "   </tr>");

        foreach(Employee e, employeeList)
        {
            html.append(QString("<tr>"
                                "   <td>%1</td>"
                                "   <td>%2</td>"
                                "   <td>%3</td>"
                                "   <td>%4</td>"
                                "   <td>%5</td>"
                                "   <td>%6</td>"
                                "   <td>%1</td>"
                                )
                        .arg(e.getID())
                        .arg(e.getFirstName())
                        .arg(e.getLastName())
                        .arg(e.getEmailAddress())
                        .arg(e.getPhoneNumber())
                        .arg(e.getCellNumber())
                        .arg(e.getOverallScore())
                            );
            html.append("</tr>");
        }
        html.append("</table>");
        doc->setHtml(html);

        doc->print(&printer);
    } else //Otherwise, print out each one by page
    {
        foreach(Employee e, employeeList)
        {
            QTextDocument* doc = new QTextDocument();
            QString html("<h1 align=center>MMT Employee Sheet</h1><hr /><hr />");
            html.append(QString("<table align=center border=\"5\" width=\"500\">"
                        "   <tr>"
                        "       <th>Employee ID</th>"
                        "       <td>%1</td>"
                        "   </tr>"
                        "   <tr>"
                        "       <th>Name</th>"
                        "       <td>%2 %3</td>"
                        "   </tr>"
                        "   <tr>"
                        "       <th>Email</th>"
                        "       <td>%4</td>"
                        "   </tr>"
                        "   <tr>"
                        "       <th>Phone Number</th>"
                        "       <td>%5</td>"
                        "   </tr>"
                        "   <tr>"
                        "       <th>Cell Phone Number</th>"
                        "       <td>%6</td>"
                        "   </tr>"
                        "   <tr>"
                        "       <th>Address</th>"
                        "       <td>%7, %8, %9 %10</td>"
                        "   </tr>"
                        "</table>")
                        .arg(e.getID())
                        .arg(e.getFirstName())
                        .arg(e.getLastName())
                        .arg(e.getEmailAddress())
                        .arg(e.getPhoneNumber())
                        .arg(e.getCellNumber())
                        .arg(e.getStreetAddress())
                        .arg(e.getCity())
                        .arg(e.getState())
                        .arg(e.getZipCode())
                        );

            doc->setHtml(html);
            doc->print(&printer);
            printer.newPage();
        }
    }

}

void Printer::printEmployerList(QList<Employer> employerList)
{
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");
    if (dialog->exec() != QDialog::Accepted)
        return;

    foreach(Employer e, employerList)
    {
        QTextDocument* doc = new QTextDocument();
        QString html("<h1>MMT Employer Sheet</h1><hr /><hr />");
        html.append(QString("<table align=center border=\"5\" width=\"500\">"
                            "   <tr>"
                            "       <th>Employer ID</th>"
                            "       <td>%1</td>"
                            "   </tr>"
                            "   <tr>"
                            "       <th>Name</th>"
                            "       <td>%2</td>"
                            "   </tr>"
                            "   <tr>"
                            "       <th>Address</th>"
                            "       <td>%3, %4, %5 %6</td>"
                            "   </tr>"
                            "   <tr>"
                            "       <th>Phone Number</th>"
                            "       <td>%7</td>"
                            "   </tr>"
                            "   <tr>"
                            "       <th>Email</th>"
                            "       <td>%8</td>"
                            "   </tr>"
                            "   <tr>"
                            "       <th>Contact</th>"
                            "       <td>%9</td>"
                            "   </tr>"
                            "</table>"
                        )
                    .arg(e.getID())
                    .arg(e.getName())
                    .arg(e.getStreetAddress())
                    .arg(e.getCity())
                    .arg(e.getState())
                    .arg(e.getZipCode())
                    .arg(e.getPhoneNumber())
                    .arg(e.getEmailAddress())
                    .arg(e.getContact()));

        doc->setHtml(html);
        doc->print(&printer);
        printer.newPage();
    }
}

void Printer::printEvaluation(EvaluationData e)
{
    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog *dialog = new QPrintDialog(&printer);
    dialog->setWindowTitle("Print Document");
    if (dialog->exec() != QDialog::Accepted)
        return;

    QTextDocument* doc = new QTextDocument();
    QString html = QString("<h1>MMT Evaluation Sheet</h1><hr /><hr />"
                 "<table align=center border=\"5\" width=\"500\">"
                 "   <tr>"
                 "       <th>Evaluation ID</th>"
                 "       <td>%1</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Employee ID</th>"
                 "       <td>%2</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Employer ID</th>"
                 "       <td>%3</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Evaluation Date</th>"
                 "       <td>%4</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Next Evaluation Date</th>"
                 "       <td>%5</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Work Quality</th>"
                 "       <td>%6</td>"
                 "       <td>%7</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Work Habits</th>"
                 "       <td>%8</td>"
                 "       <td>%9</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Job Knowledge</th>"
                 "       <td>%10</td>"
                 "       <td>%11</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Behavior</th>"
                 "       <td>%12</td>"
                 "       <td>%13</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Overall</th>"
                 "       <td>%14</td>"
                 "       <td>%15</td>"
                 "   </tr>"
                 "   <tr>"
                 "       <th>Recommend?</th>"
                 "       <td>%16</td>"
                 "   </tr>"
                 "</table>"
                )
            .arg(e.getInfo(EvaluationData::evalNumber))
            .arg(e.getInfo(EvaluationData::employeeID))
            .arg(e.getInfo(EvaluationData::employerID))
            .arg(e.getDate(EvaluationData::currentDate).toString(Qt::TextDate))
            .arg(e.getDate(EvaluationData::nextDate).toString(Qt::TextDate))
            .arg(e.getScore(EvaluationData::workQuality))
            .arg(e.getComment(EvaluationData::workQuality))
            .arg(e.getScore(EvaluationData::workHabits))
            .arg(e.getComment(EvaluationData::workHabits))
            .arg(e.getScore(EvaluationData::jobKnowledge))
            .arg(e.getComment(EvaluationData::jobKnowledge))
            .arg(e.getScore(EvaluationData::behavior))
            .arg(e.getComment(EvaluationData::behavior))
            .arg(e.getScore(EvaluationData::overall))
            .arg(e.getComment(EvaluationData::overall))
            .arg(e.getRecommend() ? "Yes" : "No");

    doc->setHtml(html);
    doc->print(&printer);
    printer.newPage();
}
