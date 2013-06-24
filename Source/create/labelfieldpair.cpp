/**
 * @file LabelFieldPair.cpp
 */

#include "labelfieldpair.h"
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>

/**
 * @brief Creates our objects with the label and text field.
 * @param title The title text of the lable.
 */
LabelFieldPair::LabelFieldPair(QString title)
{
    //Init objects
    boxLayout = new QHBoxLayout();
    titleLabel = new QLabel(title);
    textLine = new QLineEdit();

    //Add the objects
    boxLayout->addWidget(titleLabel);
    boxLayout->addWidget(textLine);

    //Set the size
    titleLabel->setMaximumWidth(this->width() / 2);
    textLine->setMaximumWidth(this->width()/2);

    setLayout(boxLayout);
}

/**
 * @brief Gets the text from our text field
 * @return Text from the line edit.
 */
QString LabelFieldPair::getText()
{
    return textLine->text();
}
