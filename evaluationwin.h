/**
  * @file EvaluationWin.h
  * @brief Holds all employee evaluation information to create a new one for an employee.
  */

#ifndef EVALUATIONWIN_H
#define EVALUATIONWIN_H

#include <QWidget>


//Forward declarations
class QVBoxLayout;
class QTabWidget;

class EvaluationWin : public QWidget
{
    Q_OBJECT
public:
    explicit EvaluationWin(QWidget *parent = 0); //Default constructor.
private:
    QVBoxLayout *layout; //Holds the layout of the evaluation window.
    QTabWidget  *evaluationTabs; //Contains each new instance of Evaluation as a tabbed widget.
signals:
    
public slots:
    
};

#endif // EVALUATIONWIN_H
