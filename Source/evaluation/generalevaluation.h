/**
  * @File GeneralEvaluation.h
  * A general evaluation tab to indicate overall progress, a future evaluation date, and whether or not
  * the employee is to be recommended.
  */

#ifndef GENERALEVALUATION_H
#define GENERALEVALUATION_H

#include "evaluation.h"

//Forward Declarations
class QRadioButton;
class QHBoxLayout;
class QDateEdit;
class QDate;


class GeneralEvaluation : public Evaluation
{
    Q_OBJECT
public:
    GeneralEvaluation(QString name); //Default constructor

    bool doRecommend();
    QDate getNextEvaluationDate();
private:
    QLabel*          progressBarTitle; //Title to label as overall progress v. other tabs
    QLabel*          nextEvaluationDate; //Tells that the next fields will have info about the next evaluation date
    //Label and radio buttons to determine recommendation
    QLabel*          recommendationLabel;
    QRadioButton*    yesRecommend;
    QRadioButton*    noRecommend;
    QHBoxLayout*     radioLayout; //Stores the recommendation radio buttons for the boolean value
    //Fields for next evaluation date
    QLabel*          nextEvaluationLabel;
    QDateEdit*       nextEvaluationPicker;
    QHBoxLayout*     nextEvalLayout;
};

#endif // GENERALEVALUATION_H
