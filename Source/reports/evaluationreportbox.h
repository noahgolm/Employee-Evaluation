#ifndef EVALUATIONREPORTBOX_H
#define EVALUATIONREPORTBOX_H

#include "reportbox.h"
#include "evaluationdata.h"
#include <QMainWindow>

class QAction;

class EvaluationReportBox : public QMainWindow
{
    Q_OBJECT
public:
    EvaluationReportBox(EvaluationData e);
    EvaluationData getEvaluationData();
private:
    EvaluationData evaluationData;
    QString addNewLines(QString comment);

    QAction* printAction;
    int getNumBoxes();

    QTextEdit* display;
    QString displayText;

    void makeBox(QString text);
    QVBoxLayout *boxLayout;

    int numBoxes;
public slots:
    void print();
};

#endif // EVALUATIONREPORTBOX_H
