/**
  * @File GeneralEvaluation.cpp
  */

#include "generalevaluation.h"
#include <QLabel>

GeneralEvaluation::GeneralEvaluation(QString name) : Evaluation(name)
{
    this->progressBarTitle = new QLabel("Overall Progress: ");

    this->commentLabel->setText("Overal Comments:");

}
