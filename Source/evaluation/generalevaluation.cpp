/**
  * @File GeneralEvaluation.cpp
  */

#include "generalevaluation.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QDateEdit>

/**
  * Constructor for the new general evaluation form.
  * @param name Name of the new evaluation widget.
  */
GeneralEvaluation::GeneralEvaluation(QString name) : Evaluation(name)
{
    this->progressBarTitle = new QLabel("Overall Progress (does not weigh into average score): ");
    this->sliderLayout->insertWidget(0, progressBarTitle);

    this->commentLabel->setText("Overall Comments:");

    //Create the recommendation setup
    this->recommendationLabel = new QLabel("Recommend?");

    this->radioLayout = new QHBoxLayout();

    //Create recommendation buttons
    this->yesRecommend = new QRadioButton("- Yes");
    this->noRecommend = new QRadioButton("- No");

    //Add all of the parts of the recommendation to the layout
    radioLayout->addWidget(recommendationLabel);
    radioLayout->addWidget(yesRecommend);
    radioLayout->addWidget(noRecommend);

    //Create a box to hold this new layout
    QGroupBox* radioBox = new QGroupBox();
    radioBox->setLayout(radioLayout);

    //Add the radio button information to the bottom of the evaluation window
    layout->addWidget(radioBox);

    //Set up layout for the evaluation date
    QGroupBox* nextDateBox = new QGroupBox();
    QHBoxLayout* nextEvalLayout = new QHBoxLayout();

    //Initialize the label and date picker
    nextEvaluationLabel = new QLabel("Next evaluation date: ");
    nextEvaluationPicker = new QDateEdit(QDate::currentDate());

    //Add the widgets to the layout
    nextEvalLayout->addWidget(nextEvaluationLabel);
    nextEvalLayout->addWidget(nextEvaluationPicker);

    //Set the container box's layout to the one containing the widgets
    nextDateBox->setLayout(nextEvalLayout);

    //Add the next evaluation date widgets to the window
    layout->addWidget(nextDateBox);

}

bool GeneralEvaluation::doRecommend()
{
    return yesRecommend->isChecked();
}

QDate GeneralEvaluation::getNextEvaluationDate()
{
    return nextEvaluationPicker->date();
}
