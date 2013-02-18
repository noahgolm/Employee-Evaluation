/**
  * @file Evaluation.cpp
  */

#include "evaluation.h"
#include <QSlider>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLabel>
#include <QDebug>
#include "evaluationdata.h"

const static int max_chars = 256; //Maximum character limit for comments

/**
  * Default constructor. Sets the name of the widget.
  * @param name Name of the new evaluation widget.
  */
Evaluation::Evaluation(QString name)
{
    this->name = name;

    //Create map object to relate scale value to a label
    scaleTextMap = new QMap<int, QString>();
    scaleTextMap->insert(1, "Unsatisfactory");
    scaleTextMap->insert(2, "Below Average");
    scaleTextMap->insert(3, "Average");
    scaleTextMap->insert(4, "Above Average");
    scaleTextMap->insert(5, "Outstanding");

    //Initiate and set properties of the slider
    QGroupBox *slideBox = new QGroupBox();
    sliderLayout = new QVBoxLayout();
    slideBox->setLayout(sliderLayout);

    slider = new QSlider();
    slider->setOrientation(Qt::Horizontal);
    slider->setRange(100, 500);
    slider->setSliderPosition(300);

    //Add slider label
    scaleLabel = new QLabel(getFormattedKey(getRoundedValue()));

    //Add scale info to slider/scale layout
    sliderLayout->addWidget(scaleLabel);
    sliderLayout->addWidget(slider);

    //Comment label and box
    commentLabel = new QLabel("Comments:");
    commentBox = new QTextEdit("");

    //Label to update the amount of characters left
    characterCount = new QLabel();
    characterCount->setText(QString("Characters left: %1").arg(max_chars));

    //Connect when text is changed in the box to the character count updater
    connect(commentBox, SIGNAL(textChanged()), this, SLOT(updateCharCount())); //Connects change of text to the update of the label
    connect(slider, SIGNAL(valueChanged(int)), this, SLOT(updateScaleLabel())); //Connects change of thes lider to the slider label
    //Create a layout object to contain all the widgets properly
    layout = new QVBoxLayout;

    //Add widgets to layout
    layout->addWidget(slideBox);
    layout->addWidget(commentLabel);
    layout->addWidget(commentBox);
    layout->addWidget(characterCount);

    //Set the layout of the evaluation widget
    this->setLayout(layout);
}

/**
  * Returns a formatted string to display given the slider value.
  * @param val The value to get a map to
  * @return Formatted string from map of slider values
  */
QString Evaluation::getFormattedKey(int val) {
    return QString("%1 - %2").arg(val).arg(scaleTextMap->value(getRoundedValue()));
}

/**
  * Returns the name of the evaluation tab.
  * @return String with the name of the evaluation.
  */
QString Evaluation::getName() {
    return name;
}

/**
  * Returns the current score in the slider.
  * @return Integer with the slider value in it.
  */
int Evaluation::getScore() {
    return slider->value();
}

/**
  * Updates the scale label with the appropriate formatted text. Called when the slider is changed.
  */
void Evaluation::updateScaleLabel()
{
    //Update text label based on value of scale
    scaleLabel->setText(getFormattedKey(getRoundedValue()));
    emit updatedScaleValue();
}

/**
  * Updates the characters left in the comments box.
  */
void Evaluation::updateCharCount()
{
    //Get amount of chars left based on maximum
    remainingChars = max_chars - commentBox->toPlainText().length();
    characterCount->setText(QString("Characters left: %1").arg(remainingChars));

    /*
     * If there are no remaining characters, set the text to all left of the limit and
     * move the cursor to the end. Setting the text resets this cursor.
     */
    if(remainingChars < 0)
    {
        //Sets the textto the current text minus anything right of the limit
        commentBox->setPlainText(commentBox->toPlainText().left(
            commentBox->toPlainText().length() - abs(remainingChars)));
        commentBox->moveCursor(QTextCursor::End);
    }
}

int Evaluation::getRoundedValue()
{
    return ((slider->value() + 50) / 100);
}
