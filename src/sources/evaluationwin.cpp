/**
  * @file EvaluationWin.cpp
  */

#include "evaluationwin.h"
#include "generalevaluation.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QStatusBar>
#include "evaluation.h"
#include <QLabel>
#include <QStatusBar>

//Window size constants
const int winX = 450;
const int winY = 500;

EvaluationWin::EvaluationWin(QWidget *parent) :
    QWidget(parent)
{
    //Set the window titles and size.
    setWindowTitle("Employee Evaluation - ");
    resize(winX, winY);

    //Instantiate tab view and add new tabs for each category of evaluation.
    evaluationTabs = new QTabWidget(this);
    evaluationTabs->resize(winX, winY); //Resize each tab to fit within the window.
    //String is used twice, one to set title inside the Evaluation object and another time to set the tab title.
    evaluationTabs->addTab(new GeneralEvaluation("General"), "General");
    evaluationTabs->addTab(new Evaluation("Quality of Work"), "Quality of Work");
    evaluationTabs->addTab(new Evaluation("Work Habits"), "Work Habits");
}
