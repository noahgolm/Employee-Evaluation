/**
 * @file CreateEmployerWin.h
 */

#ifndef CREATEEMPLOYEEWIN_H
#define CREATEEMPLOYEEWIN_H

#include <QWidget>

class QVBoxLayout;
class QPushButton;
class LabelFieldPair;

/**
 * @class CreateEmployeeWin
 * @brief Creates a new employee entry.
 */
class CreateEmployeeWin : public QWidget
{
    Q_OBJECT
public:
    explicit CreateEmployeeWin(QWidget *parent = 0);
    
private:
    QVBoxLayout* boxLayout;
    QList<LabelFieldPair*> labelFieldPairs; //List of our information fields w/an associated label
    QPushButton *saveButton;

signals:
    
public slots:
    void saveData(); //Saves the data to the file once the button is pressed
    
};

#endif // CREATEEMPLOYEEWIN_H
