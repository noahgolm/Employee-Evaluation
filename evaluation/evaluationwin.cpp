/**
  * @file EvaluationWin.cpp
  */

#include "evaluationwin.h"
#include "evaluationdata.h"
#include "generalevaluation.h"
#include <QVBoxLayout>
#include <QTabWidget>
#include <QStatusBar>
#include "evaluation.h"
#include <QLabel>
#include <QTabBar>
#include <typeinfo>
#include <QAction>
#include <QMenuBar>
#include <QMenu>

//Window size constants
const int winX = 465;
const int winY = 500;

//Offset to more clearly show status bar
const int statusBarOffset = 18;

EvaluationWin::EvaluationWin(QWidget *parent) :
    QMainWindow(parent)
{

    //Set the window titles and size.
    setWindowTitle("Employee Evaluation - ");
    setFixedSize(winX, winY);

    setupFileMenu();

    //Instantiate tab view and add new tabs for each category of evaluation.
    evaluationTabWidget = new QTabWidget(this);
    evaluationTabWidget->resize(winX, winY - statusBarOffset - menuBar()->height()); //Resize each tab to fit within the window.
    evaluationTabWidget->move(evaluationTabWidget->x(), menuBar()->height() - 7);

    //Add each new evaluation to the list of them before showing them
    evaluationTabMap.push_back(new GeneralEvaluation("General"));
    evaluationTabMap.push_back(new Evaluation("Quality of Work"));
    evaluationTabMap.push_back(new Evaluation("Work Habits"));
    evaluationTabMap.push_back(new Evaluation("Job Knowledge"));
    evaluationTabMap.push_back(new Evaluation("Behavior/Relations"));

    //String is used twice, one to set title inside the Evaluation object and another time to set the tab title.
    foreach(Evaluation* e, evaluationTabMap)
    {
        evaluationTabWidget->addTab(e, e->getName());

        //Connect all the update signals to the new average updater
        if(typeid(*e) != typeid(GeneralEvaluation)) //Ignore the general evaluation; this doesn't factor into the average
            connect(e, SIGNAL(updatedScaleValue()), this, SLOT(updateAverage()));
    }

    //Get the tab bar directly through it's ID since it is normally protected.
    QTabBar* bar = evaluationTabWidget->findChild<QTabBar *>(QLatin1String("qt_tabwidget_tabbar"));
    //Set the color of the general tab show that it is different than the regular evaluations.
    bar->setTabTextColor(0, Qt::darkRed);

    statusBar()->addPermanentWidget(new QLabel("NAME:   GOLMANT, NOAH"), 10);
    statusBar()->addPermanentWidget(new QLabel("ID: "), 8);

    QString averageStr = QString::number(getAverageScore(), 'f', 2);
    averageDisplay = new QLabel(QString("AVERAGE: %1").arg(averageStr));
    statusBar()->addPermanentWidget(averageDisplay, 3);


}

float EvaluationWin::getAverageScore() {
    float runningTotal = 0;
    foreach(Evaluation* e, evaluationTabMap)
    {
        if(typeid(*e) != typeid(GeneralEvaluation))
            runningTotal += (float)e->getRoundedValue();
    }
    return runningTotal / (evaluationTabMap.size() - 1);
}


void EvaluationWin::updateAverage()
{
    QString averageStr = QString::number(getAverageScore(), 'f', 2);
    averageDisplay->setText(QString("AVERAGE: %1").arg(averageStr));
}

void EvaluationWin::selectNewEmployee()
{

}

void EvaluationWin::saveEvaluation()
{

}

void EvaluationWin::setupFileMenu()
{
    //Set up file menu and actions
    selectNewAction = new QAction("&Select New Employee", this);
    selectNewAction->setShortcut(QKeySequence::New);
    selectNewAction->setStatusTip("Select a new employee for evaluation.");
    connect(selectNewAction, SIGNAL(triggered()), this, SLOT(selectNewEmployee()));

    saveAction = new QAction("&Save Evaluation", this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip("Save the current evaluation to the employee XML file.");
    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveEvaluation()));

    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(selectNewAction);
    fileMenu->addAction(saveAction);
}
