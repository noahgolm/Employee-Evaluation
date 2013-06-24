/**
  * @file EvaluationWin.h
  * @brief Holds all employee evaluation information to create a new one for an employee.
  */

#ifndef EVALUATIONWIN_H
#define EVALUATIONWIN_H

#include "evaluation.h"
#include <QList>
#include <QMainWindow>
#include "employee.h"


//Forward declarations
class QVBoxLayout;
class QTabWidget;
class QMenu;
class QAction;

class EvaluationWin : public QMainWindow
{
    Q_OBJECT
public:
    explicit EvaluationWin(int evalNum, Employee evaluated, QWidget *parent); //Default constructor.
    float getAverageScore();
private:
    QVBoxLayout*          layout; //Holds the layout of the evaluation window.
    QTabWidget*           evaluationTabWidget; //Contains each new instance of Evaluation as a tabbed widget.
    QLabel*               averageDisplay;

    QList<Evaluation*>    evaluationTabMap; //Holds all the actual evaluations for later reference

    //File options
    void     setupFileMenu();
    QMenu*   fileMenu;
    QAction* saveAction;

    Employee evaluated;

    int evaluationNum;

signals:
    
public slots:
    void updateAverage();
    //File options
    void saveEvaluation();
    
};

#endif // EVALUATIONWIN_H
