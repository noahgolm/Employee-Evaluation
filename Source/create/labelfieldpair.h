/**
 * @file LabelFieldPair.h
 */

#ifndef LABELFIELDPAIR_H
#define LABELFIELDPAIR_H

#include <QGroupBox>

//Forward declarations
class QLabel;
class QLineEdit;
class QHBoxLayout;

/**
 * @class LabelFieldPair
 * @brief A box with a label and a field to enter text into.
 */
class LabelFieldPair : public QGroupBox
{
public:
    LabelFieldPair(QString title);
    QString getText(); //Gets the text from our lineedit
private:
    QHBoxLayout *boxLayout;
    QLabel *titleLabel;
    QLineEdit *textLine;

};

#endif // LABELFIELDPAIR_H
